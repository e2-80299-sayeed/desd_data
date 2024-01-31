#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
#include<linux/gpio.h>


#define LED_GPIO 49
#define SWITCH_GPIO 115

static int gpio_open(struct inode *pinode, struct file *pfile);
static int gpio_close(struct inode *pinode, struct file *pfile);
static ssize_t gpio_read(struct file *pfile, char * ubuf, size_t ubuf_size, loff_t *fpos);
static ssize_t gpio_write(struct file *pfile,const char * ubuf, size_t ubuf_size, loff_t *fpos);

static dev_t devno;
static struct class *gpio_class;
static struct cdev bbb_gpio_cdev;

static struct file_operations gpio_fops = {
    .owner = THIS_MODULE,
    .open = gpio_open,
    .release = gpio_close,
    .read = gpio_read,
    .write = gpio_write,
};

static __init int gpio_init(void)
{

    int ret;
    struct device *pdevice;

    printk(KERN_INFO " %s : gpio_init() is called.\n",THIS_MODULE->name);

    ret = alloc_chrdev_region(&devno, 0, 1, "gpio");
    if(ret < 0)
    {
        printk(KERN_ERR " %s : alloc_chrdev_region() failed to allocate device no.\n",THIS_MODULE->name);
        return ret;
    }
    printk(KERN_INFO " %s : alloc_chrdev_region()  allocated device no major_no = %d, minor_no = %d .\n",THIS_MODULE->name,MAJOR(devno), MINOR(devno));

    gpio_class = class_create(THIS_MODULE, "gpio_class");
    if(IS_ERR(gpio_class))
    {
        printk(KERN_ERR " %s : class_create() failed.\n",THIS_MODULE->name);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO " %s : class_create() created device class successful.\n",THIS_MODULE->name);

    pdevice = device_create(gpio_class, NULL, devno, NULL, "bbb_gpio%d",0);
    if(IS_ERR(pdevice))
    {
        printk(KERN_ERR " %s : device_create() failed to create device file.\n",THIS_MODULE->name);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO " %s : device_create() created device file.\n",THIS_MODULE->name);

    cdev_init(&bbb_gpio_cdev , &gpio_fops);
    bbb_gpio_cdev.owner = THIS_MODULE;
    ret = cdev_add(&bbb_gpio_cdev, devno, 1);
    if(ret < 0)
    {
        printk(KERN_ERR " %s : cdev_add() failed to add device into kernel db.\n",THIS_MODULE->name);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno, 1);
        return -1;

    }
    printk(KERN_INFO " %s : cdev_add() added device to kernel db.\n",THIS_MODULE->name);

    if(!gpio_is_valid(LED_GPIO))
    {
        printk(KERN_ERR "%s : gpio pin %d is invalid.\n", THIS_MODULE->name,LED_GPIO);
        cdev_del(&bbb_gpio_cdev);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO "%s : gpio pin %d is valid.\n", THIS_MODULE->name,LED_GPIO);

    ret = gpio_request(LED_GPIO, "gpio_led");
    if(ret < 0)
    {
        printk(KERN_ERR "%s : gpio request failed for pin %d.\n", THIS_MODULE->name,LED_GPIO);
        cdev_del(&bbb_gpio_cdev);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO "%s : LED gpio pin %d is requested.\n", THIS_MODULE->name,LED_GPIO);

    ret = gpio_direction_output(LED_GPIO, 0);
    if(ret < 0)
    {
        printk(KERN_ERR "%s :LED gpio pin %d is failed to set output direction .\n", THIS_MODULE->name,LED_GPIO);
        gpio_free(LED_GPIO);
        cdev_del(&bbb_gpio_cdev);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO "%s :LED gpio pin %d is to set output direction .\n", THIS_MODULE->name,LED_GPIO);

    if(!gpio_is_valid(SWITCH_GPIO))
    {
        printk(KERN_ERR "%s : gpio pin %d is invalid.\n", THIS_MODULE->name,SWITCH_GPIO);
        gpio_free(LED_GPIO);
        cdev_del(&bbb_gpio_cdev);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO "%s : gpio pin %d is valid.\n", THIS_MODULE->name,SWITCH_GPIO);

    ret = gpio_request(SWITCH_GPIO, "gpio_switch");
    if(ret < 0)
    {
        printk(KERN_ERR "%s : gpio request failed for pin %d.\n", THIS_MODULE->name,SWITCH_GPIO);
        gpio_free(LED_GPIO);
        cdev_del(&bbb_gpio_cdev);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO "%s : SWITCH gpio pin %d is requested.\n", THIS_MODULE->name,SWITCH_GPIO);

    ret = gpio_direction_input(SWITCH_GPIO);
    if(ret < 0)
    {
        printk(KERN_ERR "%s : SWITCH gpio pin %d is failed to set output direction .\n", THIS_MODULE->name,SWITCH_GPIO);
        gpio_free(SWITCH_GPIO);
        gpio_free(LED_GPIO);
        cdev_del(&bbb_gpio_cdev);
        device_destroy(gpio_class, devno);
        class_destroy(gpio_class);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO "%s :SWITCH gpio pin %d is to set output direction .\n", THIS_MODULE->name,SWITCH_GPIO);
    
    ret = gpio_set_debounce(SWITCH_GPIO,40);
    if(ret < 0)
    {
        printk(KERN_ERR "%s : failed to set gpio pin %d debouncing delay.\n",THIS_MODULE->name,SWITCH_GPIO);
    }
    else
    {
        printk(KERN_ERR "%s : SWITCH gpio pin is set input direction.\n",THIS_MODULE->name);
            
        return 0;

    }
}

