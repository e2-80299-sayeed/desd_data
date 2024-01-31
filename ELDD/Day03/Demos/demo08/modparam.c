#include<linux/module.h>
#include<linux/moduleparam.h>

int num = 3;

int notify_change(const char *var, const struct kernel_param *kp)
{
	int res = param_set_int(var, kp);		// default callback
	if(res == 0)
	{
		printk(KERN_INFO "callback for setting num is called\n");
		printk(KERN_INFO "Upaded/changed value of num = %d\n", num);
		return 0;
	}
	return -1;
}


struct kernel_param_ops num_ops = {
	.set = &notify_change,		// our callback
	.get = &param_get_int		// default callback
};

module_param_cb(num, &num_ops, &num, 0644);

static __init int modparam_init(void)
{
	printk(KERN_INFO " %s : modparam_init() is called\n", THIS_MODULE->name);
	printk(KERN_INFO " %s : num = %d\n", THIS_MODULE->name, num);
	printk(KERN_INFO " %s : modparam_init() is completed\n", THIS_MODULE->name);
	
	return 0;
}

static __exit void modparam_exit(void)
{
	printk(KERN_INFO " %s : modparam_exit() is called\n", THIS_MODULE->name);
	printk(KERN_INFO " %s : num = %d\n", THIS_MODULE->name, num);
	printk(KERN_INFO " %s : modparam_exit() is completed\n", THIS_MODULE->name);

}

module_init(modparam_init);
module_exit(modparam_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Devendra Dhande");
MODULE_DESCRIPTION("This is demo of module parameteres");











