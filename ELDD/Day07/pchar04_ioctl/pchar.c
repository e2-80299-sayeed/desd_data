#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kfifo.h>
#include "pchar.h"

// symbolic constants
#define MAX 32

// global variables
// device
static struct kfifo buf;
// device number
static dev_t devno;
static int major=250;
// device class
static struct class *pclass;
// cdev object
static struct cdev pchar_cdev;

// device functions/operations declarations
static int pchar_open(struct inode *pinode, struct file *pfile);
static int pchar_close(struct inode *pinode, struct file *pfile);
static ssize_t pchar_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos);
static ssize_t pchar_write(struct file *pfile, const char * __user ubuf, size_t ubuf_size, loff_t *fpos);
static long pchar_ioctl(struct file *pfile, unsigned int cmd, unsigned long param);

// device operations
static struct file_operations pchar_fops = {
    .owner = THIS_MODULE,
    .open = pchar_open,
    .release = pchar_close,
    .read = pchar_read,
    .write = pchar_write,
    .unlocked_ioctl = pchar_ioctl
};

// kernel module init & exit functions
static __init int pchar_init(void) {
    int ret, minor;
    struct device *pdevice;

    printk(KERN_INFO "%s: pchar_init() called.\n", THIS_MODULE->name);
    // register/allocate device number
    devno = MKDEV(major, 0);
    ret = alloc_chrdev_region(&devno, 0, 1, "pchar");
    if(ret < 0) {
        printk(KERN_ERR "%s: alloc_chrdev_region() failed.\n", THIS_MODULE->name);
        return ret;
    }
    major = MAJOR(devno);
    minor = MINOR(devno);
    printk(KERN_INFO "%s: alloc_chrdev_region() allocated device number major=%d, minor=%d.\n", THIS_MODULE->name, major, minor);

    // create device class and device file
    pclass = class_create(THIS_MODULE, "pchar_class");
    if(IS_ERR(pclass)) {
        printk(KERN_ERR "%s: class_create() failed.\n", THIS_MODULE->name);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO "%s: class_create() created device class.\n", THIS_MODULE->name);

    pdevice = device_create(pclass, NULL, devno, NULL, "pchar%d", 0);
    if(IS_ERR(pdevice)) {
        printk(KERN_ERR "%s: device_create() failed.\n", THIS_MODULE->name);
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO "%s: device_create() created device file.\n", THIS_MODULE->name);

    // initialize cdev and add it into kernel
    cdev_init(&pchar_cdev, &pchar_fops);
    pchar_cdev.owner = THIS_MODULE;
    ret = cdev_add(&pchar_cdev, devno, 1);
    if(ret < 0) {
        printk(KERN_ERR "%s: cdev_add() failed.\n", THIS_MODULE->name);
        device_destroy(pclass, devno);
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);
        return -1;
    }
    printk(KERN_INFO "%s: cdev_add() added char device in kernel db.\n", THIS_MODULE->name);
    
    // allocate device (kfifo) buffer
    ret = kfifo_alloc(&buf, MAX, GFP_KERNEL);
    if(ret < 0) {
        printk(KERN_ERR "%s: kfifo_alloc() failed.\n", THIS_MODULE->name);
        cdev_del(&pchar_cdev);
        device_destroy(pclass, devno);
        class_destroy(pclass);
        unregister_chrdev_region(devno, 1);
        return ret;
    }
    printk(KERN_INFO "%s: kfifo_alloc() allocated kfifo.\n", THIS_MODULE->name);
    return 0;
}

static __exit void pchar_exit(void) {
    printk(KERN_INFO "%s: pchar_exit() called.\n", THIS_MODULE->name);
    // delete device buffer/kfifo
    kfifo_free(&buf);
    // delete cdev from the kernel
    cdev_del(&pchar_cdev);
    printk(KERN_INFO "%s: cdev_del() removed char device from kernel db.\n", THIS_MODULE->name);
    // destroy device class and device file
    device_destroy(pclass, devno);
    printk(KERN_INFO "%s: device_destroy() destroyed device file.\n", THIS_MODULE->name);
    class_destroy(pclass);
    printk(KERN_INFO "%s: class_destroy() destroyed device class.\n", THIS_MODULE->name);
    // un-register device number
    unregister_chrdev_region(devno, 1);
    printk(KERN_INFO "%s: unregister_chrdev_region() un-allocated device number.\n", THIS_MODULE->name);
}

module_init(pchar_init);
module_exit(pchar_exit);

// device operations implementation
static int pchar_open(struct inode *pinode, struct file *pfile) {
    printk(KERN_INFO "%s: pchar_open() called.\n", THIS_MODULE->name);
    return 0;
}

static int pchar_close(struct inode *pinode, struct file *pfile) {
    printk(KERN_INFO "%s: pchar_close() called.\n", THIS_MODULE->name);
    return 0;
}

static ssize_t pchar_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos) {
    int nbytes, ret;
    printk(KERN_INFO "%s: pchar_read() called.\n", THIS_MODULE->name);
    // read from device buffer/fifo into user buffer
    ret = kfifo_to_user(&buf, ubuf, ubuf_size, &nbytes);
    if(ret < 0) {
        printk(KERN_ERR "%s: kfifo_to_user() failed.\n", THIS_MODULE->name);
        return ret;
    }
    // return the number of bytes successfully read/copied
    return nbytes;
}

static ssize_t pchar_write(struct file *pfile, const char * __user ubuf, size_t ubuf_size, loff_t *fpos) {
    int ret, nbytes;
    printk(KERN_INFO "%s: pchar_write() called.\n", THIS_MODULE->name);
    // check if kfifo is full
    if(kfifo_is_full(&buf)) {
        printk(KERN_ERR "%s: pchar_write() -- device buffer is full.\n", THIS_MODULE->name);
        return -ENOSPC;
    }
    // copy from user buffer to device buffer/kfifo.
    ret = kfifo_from_user(&buf, ubuf, ubuf_size, &nbytes);
    if(ret < 0) {
        printk(KERN_ERR "%s: kfifo_from_user() failed.\n", THIS_MODULE->name);
        return ret;
    }
    // return the number of bytes successfully written/copied
    return nbytes;
}

static long pchar_ioctl(struct file *pfile, unsigned int cmd, unsigned long param) {
    info_t info;
    int ret;
    switch(cmd) {
    case FIFO_CLEAR:
        kfifo_reset(&buf);
        printk(KERN_INFO "%s: pchar_ioctl() -- fifo is cleared.\n", THIS_MODULE->name);
        break;
    case FIFO_GET_INFO:
        info.size = kfifo_size(&buf);
        info.len = kfifo_len(&buf);
        info.avail = kfifo_avail(&buf);
        ret = copy_to_user((void*)param, &info, sizeof(info_t));
        if(ret < 0) {
            printk(KERN_ERR "%s: pchar_ioctl() failed to get info.\n", THIS_MODULE->name);
            return ret;
        }
        printk(KERN_INFO "%s: pchar_ioctl() -- fifo info is collected.\n", THIS_MODULE->name);
        break;
    default:
        printk(KERN_ERR "%s: pchar_ioctl() invaid command.\n", THIS_MODULE->name);
        return -EINVAL;
    }
    return 0;
}

// kernel module info macros
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Pseudo char device driver for DESD Sep-2023 @ Sunbeam Infotech");
MODULE_AUTHOR("Nilesh Ghule <nilesh@sunbeaminfo.com>");
