#include <linux/module.h>
#include "file3.h"

static __init int sayeed_init(void)
{
	my_function();
	my_var = 20;

	printk(KERN_INFO"%s : sayeed_init() : initialisation is successful\n",THIS_MODULE->name);

	return 0;
}

module_init(sayeed_init);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sayeed");
MODULE_DESCRIPTION("This is my tesing module");
