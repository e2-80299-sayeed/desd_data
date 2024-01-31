#include<linux/module.h>

int my_var = 123;

void my_function(void)
{
	printk(KERN_INFO " %s : my_function is called\n", THIS_MODULE->name);
	printk(KERN_INFO " %s : my_var = %d\n", THIS_MODULE->name, my_var);
	my_var++;
}

static __init int desd_init(void)
{
	printk(KERN_INFO " %s : desd_init is called\n", THIS_MODULE->name);
	printk(KERN_INFO " %s : my_var = %d\n", THIS_MODULE->name, my_var);
	printk(KERN_INFO " %s : desd_init is completed\n", THIS_MODULE->name);
	return 0;
}


static __exit void desd_exit(void)
{
	printk(KERN_INFO " %s : desd_exit is called\n", THIS_MODULE->name);
	printk(KERN_INFO " %s : my_var = %d\n", THIS_MODULE->name, my_var);
	printk(KERN_INFO " %s : desd_exit is completed\n", THIS_MODULE->name);
}


module_init(desd_init);
module_exit(desd_exit);

EXPORT_SYMBOL(my_var);
EXPORT_SYMBOL_GPL(my_function);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DESD @ Sunbeam");
MODULE_DESCRIPTION("This is export (Dependancy) module");