static __exit void gpio_exit(void)
{
printk(KERN_INFO "%s : gpio_exit() called.\n",THIS_MODULE->name);

gpio_free(SWITCH_GPIO);
printk(KERN_INFO "%s : SWITCH gpio pin is free.\n",THIS_MODULE->name);

gpio_free(LED_GPIO);
printk(KERN_INFO "%s : LED gpio pin is free.\n",THIS_MODULE->name);

cdev_del(&bbb_gpio_cdev);
printk(KERN_INFO "%s : cdev_del() removed device from kernel db.\n",THIS_MODULE->name);

device_destroy(gpio_class, devno);
printk(KERN_INFO "%s : device_destroy() destroyed device file.\n",THIS_MODULE->name);

class_destroy(gpio_class);
printk(KERN_INFO "%s : destroyed device class.\n",THIS_MODULE->name);

unregister_chrdev_region(devno, 1);
printk(KERN_INFO "%s : unregister_chrdev_region() unallocated device number.\n",THIS_MODULE->name);

}
module_init(gpio_init);
module_exit(gpio_exit);


static int gpio_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_INFO "%s : gpio_open() called.\n",THIS_MODULE->name);
    return 0;
}

static int gpio_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_INFO "%s : gpio_close() called.\n",THIS_MODULE->name);
    return 0;
}

static ssize_t gpio_read(struct file *pfile, char * ubuf, size_t ubuf_size, loff_t *fpos)
{
    printk(KERN_INFO "%s : gpio_read() called.\n",THIS_MODULE->name);
    
    val =  gpio_get_value(SWITCH_GPIO);
    if(val == 1)
        ret = 2 - copy_to_user(ubuf, "1\n", 2);
    else if(val == 0)
            ret = 2 - copy_to_user(ubuf, "0\n", 2);

    if(ret < 2)
    {
        printk(KERN_INFO "%s : gpio_read() failed.\n", THIS_MODULE->name);
        return -EFAULT;
    }
    return 2;
}
static ssize_t gpio_write(struct file *pfile,const char * ubuf, size_t ubuf_size, loff_t *fpos)
{
    char buf[2] = "";
    int ret;
    printk(KERN_INFO "%s : gpio_write() called.\n",THIS_MODULE->name);

    ret = 1 - copy_from_user(buf, ubuf, 1);
    if(ret != 1)
    {
        printk(KERN_ERR "%s : gpio_write() is failed.\n",THIS_MODULE->name);
        return -EFAULT;
    }

    if(buf[0] == '1')
    {
        gpio_set_value(LED_GPIO, 1);
        printk(KERN_INFO "%s : gpio_write() LED ON.\n",THIS_MODULE->name);
    }
    else if(buf[0] == '0')
    {
        gpio_set_value(LED_GPIO, 0);
        printk(KERN_INFO "%s : gpio_write() LED OFF.\n",THIS_MODULE->name);
    }
    return ubuf_size;
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("This is a first GPIO device driver");