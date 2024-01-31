#include<linux/module.h>
#include<linux/moduleparam.h>

int num = 3;
char *name = "desd";

module_param(num, int, 0644);
module_param_named(u_name, name, charp, 0644);

static __init int modparam_init(void)
{
	printk(KERN_INFO " %s : modparam_init() is called\n", THIS_MODULE->name);
	printk(KERN_INFO " %s : num = %d\n", THIS_MODULE->name, num);
	for(int i = 1 ; i <= num ; i++)
		printk(KERN_INFO " %s : Hello %s\n", THIS_MODULE->name, name);
	printk(KERN_INFO " %s : modparam_init() is completed\n", THIS_MODULE->name);
	
	return 0;
}

static __exit void modparam_exit(void)
{
	printk(KERN_INFO " %s : modparam_exit() is called\n", THIS_MODULE->name);
	printk(KERN_INFO " %s : num = %d\n", THIS_MODULE->name, num);
	for(int i = 1 ; i <= num ; i++)
		printk(KERN_INFO " %s : Hello %s\n", THIS_MODULE->name, name);
	printk(KERN_INFO " %s : modparam_exit() is completed\n", THIS_MODULE->name);

}

module_init(modparam_init);
module_exit(modparam_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Devendra Dhande");
MODULE_DESCRIPTION("This is demo of module parameteres");











