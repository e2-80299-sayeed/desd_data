#include<linux/module.h>
#include<linux/moduleparam.h>

int num = 3;

int notify_change(const char *var, const struct kernel_param *kp)
{
	int ret = param_set_int(var,kp);
	
	if (ret == 0)
	{
		printk(KERN_INFO "%s : callback for setting num is called\n",THIS_MODULE->name);
		printk(KERN_INFO "%s : updated/changed value of num = %d\n",THIS_MODULE-name, num);
		
		return 0;
	}
		return -1;
}

struct kernel_param_ops num_ops = {
	.set = &notify_change,
	.get = &param_get_int	
};

module_param_cb(num, &num_ops, &num, 0644);

static __init int modparam_init(void)
{
	printk(KERN_INFO "%s : modparam_init() is called\n", THIS_MODULE->name);
	
	printk(KERN_INFO "%s : num = %d",THIS_MODULE->name, num);

	printk(KERN_INFO "%s : modparam_init() is completed\n", THIS_MODULE->name);

	return 0;
}

static __exit void modparam_exit(void)
{
	printk(KERN_INFO "%s : modparam_exit() is called\n",THIS_MODULE->name);
	
	printk(KERN_INFO "%s : num = %d",THIS_MODULE->name, num);

	printk(KERN_INFO "%s : modparam_exit() is completed\n",THIS_MODULE->name);
}

module_init(modparam_init);
module_exit(modparam_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sayeed");
MODULE_DESCRIPTION("This is my callback modparam module");
