#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/uaccess.h>


#define LED_GPIO 49

static int state;

static ssize_t state_show(struct kobject *kobj, struct kobj_attribute *attr,char *buf)
{

    return sprintf(buf,"led_state = %d\n",state);
}

static ssize_t state_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    int ret ;

    ret = kstrtoint(buf, 10, &state);
    if(ret < 0)
        return ret ;

    if(state == 1)
    {
        gpio_set_value(LED_GPIO, 1);
        printk(KERN_INFO "%s : gpio_write() LED ON.\n",THIS_MODULE->name);
    }
    else if(state == 0)
    {
         gpio_set_value(LED_GPIO, 0);
        printk(KERN_INFO "%s : gpio_write() LED OFF.\n",THIS_MODULE->name);
    }

    return count;
}

static struct kobj_attribute state_attribute =
     __ATTR(state, 0664, state_show, state_store);

static struct attribute *attrs[] = {
    &state_attribute.attr,
    NULL,
};

static struct attribute_group attr_group = {
    .attrs = attrs,
};

static struct kobject *state_kobj;

static __init int led_init(void)
{
    int ret;    

    if(!gpio_is_valid(LED_GPIO))
    {
        printk(KERN_ERR "%s : LED gpio pin %d is invalid.\n",THIS_MODULE->name,LED_GPIO);
        return -1;
    }
    printk(KERN_INFO "%s : LED gpio pin %d is valid.\n",THIS_MODULE->name, LED_GPIO);

    ret = gpio_request(LED_GPIO,"gpio_led");
    if(ret < 0)
    {
        printk(KERN_ERR "%s : LED gpio pin %d is failed gpio request .\n",THIS_MODULE->name,LED_GPIO);
        return -1;
    }
    printk(KERN_INFO "%s : LED gpio pin %d is requested.\n",THIS_MODULE->name, LED_GPIO);

    state = 0;
    ret = gpio_direction_output(LED_GPIO, state);
    if(ret < 0)
    {
        printk(KERN_ERR "%s : LED gpio pin is failed to set direction  as output for pin %d.\n",THIS_MODULE->name, LED_GPIO);
        gpio_free(LED_GPIO);
        return -1;
    }
    printk(KERN_INFO "%s : LED gpio pin is set for output direction.\n",THIS_MODULE->name);


    state_kobj = kobject_create_and_add("kobject_gpio", kernel_kobj);
    if(!state_kobj)
        return -ENOMEM;
    
   ret = sysfs_create_group(state_kobj, &attr_group);
    if(ret)
        kobject_put(state_kobj);
    


    return ret;
}

static __exit void led_exit(void)
{
    gpio_free(LED_GPIO);
    printk(KERN_INFO "%s : LED gpio pin is free.\n",THIS_MODULE->name);
    kobject_put(state_kobj);
}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("This a LDM based gpio module");