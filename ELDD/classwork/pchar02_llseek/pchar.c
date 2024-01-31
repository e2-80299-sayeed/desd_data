#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>

#define MAX 32

static char buf[MAX];
static dev_t devno;
static struct class *pclass;
static struct cdev pchar_cdev;

static int pchar_open(struct inode *pinode , struct file *pfile);
static int pchar_close(struct inode *pinode , struct file *pfile);
static ssize_t pchar_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos);
static ssize_t pchar_write(struct file *pfile,const char * __user ubuf, size_t ubuf_size, loff_t *fpos);
static loff_t pchar_lseek(struct file *pfile, loff_t offset, int origin);


static struct file_operations pchar_fops = {
    .owner = THIS_MODULE,
    .open = pchar_open,
    .release = pchar_close,
    .read = pchar_read,
    .write = pchar_write,
    .llseek = pchar_lseek
}; 

static __init int pchar_init(void)
{   
    int ret;
    struct device *pdevice;

    printk(KERN_INFO "%s : pchar_init() called.\n",THIS_MODULE->name); 

    ret = alloc_chrdev_region(&devno, 0, 1, "pchar" );
    if(ret < 0)
    {
        printk(KERN_ERR "%s : alloc_chrdev_region() failed.\n",THIS_MODULE->name);
        return ret;
     }
    
    printk(KERN_INFO "%s : alloc_chrdev_region() allocated device number major=%d, minor=%d.\n",THIS_MODULE->name, MAJOR(devno), MINOR(devno));

    pclass =  class_create(THIS_MODULE, "pchar_class");
    if(IS_ERR(pclass))
    {
        printk(KERN_ERR "%s : class_create() failed.\n",THIS_MODULE->name);

        unregister_chrdev_region(devno, 1);

        return -1;    
    }

    printk(KERN_ERR "%s : class_create() created device class.\n",THIS_MODULE->name);    

    pdevice = device_create(pclass, NULL, devno, NULL, "pchar%d", 0); 
    if(IS_ERR(pdevice))
    {
        printk(KERN_ERR "%s : device_create() failed.\n",THIS_MODULE->name);
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    
    printk(KERN_ERR "%s : device_create() created device file.\n",THIS_MODULE->name);
    
    cdev_init(&pchar_cdev, &pchar_fops);
    pchar_cdev.owner = THIS_MODULE;
    ret = cdev_add(&pchar_cdev,devno, 1);
    if(ret < 0)
    {
        printk(KERN_ERR "%s : cdev_add() failed.\n",THIS_MODULE->name);
        device_destroy(pclass, devno);
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);  
        return -1;  
    }   
    printk(KERN_ERR "%s : cdev_add() added char device from kernel db.\n",THIS_MODULE->name);
    
    return 0;

}

static __exit void pchar_exit(void)
{
    printk(KERN_INFO "%s : pchar_exit() called.\n",THIS_MODULE->name);

    cdev_del(&pchar_cdev);
    printk(KERN_INFO "%s : cdev_del() removed char device from kernel db.\n",THIS_MODULE->name);

    device_destroy(pclass, devno);
    printk(KERN_INFO "%s : device_destroy() destroyed device file.\n",THIS_MODULE->name);

    class_destroy(pclass);
    printk(KERN_INFO "%s : class_destroy() destroyed device class.\n",THIS_MODULE->name);

    unregister_chrdev_region(devno, 1);
    printk(KERN_INFO "%s : unregister_chrdev_region() unallocated device number.\n",THIS_MODULE->name);

}


module_init(pchar_init);
module_exit(pchar_exit);

static int pchar_open(struct inode *pinode , struct file *pfile)
{
    printk(KERN_INFO "%s : pchar_open() called.\n",THIS_MODULE->name);
    return 0;
}

static int pchar_close(struct inode *pinode , struct file *pfile)
{
    printk(KERN_INFO "%s : pchar_close() called.\n",THIS_MODULE->name);
    return 0;
}


static ssize_t pchar_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos)
{
    int avail_bytes, bytes_to_read, nbytes;
    printk(KERN_INFO "%s : pchar_read() called.\n",THIS_MODULE->name);

    avail_bytes = MAX - *fpos;

    bytes_to_read = avail_bytes < ubuf_size ? avail_bytes : ubuf_size;

    if(bytes_to_read == 0)
        return 0;

    nbytes =  bytes_to_read - copy_to_user(ubuf, buf + *fpos, bytes_to_read);

    *fpos = *fpos + nbytes;    

    return nbytes;
}

static ssize_t pchar_write(struct file *pfile,const char * __user ubuf, size_t ubuf_size, loff_t *fpos)
{
    int avail_bytes, bytes_to_write, nbytes;
    printk(KERN_INFO "%s : pchar_write() called.\n",THIS_MODULE->name);

    avail_bytes = MAX - *fpos;

    bytes_to_write = avail_bytes < ubuf_size ? avail_bytes : ubuf_size;

    if(bytes_to_write == 0)
    { 
        printk(KERN_ERR "%s : pchar_write() -- device buffer is full.\n",THIS_MODULE->name);   
        return -ENOSPC;   
    }
    nbytes =  bytes_to_write - copy_from_user(buf + *fpos, ubuf, bytes_to_write);

    *fpos = *fpos + nbytes;    

    return nbytes;
}


static loff_t pchar_lseek(struct file *pfile, loff_t offset, int origin)
{

    loff_t newpos = 0;
    printk(KERN_INFO "%s : pchar_lseek() called.\n",THIS_MODULE->name);

    switch (origin)
    {
    case SEEK_SET : 
        newpos = 0 + offset;
        break;
    case SEEK_CUR : 
        newpos = pfile->f_pos + offset;
        break;
    case SEEK_END : 
        newpos = MAX + offset;
        break;
    default:
        printk(KERN_ERR "%s : pchar_lseek() new pos = %lld.\n",THIS_MODULE->name, newpos);
        break;
    }
    pfile->f_pos = newpos;

    return newpos;
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("Pseudo char device driver ");
