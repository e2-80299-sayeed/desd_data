// exit/cleanup
#include <linux/module.h>
#include "file3.h"

static __exit void desd_exit(void)
{
	my_function();
	printk(KERN_INFO "%s : desd_exit() : de-initialisation is successful\n", THIS_MODULE->name);
}


module_exit(desd_exit);
