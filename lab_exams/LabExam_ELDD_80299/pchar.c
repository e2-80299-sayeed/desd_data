#include<linux/module.h>
#include<linux/list.h>
#include<linux/slab.h>
#include<linux/moduleparam.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/kfifo.h>
#include "pchar.h"



int MAX = 32;
module_param(MAX, int, 0644);

typedef struct  pchar_device{
     struct kfifo buf;
    dev_t devno;
    struct cdev cdev;
} pchar_device_t;

static struct class *pclass;
static pchar_device_t device;
static struct list_head head;
static struct list_head *trav1;
static info_t *info;
struct info_t *trav, *temp ;

static int pchar_open(struct inode *pinode, struct file *pfile);
static int pchar_close(struct inode *pinode, struct file *pfile);
static ssize_t pchar_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos);
static ssize_t pchar_write(struct file *pfile,const char * __user ubuf, size_t ubuf_size, loff_t *fpos);
static long pchar_ioctl(struct file *pfile, unsigned int cmd, unsigned long param);

static struct file_operations pchar_fops = {
    .owner = THIS_MODULE,
    .open = pchar_open,
    .release = pchar_close,
    .read = pchar_read,
    .write = pchar_write,
    .unlocked_ioctl = pchar_ioctl
};

static __init int pchar_init(void)
{
    int ret;
    struct device *pdevice;
    printk(KERN_INFO "%s : pchar_init() is called.\n", THIS_MODULE->name);
    
    

    ret =  alloc_chrdev_region(&device.devno, 0, 1, "pchar");
    if(ret < 0)
    {
        printk(KERN_ERR "%s : alloc_chrdev_region() failed.\n", THIS_MODULE->name);
        return ret;
    }
    printk(KERN_ERR "%s : alloc_chrdev_region() allocated device number major= %d, minor=%d.\n", THIS_MODULE->name, MAJOR(device.devno), MINOR(device.devno));

    pclass = class_create(THIS_MODULE, "pchar_class");
    if(IS_ERR(pclass))
    {
        printk(KERN_ERR " %s : class_create() failed.\n",THIS_MODULE->name);
        unregister_chrdev_region(device.devno, 1);
        
        return -1;
    }
    printk(KERN_INFO " %s : class_create() created device class.\n",THIS_MODULE->name);

    pdevice = device_create(pclass, NULL, device.devno, NULL, "pchar%d",0);
    if(IS_ERR(pdevice))
    {
        printk(KERN_ERR" %s : device_create() failed.\n",THIS_MODULE->name);    
        class_destroy(pclass);
        unregister_chrdev_region(device.devno, 1);
        return -1;
    }
    printk(KERN_INFO " %s : device_create() created device file.\n",THIS_MODULE->name);

    cdev_init(&device.cdev, &pchar_fops);
    device.cdev.owner = THIS_MODULE;
    ret = cdev_add (&device.cdev, device.devno, 1);
    if(ret < 0)
    {
        printk(KERN_ERR " %s:  cdev_add() failed.\n",THIS_MODULE->name);
        device_destroy(pclass, device.devno);
        class_destroy(pclass);
        unregister_chrdev_region(device.devno, 1);
        return -1;
    }

    printk(KERN_INFO " %s : cdev() added char device in kernel db.\n",THIS_MODULE->name);

    INIT_LIST_HEAD(&head);

    ret = kfifo_alloc(&device.buf, MAX, GFP_KERNEL);
    if(ret < 0)
    {
        printk(KERN_ERR " %s:  kfifo_alloc() failed.\n",THIS_MODULE->name);
        cdev_del(&device.cdev);
        device_destroy(pclass,device.devno);
        class_destroy(pclass);
        unregister_chrdev_region(device.devno, 1);
        printk(KERN_INFO "exit before free\n");
    
    return ret ;
    }
    
    printk(KERN_ERR " %s:  kfifo_alloc() allocated kfifo.\n",THIS_MODULE->name);

    return 0;
}   

