#include <linux/module.h>
#include <linux/usb.h>

// function declarations
static int pd_open(struct inode *pinode, struct file *pfile);
static int pd_close(struct inode *pinode, struct file *pfile);
static ssize_t pd_read(struct file *pfile, char __user *ubuf, size_t size, loff_t *pfpos);
static ssize_t pd_write(struct file *pfile, const char __user *ubuf, size_t size, loff_t *pfpos);

// global variables
static struct file_operations pd_fops = {
    .owner = THIS_MODULE,
    .open = pd_open,
    .release = pd_close,
    .read = pd_read,
    .write = pd_write
};

static struct usb_device *device;
static struct usb_class_driver class;

// macros
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define BULK_EP_OUT 0x02
#define BULK_EP_IN 0x81
#define MAX_PKT_SIZE 512

// pd probe function
static int pd_probe(struct usb_interface *intf, const struct usb_device_id *id) {
    int i, ret;
	struct usb_host_interface *iface_desc;
	struct usb_endpoint_descriptor *endpoint;
    // get device information
	iface_desc = intf->cur_altsetting;
	printk(KERN_INFO "%s: pd drive (%04X:%04X) plugged.\n", THIS_MODULE->name, id->idVendor, id->idProduct);
	printk(KERN_INFO "%s: pd drive interface: %d\n", THIS_MODULE->name, iface_desc->desc.bInterfaceNumber);
	printk(KERN_INFO "%s: pd drive bNumEndpoints: %02X\n", THIS_MODULE->name, iface_desc->desc.bNumEndpoints);
	printk(KERN_INFO "%s: pd drive bInterfaceClass: %02X\n", THIS_MODULE->name, iface_desc->desc.bInterfaceClass);

	for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
		endpoint = &iface_desc->endpoint[i].desc;
		printk(KERN_INFO "%s: pd drive Endpoint [%d]->bEndpointAddress: 0x%02X\n", THIS_MODULE->name, i, endpoint->bEndpointAddress);
		printk(KERN_INFO "%s: pd drive Endpoint [%d]->bmAttributes: 0x%02X\n", THIS_MODULE->name, i, endpoint->bmAttributes);
		printk(KERN_INFO "%s: pd drive Endpoint [%d]->wMaxPacketSize: 0x%04X (%d)\n", THIS_MODULE->name, i, endpoint->wMaxPacketSize, endpoint->wMaxPacketSize);
	}
    // get the device object for current interface
    device = interface_to_usbdev(intf);
    printk(KERN_INFO "%s: New USB device connected: %s.\n", THIS_MODULE->name, device->devpath);
    // register usb device
    class.name = "usb/pd%d";
    class.fops = &pd_fops;
    ret = usb_register_dev(intf, &class);
    if(ret < 0) {
        printk(KERN_ERR "%s: usb_register_dev() failed.\n", THIS_MODULE->name);
        return ret;
    }
    printk(KERN_INFO "%s: usb_register_dev() successful.\n", THIS_MODULE->name);
    return 0;
}

// pd disconnect function
static void pd_disconnect(struct usb_interface *intf) {
    printk(KERN_INFO "%s: pd_disconnect() called.\n", THIS_MODULE->name);
    usb_deregister_dev(intf, &class);
}

// usb device id table
static struct usb_device_id id_table[] = {
    { USB_DEVICE(0x0781, 0x557D) },
    { }
};

MODULE_DEVICE_TABLE(usb, id_table);

// usb driver struct
static struct usb_driver pd_driver = {
    .name = "pd_driver",
    .id_table = id_table,
    .probe = pd_probe,
    .disconnect = pd_disconnect
};

static __init int pd_init(void) {
    int ret;
    // register usb driver
    ret = usb_register(&pd_driver);
    if(ret < 0) {
        printk(KERN_ERR "%s: failed to register pd driver.\n", THIS_MODULE->name);
        return ret;
    }
    printk(KERN_INFO "%s: pd driver registered.\n", THIS_MODULE->name);
    return 0;
}

static __exit void pd_exit(void) {
    // unregister usb driver
    usb_deregister(&pd_driver);
    printk(KERN_INFO "%s: pd driver deregistered.\n", THIS_MODULE->name);
}

// device operations
static int pd_open(struct inode *pinode, struct file *pfile) {
    printk(KERN_INFO "%s: pd_open() called.\n", THIS_MODULE->name);
    return 0;
}

static int pd_close(struct inode *pinode, struct file *pfile) {
    printk(KERN_INFO "%s: pd_close() called.\n", THIS_MODULE->name);
    return 0;
}

static char data[MAX_PKT_SIZE] = "";
static ssize_t pd_read(struct file *pfile, char __user *ubuf, size_t usize, loff_t *pfpos) {
    int pipe, ret, nbytes, bytes_to_read, len=sizeof(data), length=0;
    printk(KERN_INFO "%s: pd_read() called.\n", THIS_MODULE->name);
    // receive the data from the device
    pipe = usb_rcvbulkpipe(device, BULK_EP_IN); // in endpoint
    ret = usb_bulk_msg(device, pipe, data, len, &length, 5000);
    if(ret < 0) {
        printk(KERN_ERR "%s: failed to read from bulk ep.\n", THIS_MODULE->name);
        return ret;
    }
    // send that data to the user space -- copy_to_user()
	bytes_to_read = MIN(usize, length);
	nbytes = bytes_to_read - copy_to_user(ubuf, data, bytes_to_read);
	return nbytes;
}

static ssize_t pd_write(struct file *pfile, const char __user *ubuf, size_t usize, loff_t *pfpos) {
    int pipe, ret, len, bytes_to_write, length=0;
    char data[MAX_PKT_SIZE] = "";
    printk(KERN_INFO "%s: pd_write() called.\n", THIS_MODULE->name);
    // collect data from user space into a temp buffer -- copy_from_user()
	bytes_to_write = MIN(usize, MAX_PKT_SIZE);
	len = bytes_to_write - copy_from_user(data, ubuf, bytes_to_write);
	if (len == 0)
	{
		printk(KERN_ERR "%s: no data to write.\n", THIS_MODULE->name);
		return -EFAULT;
	}

    // send that data to the device
    pipe = usb_sndbulkpipe(device, BULK_EP_OUT); // out endpoint
    ret = usb_bulk_msg(device, pipe, data, len, &length, 5000);
    if(ret < 0) {
        printk(KERN_ERR "%s: failed to write on bulk ep.\n", THIS_MODULE->name);
        return ret;
    }
    return length;
}

module_init(pd_init);
module_exit(pd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nilesh Ghule <nilesh@sunbeaminfo.com>");
MODULE_DESCRIPTION("Simple USB Device Driver.");

/*
1. attach pendrive and unmount it (if auto-mounted)
2. terminal> lsmod | grep "usb"
3. terminal> sudo modprobe -r uas
4. terminal> sudo modprobe -r usb_storage
5. terminal> make
6. terminal> sudo insmod usb_pd.ko
7. terminal> dmesg | tail -15
	* check if probe is invoked & device info is visible.
8. terminal> sudo cat /dev/pd0
	* Error: Connection timed out 
	* dmesg | tail -15 --> check if open(), read() and close() is called.
9. remove pendrive.
10. terminal> dmesg | tail -15
	* check if disconnect is invoked.
11. terminal> sudo rmmod pd_driver.ko
*/
