#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/moduleparam.h>
#include<linux/kfifo.h>
#include<linux/wait.h>

#define MAX 32

static int devcnt = 4;
module_param(devcnt, int, 0444);

typedef struct pchar_device
{
    struct kfifo buf;
    dev_t devno;
    struct cdev cdev;
    wait_queue_head_t wr_wq;
    wait_queue_head_t rd_wq;
}pchar_device_t;

static pchar_device_t *devices;
static dev_t devno;
static struct class *pclass;

static int pchar_open(struct inode *pinode, struct file *pfile);
static int pchar_close(struct inode *pinode, struct file *pfile);
static ssize_t pchar_read(struct file *pfile, char *__user ubuf, size_t ubuf_size, loff_t *fpos);
static ssize_t pchar_write(struct file *pfile, const char *__user ubuf, size_t ubuf_size, loff_t *fpos);


static struct file_operations pchar_fops = {
    .owner = THIS_MODULE,
    .open = pchar_open,
    .release = pchar_close,
    .read = pchar_read,
    .write =  pchar_write
};

static __init int pchar_init(void)
{
    int i, ret;
    struct device *pdevice;
    printk(KERN_INFO "%s : pchar_init() called.\n",THIS_MODULE->name);
    
    devices = (pchar_device_t*)kmalloc(devcnt *sizeof(pchar_device_t),GFP_KERNEL);
    if(devices == NULL)
    {
        printk(KERN_ERR "%s : kmallaoc() failed.\n",THIS_MODULE->name);
        ret = -ENOMEM;
        goto device_alloc_failed;    
    }
    printk(KERN_INFO "%s : kmallaoc() allocated %d devices.\n",THIS_MODULE->name,devcnt);

    for(i = 0; i<devcnt; i++)
    {
        ret = kfifo_alloc(&devices[i].buf, MAX, GFP_KERNEL);
        if(ret < 0)
        {   printk(KERN_ERR "%s : kfifo_alloc() failed.\n",THIS_MODULE->name);
            goto kfifo_alloc_failed;
        }
        
    printk(KERN_INFO "%s : kfifo_alloc() successful for device %d.\n",THIS_MODULE->name,i);
    }   
    

    ret = alloc_chrdev_region(&devno, 0, devcnt, "pchar");
    if(ret < 0)
    {
        printk(KERN_ERR "%s : alloc_chardev_region() failed.\n",THIS_MODULE->name);
        goto alloc_chrdev_region_failed;
    }
    printk(KERN_INFO "%s : alloc_chardev_region() allocated device number major=%d, minor=%d.\n",THIS_MODULE->name,MAJOR(devno), MINOR(devno));

    pclass = class_create(THIS_MODULE, "pchar_class");
    if(IS_ERR(pclass)){
        printk(KERN_ERR "%s: class_create() failed.\n",THIS_MODULE->name);
        goto class_create_failed;
    }
    printk(KERN_INFO "%s : pchar device class created by class_create().\n",THIS_MODULE->name);

    for(i=0; i<devcnt; i++)
    {
        devices[i].devno = MKDEV(MAJOR(devno),i);
        pdevice = device_create(pclass,NULL, devices[i].devno,NULL, "pchar%d",i);
        if(IS_ERR(pdevice))
        {
            printk(KERN_ERR "%s : device_create() failed for device file pchar%d.\n",THIS_MODULE->name,i);
            goto device_create_failed;
        }        
        printk(KERN_INFO "%s : device_create() created device file pchar%d.\n",THIS_MODULE->name,i);
    }

    for(i=0; i< devcnt; i++)
    {
        cdev_init(&devices[i].cdev,&pchar_fops);
        cdev_add(&devices[i].cdev, devno,1);
        if(ret < 0)
        {
            printk(KERN_ERR "%s : cdev_add() failed for device %d.\n",THIS_MODULE->name,i);
            goto cdev_add_failed;
        }
        printk(KERN_INFO "%s : cdev_add() added cdev for device %d.\n",THIS_MODULE->name,i);
        
    }
    for(i=0; i<devcnt; i++)
    {
        init_waitqueue_head(&devices[i].wr_wq);
        init_waitqueue_head(&devices[i].rd_wq);
        printk(KERN_INFO "%s : init_waitqueue_head() initialized writers wait queue for device %d.\n",THIS_MODULE->name,i);
    }

return 0;

cdev_add_failed:
    for(i=i-1; i>=0; i--)
        cdev_del(&devices[i].cdev);
    i = devcnt;

device_create_failed:
    for(i=i-1; i>=0; i--)
        device_destroy(pclass, devices[i].devno);
    class_destroy(pclass);
class_create_failed:
    unregister_chrdev_region(devno, devcnt);

alloc_chrdev_region_failed:
    i=devcnt;
kfifo_alloc_failed:
    for(i=i-1; i>=0; i--)
    kfifo_free(&devices[i].buf);
    kfree(devices);
device_alloc_failed:
return ret;
}