static __exit void pchar_exit(void)
{
    printk(KERN_INFO "%s : pchar_exit() is called.\n", THIS_MODULE->name);
    
	
	printk(KERN_INFO "exit before free\n");
	
	// list_for_each_entry_safe(trav,temp, &head, list)
	// {
	// 	list_del_init(trav->list);
	// }
	
	printk(KERN_INFO "exit after free\n");


    kfifo_free(&device.buf);

    cdev_del(&device.cdev);
    printk(KERN_INFO "%s : cdev_del() removed char device from kernel db.\n", THIS_MODULE->name);

    device_destroy(pclass,device.devno);
    printk(KERN_INFO "%s : device_destroy() destroyed device file.\n", THIS_MODULE->name);


    class_destroy(pclass);
    printk(KERN_INFO "%s : class_destroy() destroyed device class.\n", THIS_MODULE->name);

    unregister_chrdev_region(device.devno, 1);
    printk(KERN_INFO "%s : unregister_chrdev_region() un-allocated device number.\n", THIS_MODULE->name);
   
}

module_init(pchar_init);
module_exit(pchar_exit);

static int pchar_open(struct inode *pinode, struct file *pfile)
{
   // pfile->private_data = container_of(pinode->i_cdev,pchar_device_t, cdev);
    printk(KERN_INFO " %s : pchar_open() called.\n",THIS_MODULE->name);


    return 0;
}
static int pchar_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_INFO " %s : pchar_close() called.\n",THIS_MODULE->name);

    return 0;
}
static ssize_t pchar_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos)
{
     int nbytes, ret;
    

    printk(KERN_INFO " %s : pchar_read() called.\n",THIS_MODULE->name);   

    ret = kfifo_to_user(&device.buf, ubuf, ubuf_size, &nbytes); 
    if(ret < 0) 
    {
        printk(KERN_ERR "%s : kfifo_to_user() failed.\n",THIS_MODULE->name);
        return ret;
    } 

    strcpy(info->type, "read");
    info->buf_len = kfifo_len(&device.buf);
    strcpy(info->device, "pchar0");
    list_add(&info->list, &head);

    return nbytes;
}   
static ssize_t pchar_write(struct file *pfile,const char * __user ubuf, size_t ubuf_size, loff_t *fpos)
{   
    int nbytes, ret;
    printk(KERN_INFO " %s : pchar_write() called.\n",THIS_MODULE->name);

    if(kfifo_is_full(&device.buf))
    {
        printk(KERN_ERR " %s : pchar_write() -- device buffer is full.\n",THIS_MODULE->name);
        return -ENOSPC;
    }

    ret = kfifo_from_user(&device.buf, ubuf, ubuf_size, &nbytes); 
    if(ret < 0) 
    {
    printk(KERN_ERR "%s : kfifo_from_user() failed.\n",THIS_MODULE->name);
        return ret;
    } 
    
    strcpy(info->type, "write");
    info->buf_len = kfifo_len(&device.buf);
    strcpy(info->device, "pchar0");
    list_add(&info->list, &head);

    return nbytes;

}

static long pchar_ioctl(struct file *pfile, unsigned int cmd, unsigned long param)
{
   
    switch (cmd)
    {
    case FIFO_GET_INFO:

        list_for_each(trav1, &head)
	{
		info = list_entry(trav1,info_t, list);
        printk(KERN_INFO "%s : pchar_ioctl() type = %s, buf_len = %d, device = %s \n", THIS_MODULE->name,info->type, info->buf_len, info->device);
    }
        
        
        printk(KERN_INFO "%s : pchar_ioctl() fifo info is collected.\n", THIS_MODULE->name);
        break;
    
    
    default:
        printk(KERN_ERR "%s : pchar_ioctl() invalid command.\n", THIS_MODULE->name);
        return -EINVAL;

    }
    return 0;
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("This is a device driver based on kfifo and linked list");
