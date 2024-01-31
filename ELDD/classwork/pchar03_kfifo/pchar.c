#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/kfifo.h>

#define MAX 32

static struct kfifo buf;
static dev_t devno;
static struct class *pclass;
static struct cdev pchar_cdev;

static int pchar_open(struct inode *pinode, struct file *pfile);
static int pchar_close(struct inode *pinode, struct file *pfile);
static ssize_t pchar_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos);
static ssize_t pchar_write(struct file *pfile,const char * __user ubuf, size_t ubuf_size, loff_t *fpos);


static struct file_operations pchar_fops = {
    .owner = THIS_MODULE,
    .open = pchar_open,
    .release = pchar_close,
    .read = pchar_read,
    .write = pchar_write
};

static __init int pchar_init(void)
{
    int ret;
    struct device *pdevice;
    printk(KERN_INFO "%s : pchar_init() is called.\n", THIS_MODULE->name);

    ret =  alloc_chrdev_region(&devno, 0, 1, "pchar");
    if(ret < 0)
    {
        printk(KERN_ERR "%s : alloc_chrdev_region() failed.\n", THIS_MODULE->name);
        return ret;
    }
    printk(KERN_ERR "%s : alloc_chrdev_region() allocated device number major= %d, minor=%d.\n", THIS_MODULE->name, MAJOR(devno), MINOR(devno));

    pclass = class_create(THIS_MODULE, "pchar_class");
    if(IS_ERR(pclass))
    {
        printk(KERN_ERR " %s : class_create() failed.\n",THIS_MODULE->name);
        unregister_chrdev_region(devno, 1);
        
        return -1;
    }
    printk(KERN_INFO " %s : class_create() created device class.\n",THIS_MODULE->name);

    pdevice = device_create(pclass, NULL, devno, NULL, "pchar%d",0);
    if(IS_ERR(pdevice))
    {
        printk(KERN_ERR" %s : device_create() failed.\n",THIS_MODULE->name);    
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO " %s : device_create() created device file.\n",THIS_MODULE->name);

    cdev_init(&pchar_cdev, &pchar_fops);
    pchar_cdev.owner = THIS_MODULE;
    ret = cdev_add (&pchar_cdev, devno, 1);
    if(ret < 0)
    {
        printk(KERN_ERR " %s:  cdev_add() failed.\n",THIS_MODULE->name);
        device_destroy(pclass, devno);
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);
        return -1;
    }

    printk(KERN_INFO " %s : cdev() added char device in kernel db.\n",THIS_MODULE->name);

    ret = kfifo_alloc(&buf, MAX, GFP_KERNEL);
    if(ret < 0)
    {
        printk(KERN_ERR " %s:  kfifo_alloc() failed.\n",THIS_MODULE->name);
        cdev_del(&pchar_cdev);
        device_destroy(pclass,devno);
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);
        
        return ret ;
    }
            printk(KERN_ERR " %s:  kfifo_alloc() allocated kfifo.\n",THIS_MODULE->name);

    return 0;
}   

static __exit void pchar_exit(void)
{
    printk(KERN_INFO "%s : pchar_exit() is called.\n", THIS_MODULE->name);

    kfifo_free(&buf);

    cdev_del(&pchar_cdev);
    printk(KERN_INFO "%s : cdev_del() removed char device from kernel db.\n", THIS_MODULE->name);

    device_destroy(pclass,devno);
    printk(KERN_INFO "%s : device_destroy() destroyed device file.\n", THIS_MODULE->name);


    class_destroy(pclass);
    printk(KERN_INFO "%s : class_destroy() destroyed device class.\n", THIS_MODULE->name);

    unregister_chrdev_region(devno, 1);
    printk(KERN_INFO "%s : unregister_chrdev_region() un-allocated device number.\n", THIS_MODULE->name);
   
}

module_init(pchar_init);
module_exit(pchar_exit);

static int pchar_open(struct inode *pinode, struct file *pfile)
{
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

    ret = kfifo_to_user(&buf, ubuf, ubuf_size, &nbytes); 
    if(ret < 0) 
    {
        printk(KERN_ERR "%s : kfifo_to_user() failed.\n",THIS_MODULE->name);
        return ret;
    } 

    return nbytes;
}   
static ssize_t pchar_write(struct file *pfile,const char * __user ubuf, size_t ubuf_size, loff_t *fpos)
{   
    int nbytes, ret;
    printk(KERN_INFO " %s : pchar_write() called.\n",THIS_MODULE->name);

    if(kfifo_is_full(&buf))
    {
        printk(KERN_ERR " %s : pchar_write() -- device buffer is full.\n",THIS_MODULE->name);
        return -ENOSPC;
    }

    ret = kfifo_from_user(&buf, ubuf, ubuf_size, &nbytes); 
    if(ret < 0) 
    {
    printk(KERN_ERR "%s : kfifo_from_user() failed.\n",THIS_MODULE->name);
        return ret;
    } 

    return nbytes;

}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("This is a device driver based on kfifo");