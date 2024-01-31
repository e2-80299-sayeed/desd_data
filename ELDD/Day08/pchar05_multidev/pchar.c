#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kfifo.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/cdev.h>

// device buffer size
#define MAX 32

// device count
static int devcnt = 4;
module_param(devcnt, int, 0444);

// device private structure
typedef struct pchar_device {
    struct kfifo buf;
    dev_t devno;
    struct cdev cdev;
}pchar_device_t;

// all devices -- allocated dynamically as per devcnt
static pchar_device_t *devices;
// device numbers
static dev_t devno;
static int major;
// device class
static struct class *pclass;

// device functions/operations declarations
static int pchar_open(struct inode *pinode, struct file *pfile);
static int pchar_close(struct inode *pinode, struct file *pfile);
static ssize_t pchar_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos);
static ssize_t pchar_write(struct file *pfile, const char * __user ubuf, size_t ubuf_size, loff_t *fpos);

// device operations
static struct file_operations pchar_fops = {
    .owner = THIS_MODULE,
    .open = pchar_open,
    .release = pchar_close,
    .read = pchar_read,
    .write = pchar_write
};

static __init int pchar_init(void) {
    int i, ret;
    struct device *pdevice;
    printk(KERN_INFO "%s: pchar_init() called.\n", THIS_MODULE->name);
    devices = (pchar_device_t*)kmalloc(devcnt * sizeof(pchar_device_t), GFP_KERNEL);
    if(devices == NULL) {
        printk(KERN_ERR "%s: kmalloc() failed.\n", THIS_MODULE->name);
        ret = -ENOMEM;
        goto device_alloc_failed;
    }
    printk(KERN_INFO "%s: kmalloc() allocated %d devices.\n", THIS_MODULE->name, devcnt);

    for(i=0; i<devcnt; i++) {
        ret = kfifo_alloc(&devices[i].buf, MAX, GFP_KERNEL);
        if(ret < 0) {
            printk(KERN_ERR "%s: kfifo_alloc() failed for device %d.\n", THIS_MODULE->name, i);
            goto kfifo_alloc_failed;
        }
        printk(KERN_INFO "%s: kfifo_alloc() successful for device %d.\n", THIS_MODULE->name, i);
    }

    // allocate major and minor numbers of devices
    ret = alloc_chrdev_region(&devno, 0, devcnt, "pchar");
    if(ret < 0) {
        printk(KERN_ERR "%s: alloc_chrdev_region() failed.\n", THIS_MODULE->name);
        goto alloc_chrdev_region_failed;
    }
    major = MAJOR(devno);
    printk(KERN_INFO "%s: alloc_chrdev_region() allocated device number major=%d, minor=%d.\n", THIS_MODULE->name, major, MINOR(devno));

    // allocate device class and device files
    pclass = class_create(THIS_MODULE, "pchar_class");
    if(IS_ERR(pclass)) {
        printk(KERN_ERR "%s: class_create() failed.\n", THIS_MODULE->name);
        goto class_create_failed;
    }
    printk(KERN_INFO "%s: pchar device class created by class_create().\n", THIS_MODULE->name);

    for(i=0; i<devcnt; i++) {
        devices[i].devno = MKDEV(major, i);
        pdevice = device_create(pclass, NULL, devices[i].devno, NULL, "pchar%d", i);
        if(IS_ERR(pdevice)) {
            printk(KERN_ERR "%s: device_create() failed for device file pchar%d.\n", THIS_MODULE->name, i);
            goto device_create_failed;
        }
        printk(KERN_INFO "%s: device_create() created device file pchar%d.\n", THIS_MODULE->name, i);
    }

    // create cdev for each device and add into kernel db
    for(i=0; i<devcnt; i++) {
        cdev_init(&devices[i].cdev, &pchar_fops);
        devices[i].cdev.owner = THIS_MODULE;
        ret = cdev_add(&devices[i].cdev, devices[i].devno, 1);
        if(ret < 0) {
            printk(KERN_ERR "%s: cdev_add() failed for device %d.\n", THIS_MODULE->name, i);
            goto cdev_add_failed;
        }
        printk(KERN_INFO "%s: cdev_add() added cdev for device %d.\n", THIS_MODULE->name, i);
    }
    return 0;

cdev_add_failed:
    for(i=i-1; i>=0; i--)
        cdev_del(&devices[i].cdev);
    i=devcnt;
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

static __exit void pchar_exit(void) {
    int i;
    printk(KERN_INFO "%s: pchar_exit() called.\n", THIS_MODULE->name);
    // delete cdevs from kernel db
    for(i=devcnt-1; i>=0; i--)
        cdev_del(&devices[i].cdev);
    printk(KERN_INFO "%s: cdev_del() deleted cdev for devices.\n", THIS_MODULE->name);
    // destroy device files and class
    for(i=devcnt-1; i>=0; i--)
        device_destroy(pclass, devices[i].devno);
    printk(KERN_INFO "%s: device_destroy() destroyed device files.\n", THIS_MODULE->name);

    class_destroy(pclass);
    printk(KERN_INFO "%s: class_destroy() destroyed device class.\n", THIS_MODULE->name);

    // unregister device number
    unregister_chrdev_region(devno, devcnt);
    printk(KERN_INFO "%s: unregister_chrdev_region() released device numbers.\n", THIS_MODULE->name);

    for(i=devcnt-1; i>=0; i--)
        kfifo_free(&devices[i].buf);
    printk(KERN_INFO "%s: kfifo_free() released device fifos of %d devices.\n", THIS_MODULE->name, devcnt);
    
    kfree(devices);
    printk(KERN_INFO "%s: kfree() released memory of %d devices.\n", THIS_MODULE->name, devcnt);
}

module_init(pchar_init);
module_exit(pchar_exit);

// device operations implementation
static int pchar_open(struct inode *pinode, struct file *pfile) {
    printk(KERN_INFO "%s: pchar_open() called.\n", THIS_MODULE->name);
    pfile->private_data = container_of(pinode->i_cdev, pchar_device_t, cdev);
    return 0;
}

static int pchar_close(struct inode *pinode, struct file *pfile) {
    printk(KERN_INFO "%s: pchar_close() called.\n", THIS_MODULE->name);
    return 0;
}

static ssize_t pchar_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos) {
    int nbytes, ret;
    pchar_device_t *pdev = (pchar_device_t*)pfile->private_data;
    printk(KERN_INFO "%s: pchar_read() called for device %d.\n", THIS_MODULE->name, MINOR(pdev->devno));
    // read from device buffer/fifo into user buffer
    ret = kfifo_to_user(&pdev->buf, ubuf, ubuf_size, &nbytes);
    if(ret < 0) {
        printk(KERN_ERR "%s: kfifo_to_user() failed.\n", THIS_MODULE->name);
        return ret;
    }
    // return the number of bytes successfully read/copied
    return nbytes;
}

static ssize_t pchar_write(struct file *pfile, const char * __user ubuf, size_t ubuf_size, loff_t *fpos) {
    int ret, nbytes;
    pchar_device_t *pdev = (pchar_device_t*)pfile->private_data;
    printk(KERN_INFO "%s: pchar_write() called for device %d.\n", THIS_MODULE->name, MINOR(pdev->devno));
    // check if kfifo is full
    if(kfifo_is_full(&pdev->buf)) {
        printk(KERN_ERR "%s: pchar_write() -- device buffer is full.\n", THIS_MODULE->name);
        return -ENOSPC;
    }
    // copy from user buffer to device buffer/kfifo.
    ret = kfifo_from_user(&pdev->buf, ubuf, ubuf_size, &nbytes);
    if(ret < 0) {
        printk(KERN_ERR "%s: kfifo_from_user() failed.\n", THIS_MODULE->name);
        return ret;
    }
    // return the number of bytes successfully written/copied
    return nbytes;
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nilesh Ghule <nilesh@sunbeaminfo.com>");
MODULE_DESCRIPTION("Pseudo char device driver - DESD Sep 2023 @ Sunbeam");
