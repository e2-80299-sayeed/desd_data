#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/gpio.h>
#include<linux/uaccess.h>
#include<linux/interrupt.h>

#define LED_GPIO 49
#define SWITCH_GPIO 115

static dev_t devno;
static struct class *gpio_class;
static struct cdev bbb_gpio_cdev;
static int led_state;
static int irq;
static work_struct switch_work_que;

static int gpio_open(struct inode *pinode, struct file *pfile);
static int gpio_close(struct inode *pinode, struct file *pfile);
static ssize_t gpio_read(struct file *pfile,char *ubuf, size_t ubuf_size, loff_t *fpos);
static ssize_t gpio_write(struct file *pfile,const char *ubuf, size_t ubuf_size, loff_t *fpos);
static irqreturn_t switch_isr(int irq, void *param);
static void work_handler(void * data);

static struct file_operations bbb_gpio_fops ={
    .owner = THIS_MODULE,
    .open = gpio_open,
    .release = gpio_close,
    .read = gpio_read,
    .write = gpio_write,
};

static __init int gpio_init(void)
{
    int ret;
    struct device *gpio_device;
    printk(KERN_INFO "%s : gpio_init() called\n",THIS_MODULE->name);
    ret = alloc_chrdev_region(&devno, 0, 1, "gpio");
    if(ret < 0)
    {
        printk(KERN_ERR "%s : alloc_chrdev_region() failed to allocate device no.\n",THIS_MODULE->name);
        return ret;
    }
    printk(KERN_INFO "%s : alloc_chrdev_region() device no allocated major no=%d , minor no=%d\n",THIS_MODULE->name, MAJOR(devno), MINOR(devno));
    
    gpio_class = class_create(THIS_MODULE,"bbb_gpio_class");
    if(IS_ERR(gpio_class))
    {
        printk(KERN_ERR "%s : class_create() failed.\n",THIS_MODULE->name);        
        unregister_chrdev_region(devno , 1);
        return -1;
    } 
    printk(KERN_INFO "%s : class_create() created device class.\n",THIS_MODULE->name);

    gpio_device = device_create(gpio_class, NULL, devno, NULL, "bbb_gpio%d",0);
    if(IS_ERR(gpio_device))
    {
        printk(KERN_ERR " %s : device_create() failed.\n",THIS_MODULE->name);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno , 1);
        return -1;
    }
    printk(KERN_INFO " %s : device_create() created device file.\n",THIS_MODULE->name);        

    cdev_init(&bbb_gpio_cdev, &bbb_gpio_fops);
    bbb_gpio_cdev.owner = THIS_MODULE;
    ret = cdev_add(&bbb_gpio_cdev, devno, 1);
    if(ret < 0)
    {
        printk(KERN_ERR "%s : cdev_add() failed.\n",THIS_MODULE->name);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno , 1);
        return -1;
    }

    printk(KERN_INFO " %s : cdev_add() added char device in kernel db.\n",THIS_MODULE->name);

    //LED
    if(!gpio_is_valid(LED_GPIO))
    {
        printk(KERN_ERR "%s : gpio request failed for pin %d.\n",THIS_MODULE->name, LED_GPIO);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno , 1);
        return -1;
    }
    printk(KERN_INFO " %s : LED gpio pin is valid.\n", THIS_MODULE->name);

    ret = gpio_request(LED_GPIO, "gpio_led");
    if(ret < 0)
    {
        printk(KERN_ERR "%s : gpio_request failed for pin %d.\n",THIS_MODULE->name,LED_GPIO);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno , 1);
        return -1;
    }
    printk(KERN_INFO "%s : LED gpio pin is requested.\n",THIS_MODULE->name);

    led_state = 0;
    ret = gpio_direction_output(LED_GPIO, led_state);
    if(ret < 0)
    {
        printk(KERN_ERR "%s : LED gpio failed to set direction as output for pin %d.\n",THIS_MODULE->name,LED_GPIO);
        gpio_free(LED_GPIO);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno , 1);
        return -1;
    }
    
    printk(KERN_INFO "%s : LED gpio pin is set for output direction.\n",THIS_MODULE->name);

    //Switch

    if(!gpio_is_valid(SWITCH_GPIO))
    {
        printk(KERN_ERR "%s : gpio request failed for pin %d.\n",THIS_MODULE->name, SWITCH_GPIO);
        gpio_free(LED_GPIO);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno , 1);
        return -1;
    }
    printk(KERN_INFO " %s : SWITCH gpio pin is valid.\n", THIS_MODULE->name);

    ret = gpio_request(SWITCH_GPIO, "gpio_switch");
    if(ret < 0)
    {
        printk(KERN_ERR "%s : gpio_request failed for pin %d.\n",THIS_MODULE->name,SWITCH_GPIO);
        gpio_free(LED_GPIO);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno , 1);
        return -1;
    }
    printk(KERN_INFO "%s : SWITCH gpio pin is requested.\n",THIS_MODULE->name);

    
    ret = gpio_direction_input(SWITCH_GPIO);
    if(ret < 0)
    {
        printk(KERN_ERR "%s : SWITCH gpio failed to set direction as output for pin %d.\n",THIS_MODULE->name,SWITCH_GPIO);
        gpio_free(SWITCH_GPIO);
        gpio_free(LED_GPIO);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno , 1);
        return -1;
    }
    
    printk(KERN_INFO "%s : SWITCH gpio pin is set for input direction.\n",THIS_MODULE->name);

    //set switch debouncing delay
    ret = gpio_set_debounce(SWITCH_GPIO, 40);
    if(ret < 0)
        printk(KERN_INFO " %s : failed to set gpio pin %d debouncing delay.\n",THIS_MODULE->name,SWITCH_GPIO);
    else 
        printk(KERN_INFO "%s : SWITCH gpio pin is set for input direction.\n",THIS_MODULE->name);

    //irq of switch gpio
    irq = gpio_to_irq(SWITCH_GPIO);
    if(irq < 0)
    {
        printk(KERN_INFO " %s : failed to get irq for gpio %d.\n",THIS_MODULE->name,SWITCH_GPIO);
    }
    else 
    {
        printk(KERN_INFO " %s : switch  gpio pin irq = %d .\n",THIS_MODULE->name,irq);
    }

    //register switch for isr
    if(irq > 0)
    {
        ret = request_irq(irq, switch_isr, IRQF_TRIGGER_RISING, "bbb_switch", NULL);
        if(ret < 0)
        {
            printk(KERN_ERR " %s : failed to register isr for swicth gpio pin %d.\n",THIS_MODULE->name,SWITCH_GPIO);
        }
        else
        {
            printk(KERN_INFO " %s : switch  gpio pin irq = %d is registered.\n",THIS_MODULE->name,irq);
        }
    }

    return 0;
}


