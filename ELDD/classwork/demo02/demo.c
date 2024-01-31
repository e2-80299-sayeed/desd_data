#include<linux/module.h>

static __init int sayeed_init(void)
{
	printk(KERN_INFO "%s : sayeed_init : Hi..Neha..!! \n", THIS_MODULE->name);
	return 0;
}

static __exit void sayeed_exit(void)
{
	printk(KERN_INFO "%s : sayeed_init : Bye....Neha..!!\n", THIS_MODULE->name);
}

module_init(sayeed_init);
module_exit(sayeed_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mohammad Sayeed");
MODULE_DESCRIPTION("This is my - module ");
