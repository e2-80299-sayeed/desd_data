#include<linux/module.h>
#include<linux/kfifo.h>

struct kfifo my_fifo;

static __init int sayeed_init(void)
{
	int ret;
	char data1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char data2[] = "0123456789"; 

	ret = kfifo_alloc(&my_fifo, 32, GFP_KERNEL);
	if(ret < 0)
	{
		printk(KERN_ERR "%s : kfifo_alloc() is failed \n",THIS_MODULE->name);
		return -1;
	}
	
	printk(KERN_INFO "%s : kfifo size = %d\n",THIS_MODULE->name, kfifo_size(&my_fifo));
	printk(KERN_INFO "%s : kfifo len = %d\n",THIS_MODULE->name, kfifo_len(&my_fifo));
	printk(KERN_INFO "%s : kfifo avail = %d\n",THIS_MODULE->name, kfifo_avail(&my_fifo));

	ret = kfifo_in(&my_fifo, data1, 26);
	printk(KERN_INFO "%s : bytes written into kfifo : %d\n",THIS_MODULE->name, ret);

	printk(KERN_INFO "%s : kfifo size = %d\n", THIS_MODULE->name, kfifo_size(&my_fifo));
	printk(KERN_INFO "%s : kfifo len = %d\n", THIS_MODULE->name, kfifo_len(&my_fifo));
	printk(KERN_INFO "%s : kfifo avail = %d\n", THIS_MODULE->name, kfifo_avail(&my_fifo));
	
	ret = kfifo_in(&my_fifo, data2, 10);
	printk(KERN_INFO "%s : bytes written into kfifo : %d\n", THIS_MODULE->name, ret);

	printk(KERN_INFO "%s : kfifo size = %d\n", THIS_MODULE->name, kfifo_size(&my_fifo));
	printk(KERN_INFO "%s : kfifo len = %d\n", THIS_MODULE->name, kfifo_len(&my_fifo));
	printk(KERN_INFO "%s : kfifo avail = %d\n", THIS_MODULE->name, kfifo_avail(&my_fifo));
	
	printk(KERN_INFO "%s : kfifo is full = %d\n",THIS_MODULE->name, kfifo_is_full(&my_fifo));
	printk(KERN_INFO "%s : kfifo is empty = %d\n", THIS_MODULE->name, kfifo_is_empty(&my_fifo));
	
	return 0;
}


static __exit void sayeed_exit(void)
{
	char data1[32] = "";
	char data2[16]   = "";
	int ret;

	ret = kfifo_out(&my_fifo, data1, 26);
	printk(KERN_INFO "%s : bytes read from kfifo : %d [%s]\n",THIS_MODULE->name, ret, data1);
	
	printk(KERN_INFO "%s : kfifo size = %d\n", THIS_MODULE->name, kfifo_size(&my_fifo));
	printk(KERN_INFO "%s : kfifo len = %d\n", THIS_MODULE->name, kfifo_len(&my_fifo));
	printk(KERN_INFO "%s : kfifo avail = %d\n", THIS_MODULE->name, kfifo_avail(&my_fifo));
	

	ret = kfifo_out(&my_fifo, data2, 10);
	printk(KERN_INFO "%s : bytes read from kfifo : %d [%s]\n",THIS_MODULE->name, ret, data2);
	
	printk(KERN_INFO "%s : kfifo size = %d\n", THIS_MODULE->name, kfifo_size(&my_fifo));
	printk(KERN_INFO "%s : kfifo len = %d\n", THIS_MODULE->name, kfifo_len(&my_fifo));
	printk(KERN_INFO "%s : kfifo avail = %d\n", THIS_MODULE->name, kfifo_avail(&my_fifo));


	printk(KERN_INFO "%s : kfifo is full = %d\n",THIS_MODULE->name, kfifo_is_full(&my_fifo));
	printk(KERN_INFO "%s : kfifo is empty = %d\n", THIS_MODULE->name, kfifo_is_empty(&my_fifo));

}	

module_init(sayeed_init);
module_exit(sayeed_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sayeed");
MODULE_DESCRIPTION("This is my kfifo module");
