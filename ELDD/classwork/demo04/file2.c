#include<linux/module.h>

static __exit void sayeed_exit(void)
{
	printk(KERN_INFO "%s : sayeed() : state = %d\n",THIS_MODULE->name, THIS_MODULE->state);
	printk(KERN_INFO "%s : sayeed() : de-initialisation is successful\n",THIS_MODULE->name);


}

module_exit(sayeed_exit);

