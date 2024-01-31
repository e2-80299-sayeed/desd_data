#include<linux/module.h>

static __init int sayeed_init(void)
{
	printk(KERN_INFO "%s : sayeed_init() : state = %d\n",THIS_MODULE->name, THIS_MODULE->state);
	printk(KERN_INFO "%s : sayeed_init() : initialisation is successful\n",THIS_MODULE->name);

	return 0;

}

module_init(sayeed_init);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sayeed");
MODULE_DESCRIPTION("This is splitfile module");
