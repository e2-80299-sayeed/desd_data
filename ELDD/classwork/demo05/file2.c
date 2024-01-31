#include<linux/module.h>
#include "file3.h"

static __exit void sayeed_exit(void)
{
	my_function();
	printk(KERN_INFO "%s : sayeed_exit() : de-initialisation is successful\n", THIS_MODULE->name);
	
}

module_exit(sayeed_exit);

