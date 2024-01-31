#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

// symbolic constants
#define MAX 32

// global variables
// device
static char buf[MAX];
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
static loff_t pchar_lseek(struct file *pfile, loff_t offset, int origin);

// device operations
static struct file_operations pchar_fops = {
    .owner = THIS_MODULE,
    .open = pchar_open,
    .release = pchar_close,
    .read = pchar_read,
    .write = pchar_write,
    .llseek = pchar_lseek
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
    return 0;
}

static __exit void pchar_exit(void) {
    printk(KERN_INFO "%s: pchar_exit() called.\n", THIS_MODULE->name);
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
    int avail_bytes, bytes_to_read, nbytes;
    printk(KERN_INFO "%s: pchar_read() called.\n", THIS_MODULE->name);
    // find number of bytes availble in buffer = device buf size - current fpos
    avail_bytes = MAX - *fpos;
    // find number of bytes to be read from the buffer = MIN(avail bytes, ubuf size)
    bytes_to_read = avail_bytes < ubuf_size ? avail_bytes : ubuf_size;
    // if number of bytes to read is zero, return 0
    if(bytes_to_read == 0)
        return 0;
    // copy device buf into user buf from current pos onwards using copy_to_user() and calc number of bytes successfully copied.
    nbytes = bytes_to_read - copy_to_user(ubuf, buf + *fpos, bytes_to_read);
    // update current file pos with number of read bytes
    *fpos = *fpos + nbytes;
    // return the number of bytes successfully read/copied
    return nbytes;
}

static ssize_t pchar_write(struct file *pfile, const char * __user ubuf, size_t ubuf_size, loff_t *fpos) {
    int avail_bytes, bytes_to_write, nbytes;
    printk(KERN_INFO "%s: pchar_write() called.\n", THIS_MODULE->name);
    // find number of bytes availble in buffer = device buf size - current fpos
    avail_bytes = MAX - *fpos;
    // find number of bytes to be written in the buffer = MIN(avail bytes, ubuf size)
    bytes_to_write = avail_bytes < ubuf_size ? avail_bytes : ubuf_size;
    // if number of bytes to write is zero, return 0 or error ENOSPC
    if(bytes_to_write == 0) {
        printk(KERN_ERR "%s: pchar_write() -- device buffer is full.\n", THIS_MODULE->name);
        return -ENOSPC;
    }
    // copy user buf into device buf from current pos onwards using copy_from_user() and calc number of bytes successfully copied.
    nbytes = bytes_to_write - copy_from_user(buf + *fpos, ubuf, bytes_to_write);
    // update current file pos with number of written bytes
    *fpos = *fpos + nbytes;
    // return the number of bytes successfully written/copied
    return nbytes;
}

static loff_t pchar_lseek(struct file *pfile, loff_t offset, int origin) {
    loff_t newpos = 0;
    printk(KERN_INFO "%s: pchar_lseek() called.\n", THIS_MODULE->name);
    switch(origin) {
    case SEEK_SET:
        newpos = 0 + offset;
        break;
    case SEEK_CUR:
        newpos = pfile->f_pos + offset;
        break;
    case SEEK_END:
        newpos = MAX + offset;
        break;
    default:
        printk(KERN_ERR "%s: pchar_lseek() -- invalid origin.\n", THIS_MODULE->name);
        return -EINVAL;
    }
    if(newpos < 0)
        newpos = 0;
    if(newpos > MAX)
        newpos = MAX;
    printk(KERN_INFO "%s: pchar_lseek() new pos = %lld.\n", THIS_MODULE->name, newpos);
    pfile->f_pos = newpos;
    return newpos;
}

// kernel module info macros

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Pseudo char device driver for DESD Sep-2023 @ Sunbeam Infotech");
MODULE_AUTHOR("Nilesh Ghule <nilesh@sunbeaminfo.com>");
