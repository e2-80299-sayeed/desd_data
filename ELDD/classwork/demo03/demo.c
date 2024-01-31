#include<linux/module.h>

static __init int sayeed_init(void)
{

	printk(KERN_INFO "%s : sayeed_init() : state = %d\n", THIS_MODULE->name,THIS_MODULE->state);
	printk(KERN_INFO "%s : sayeed_init() : initialisation is successful\n", THIS_MODULE->name);

	return 0;
	
}

static __exit void sayeed_exit(void)
{


	printk(KERN_INFO "%s : sayeed_exit() : state = %d\n", THIS_MODULE->name,THIS_MODULE->state);
	printk(KERN_INFO "%s : sayeed_exit() : de-initialisation is successful\n", THIS_MODULE->name);

}

module_init(sayeed_init);
module_exit(sayeed_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mohammad Sayeed");
MODULE_DESCRIPTION("This is the testing module for ELDD");