static __exit void gpio_exit(void)
{
     printk(KERN_INFO "%s : gpio_exit() called.\n",THIS_MODULE->name);
    
    free_irq(irq, NULL);
    printk(KERN_INFO "%s : switch gpio pin is released.\n",THIS_MODULE->name);

    gpio_free(SWITCH_GPIO);
    printk(KERN_INFO "%s : switch gpio pin is free.\n",THIS_MODULE->name);

    gpio_free(LED_GPIO);
    printk(KERN_INFO "%s : LED gpio pin is free.\n",THIS_MODULE->name);
    
    cdev_del(&bbb_gpio_cdev);
    printk(KERN_INFO "%s : cdev_del removed char device from kernel db.\n",THIS_MODULE->name);

    device_destroy(gpio_class, devno);
    printk(KERN_INFO "%s : device_destroy() destroyed device file.\n",THIS_MODULE->name);

    class_destroy(gpio_class);
    printk(KERN_INFO "%s : class_destroy() destroyed device file.\n",THIS_MODULE->name);

    unregister_chrdev_region(devno , 1);
    printk(KERN_INFO "%s : unregister_chrdev_region() un-allocated device number.\n",THIS_MODULE->name);    

}

module_init(gpio_init);
module_exit(gpio_exit);


static int gpio_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_INFO " %s : gpio_open() called.\n",THIS_MODULE->name);
    return 0;
}
static int gpio_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_INFO " %s : gpio_close() called.\n",THIS_MODULE->name);
    return 0;
}

static ssize_t gpio_read(struct file *pfile,char *ubuf, size_t ubuf_size, loff_t *fpos)
{
    int val , ret;
    printk(KERN_INFO " %s : gpio_read() called.\n",THIS_MODULE->name);
    
    val = gpio_get_value(SWITCH_GPIO);
    if(val == 1)
        ret = 2 - copy_to_user(ubuf, "1\n", 2);
    else if(val == 0)
        ret = 2 - copy_to_user(ubuf, "0\n", 2);
    
    if(ret < 2)
    {
        printk(KERN_ERR " %s : bbb_gpio_read() failed.\n",THIS_MODULE->name);
        return -EFAULT;
    }
    
    return 2;
}

static ssize_t gpio_write(struct file *pfile,const char *ubuf, size_t ubuf_size, loff_t *fpos)
{
    char buf[2] = "";
    int ret;
    printk(KERN_INFO " %s : gpio_write() called.\n",THIS_MODULE->name);

    ret = 1 - copy_from_user(buf, ubuf, 1);
    if(ret != 1)
        printk(KERN_ERR "%s : gpio_write failed.\n", THIS_MODULE->name);
            return -EFAULT;

    if(buf[0] == '1')
    {
        led_state = 1;
        gpio_set_value(LED_GPIO, 1);
        printk(KERN_INFO " %s : gpio_write() LED ON.\n",THIS_MODULE->name);
    }
    else if(buf[0] == '0')
    {
        led_state = 0;
        gpio_set_value(LED_GPIO, 0);
        printk(KERN_INFO " %s : gpio_write() LED OFF.\n",THIS_MODULE->name);
    }

    return ubuf_size;
}

//switch isr implementation
static irqreturn_t switch_isr(int irq, void *param)
{
    led_state = ! led_state;
    gpio_set_value(LED_GPIO, led_state);
    printk(KERN_INFO " %s : switch_isr() called -- LED toggled.\n",THIS_MODULE->name);

    return IRQ_HANDLED;    
}

/*static void work_handler(void * data)
{
    int i;

}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("This is a GPIO device driver for BBB");