static __exit void pchar_exit(void)
{
    int i;
    printk(KERN_INFO "%s : pchar_exit() called.\n",THIS_MODULE->name);

     for(i=devcnt-1; i>=0; i--)
        cdev_del(&devices[i].cdev);
    printk(KERN_INFO "%s : cdev_del() deleted cdev for devices.\n",THIS_MODULE->name);

    for(i=devcnt-1; i>=0; i--)
        device_destroy(pclass, devices[i].devno);
    printk(KERN_INFO "%s : device_destroy() deleted cdev for devices.\n",THIS_MODULE->name);
    
    class_destroy(pclass);
    printk(KERN_INFO "%s : class_destroy() destroyed device class.\n",THIS_MODULE->name);
    
    unregister_chrdev_region(devno, devcnt);
    printk(KERN_INFO "%s :unregister_chrdev_region() released device numbers.\n",THIS_MODULE->name);

    for(i=devcnt-1; i>=0; i--)
        kfifo_free(&devices[i].buf);
    printk(KERN_INFO "%s :kfree() released device fifos of %d devices.\n",THIS_MODULE->name,i);      

    kfree(devices);
    printk(KERN_INFO " %s : kfree() released memory of %d devices.\n",THIS_MODULE->name, devcnt);
}

module_init(pchar_init);
module_exit(pchar_exit);

static int pchar_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_INFO "%s : pchar_open() called.\n",THIS_MODULE->name);

    pfile->private_data = container_of(pinode->i_cdev, pchar_device_t, cdev);
    return 0;
}
static int pchar_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_INFO "%s : pchar_close() called.\n",THIS_MODULE->name);
    return 0;
}
static ssize_t pchar_read(struct file *pfile, char *__user ubuf, size_t ubuf_size, loff_t *fpos)
{
    int nbytes, ret;
    pchar_device_t *pdev = (pchar_device_t*)pfile->private_data;

    printk(KERN_INFO "%s : pchar_read() called for device %d.\n", THIS_MODULE->name,MINOR(pdev->devno));

    ret = wait_event_interruptible(pdev->rd_wq, !kfifo_is_empty(&pdev->buf));
    if(ret != 0)
    {
        printk(KERN_INFO "%s : pchar_read() wakeup due to signal.\n",THIS_MODULE->name);
        return -EINTR;
    }

    ret = kfifo_to_user(&pdev->buf, ubuf, ubuf_size, &nbytes);
    if(ret < 0)
    {
        printk(KERN_ERR "%s : kfifo_to_user() failed.\n",THIS_MODULE->name);
        return ret;
    }

    if(nbytes > 0)
        wake_up_interruptible(&pdev->wr_wq);

    return nbytes;

}
static ssize_t pchar_write(struct file *pfile, const char *__user ubuf, size_t ubuf_size, loff_t *fpos)
{
    int nbytes, ret;
    pchar_device_t *pdev = (pchar_device_t*)pfile->private_data;

    printk(KERN_INFO "%s : pchar_write() called for device %d.\n", THIS_MODULE->name,MINOR(pdev->devno));

    ret = wait_event_interruptible(pdev->wr_wq, !kfifo_is_full(&pdev->buf));
    if(ret != 0)
    {
        printk(KERN_INFO "%s : pchar_write() wakeup due to signal.\n",THIS_MODULE->name);
        return -EINTR;
        //return -ERESTARTSYS;
    }
    

    ret = kfifo_from_user(&pdev->buf, ubuf, ubuf_size, &nbytes);
    if(ret < 0)
    {
        printk(KERN_ERR "%s : kfifo_from_user() failed.\n",THIS_MODULE->name);
        return ret;
    }

    if(nbytes > 0)
        wake_up_interruptible(&pdev->rd_wq);

    return nbytes;
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("This is a pseduo char device driver");