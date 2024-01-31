#include<linux/module.h>

int my_var = 200;

void my_function(void)
{
	printk(KERN_INFO "%s : my_function is called\n",THIS_MODULE->name);

	printk(KERN_INFO "%s : my_var = %d",THIS_MODULE->name,my_var);
	my_var++;
}


static __init int export_init(void)
{
	printk(KERN_INFO"%s : export_init is called\n",THIS_MODULE->name);
	printk(KERN_INFO "%s : my_var = %d",THIS_MODULE->name,my_var);
	
	printk(KERN_INFO"%s : export_init is completed\n",THIS_MODULE->name);
	
	return 0;
}

static __exit void export_exit(void)
{
	
	printk(KERN_INFO"%s : export_exit is called\n",THIS_MODULE->name);
	printk(KERN_INFO"%s : export_exit is completed\n",THIS_MODULE->name);
}

module_init(export_init);
module_exit(export_exit);

EXPORT_SYMBOL(my_var);
EXPORT_SYMBOL_GPL(my_function);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sayeed");
MODULE_DESCRIPTION("This is my export(Dependency) module");
