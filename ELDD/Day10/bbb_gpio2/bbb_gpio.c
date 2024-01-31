#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/gpio.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>

#define LED_GPIO	49	
#define SWITCH_GPIO	115		

// global variables
// device number
static dev_t devno;
static int major=250;
// device class
static struct class *pclass;
// cdev object
static struct cdev bbb_gpio_cdev;
// led state
static int led_state;
// gpio irq
static int irq;

// switch isr declaration
static irqreturn_t switch_isr(int irq, void *param);

// device functions/operations declarations

static int bbb_gpio_open(struct inode *pinode, struct file *pfile);
static int bbb_gpio_close(struct inode *pinode, struct file *pfile);
static ssize_t bbb_gpio_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos);
static ssize_t bbb_gpio_write(struct file *pfile, const char * __user ubuf, size_t ubuf_size, loff_t *fpos);

// device operations
static struct file_operations bbb_gpio_fops = {
	.owner = THIS_MODULE,
	.open = bbb_gpio_open,
	.release = bbb_gpio_close,
	.read = bbb_gpio_read,
	.write = bbb_gpio_write
};

// kernel module init & exit functions

static __init int bbb_gpio_init(void) {
	int ret, minor;
	struct device *pdevice;

	printk(KERN_INFO "%s: bbb_gpio_init() called.\n", THIS_MODULE->name);
	// register/allocate device number
	devno = MKDEV(major, 0);
	ret = alloc_chrdev_region(&devno, 0, 1, "bbb_gpio");
	if(ret < 0) {
		printk(KERN_ERR "%s: alloc_chrdev_region() failed.\n", THIS_MODULE->name);
		return ret;
	}
	major = MAJOR(devno);
	minor = MINOR(devno);
	printk(KERN_INFO "%s: alloc_chrdev_region() allocated device number major=%d, minor=%d.\n", THIS_MODULE->name, major, minor);

	// create device class and device file
	pclass = class_create(THIS_MODULE, "bbb_gpio_class");
	if(IS_ERR(pclass)) {
		printk(KERN_ERR "%s: class_create() failed.\n", THIS_MODULE->name);
		unregister_chrdev_region(devno, 1);
		return -1;
	}
	printk(KERN_INFO "%s: class_create() created device class.\n", THIS_MODULE->name);

	pdevice = device_create(pclass, NULL, devno, NULL, "bbb_gpio%d", 0);
	if(IS_ERR(pdevice)) {
		printk(KERN_ERR "%s: device_create() failed.\n", THIS_MODULE->name);
		class_destroy(pclass);
		unregister_chrdev_region(devno, 1);
		return -1;
	}
	printk(KERN_INFO "%s: device_create() created device file.\n", THIS_MODULE->name);

	// initialize cdev and add it into kernel
	cdev_init(&bbb_gpio_cdev, &bbb_gpio_fops);
	bbb_gpio_cdev.owner = THIS_MODULE;
	ret = cdev_add(&bbb_gpio_cdev, devno, 1);
	if(ret < 0) {
		printk(KERN_ERR "%s: cdev_add() failed.\n", THIS_MODULE->name);
		device_destroy(pclass, devno);
		class_destroy(pclass);
		unregister_chrdev_region(devno, 1);
		return -1;
	}
	printk(KERN_INFO "%s: cdev_add() added char device in kernel db.\n", THIS_MODULE->name);
	
	// check if LED gpio is valid
	if(!gpio_is_valid(LED_GPIO)) {
		printk(KERN_ERR "%s: gpio pin %d is not valid.\n", THIS_MODULE->name, LED_GPIO);
		device_destroy(pclass, devno);
		class_destroy(pclass);
		unregister_chrdev_region(devno, 1);
		return -1;
	}
	printk(KERN_INFO "%s: LED gpio pin is valid.\n", THIS_MODULE->name);

	// request LED gpio pin
	ret = gpio_request(LED_GPIO, "gpio_led");
	if(ret < 0) {
		printk(KERN_ERR "%s: gpio request failed for pin %d.\n", THIS_MODULE->name, LED_GPIO);
		device_destroy(pclass, devno);
		class_destroy(pclass);
		unregister_chrdev_region(devno, 1);
		return -1;
	}
	printk(KERN_INFO "%s: LED gpio pin is requested.\n", THIS_MODULE->name);

	// set LED gpio pin direction to output
	led_state = 0;
	ret = gpio_direction_output(LED_GPIO, led_state);
	if(ret < 0) {
		printk(KERN_ERR "%s: failed to set gpio pin %d direction as output.\n", THIS_MODULE->name, LED_GPIO);
		gpio_free(LED_GPIO);
		device_destroy(pclass, devno);
		class_destroy(pclass);
		unregister_chrdev_region(devno, 1);
		return -1;
	}
	printk(KERN_INFO "%s: LED gpio pin is set output direction.\n", THIS_MODULE->name);
	
	// check if SWITCH gpio is valid
	if(!gpio_is_valid(SWITCH_GPIO)) {
		printk(KERN_ERR "%s: switch gpio pin %d is not valid.\n", THIS_MODULE->name, SWITCH_GPIO);
		gpio_free(LED_GPIO);
		device_destroy(pclass, devno);
		class_destroy(pclass);
		unregister_chrdev_region(devno, 1);
		return -1;
	}
	printk(KERN_INFO "%s: SWITCH gpio pin is valid.\n", THIS_MODULE->name);

	// requst SWITCH gpio pin
	ret = gpio_request(SWITCH_GPIO, "gpio_switch");
	if(ret < 0) {
		printk(KERN_ERR "%s: gpio request failed for pin %d.\n", THIS_MODULE->name, SWITCH_GPIO);
		gpio_free(LED_GPIO);
		device_destroy(pclass, devno);
		class_destroy(pclass);
		unregister_chrdev_region(devno, 1);
		return -1;
	}
	printk(KERN_INFO "%s: SWITCH gpio pin is requested.\n", THIS_MODULE->name);

	// set SWITCH gpio pin direction as input
	ret = gpio_direction_input(SWITCH_GPIO);
	if(ret < 0) {
		printk(KERN_ERR "%s: failed to set gpio pin %d direction as input.\n", THIS_MODULE->name, SWITCH_GPIO);
		gpio_free(SWITCH_GPIO);
		gpio_free(LED_GPIO);
		device_destroy(pclass, devno);
		class_destroy(pclass);
		unregister_chrdev_region(devno, 1);
		return -1;
	}
	printk(KERN_INFO "%s: SWITCH gpio pin is set input direction.\n", THIS_MODULE->name);
	// set SWITCH debouncing delay
	ret = gpio_set_debounce(SWITCH_GPIO, 40);
	if(ret < 0)
		printk(KERN_ERR "%s: failed to set gpio pin %d debouncing delay.\n", THIS_MODULE->name, SWITCH_GPIO);
	else
		printk(KERN_INFO "%s: SWITCH gpio pin is set input direction.\n", THIS_MODULE->name);
	
	// get irq number of SWITCH GPIO
	irq = gpio_to_irq(SWITCH_GPIO);
	if(irq < 0)
		printk(KERN_ERR "%s: failed to get irq for gpio pin %d.\n", THIS_MODULE->name, SWITCH_GPIO);
	else
		printk(KERN_INFO "%s: SWITCH gpio pin irq = %d.\n", THIS_MODULE->name, irq);

	// register switch isr
	if(irq > 0) {
		ret = request_irq(irq, switch_isr, IRQF_TRIGGER_FALLING, "bbb_switch", NULL);
		if(ret < 0)
			printk(KERN_ERR "%s: failed to register isr for switch gpio pin %d.\n", THIS_MODULE->name, SWITCH_GPIO);
		else
			printk(KERN_INFO "%s: SWITCH gpio pin irq is registered.\n", THIS_MODULE->name);
	}
	return 0;
}

static __exit void bbb_gpio_exit(void) {
	printk(KERN_INFO "%s: bbb_gpio_exit() called.\n", THIS_MODULE->name);
	// free switch irq
	free_irq(irq, NULL);
	printk(KERN_INFO "%s: SWITCH gpio pin irq is released.\n", THIS_MODULE->name);
	// release SWITCH gpio pin
	gpio_free(SWITCH_GPIO);
	printk(KERN_INFO "%s: SWITCH gpio pin is free.\n", THIS_MODULE->name);
	// release LED gpio pin
	gpio_free(LED_GPIO);
	printk(KERN_INFO "%s: LED gpio pin is free.\n", THIS_MODULE->name);
	// delete cdev from the kernel
	cdev_del(&bbb_gpio_cdev);
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

module_init(bbb_gpio_init);
module_exit(bbb_gpio_exit);

// device operations implementation
static int bbb_gpio_open(struct inode *pinode, struct file *pfile) {
	printk(KERN_INFO "%s: bbb_gpio_open() called.\n", THIS_MODULE->name);
	return 0;
}

static int bbb_gpio_close(struct inode *pinode, struct file *pfile) {
	printk(KERN_INFO "%s: bbb_gpio_close() called.\n", THIS_MODULE->name);
	return 0;
}

static ssize_t bbb_gpio_read(struct file *pfile, char * __user ubuf, size_t ubuf_size, loff_t *fpos) {
	int val, ret = 0;
	printk(KERN_INFO "%s: bbb_gpio_read() called.\n", THIS_MODULE->name);
	val = gpio_get_value(SWITCH_GPIO);
	if(val == 1)
		ret = 2 - copy_to_user(ubuf, "1\n", 2);
	else if(val == 0)
		ret = 2 - copy_to_user(ubuf, "0\n", 2);
	if(ret < 2) {
		printk(KERN_ERR "%s: bbb_gpio_read() failed.\n", THIS_MODULE->name);
		return -EFAULT;
	}
	return 2;
}

static ssize_t bbb_gpio_write(struct file *pfile, const char * __user ubuf, size_t ubuf_size, loff_t *fpos) {
	char buf[2] = "";
	int ret;
	printk(KERN_INFO "%s: bbb_gpio_write() called.\n", THIS_MODULE->name);
	ret = 1 - copy_from_user(buf, ubuf, 1);
	if(ret != 1) {
		printk(KERN_ERR "%s: bbb_gpio_write() failed.\n", THIS_MODULE->name);
		return -EFAULT;
	}

	if(buf[0] == '1') {
		led_state = 1;
		gpio_set_value(LED_GPIO, 1);
		printk(KERN_INFO "%s: bbb_gpio_write() LED ON.\n", THIS_MODULE->name);
	} else if(buf[0] == '0') {
		led_state = 0;
		gpio_set_value(LED_GPIO, 0);
		printk(KERN_INFO "%s: bbb_gpio_write() LED OFF.\n", THIS_MODULE->name);
	}
	return ubuf_size;
}

// switch isr implementation
static irqreturn_t switch_isr(int irq, void *param) {
	// toggle led
	led_state = ! led_state;
	gpio_set_value(LED_GPIO, led_state);
	printk(KERN_INFO "%s: switch_isr() called -- LED toggled.\n", THIS_MODULE->name);
	return IRQ_HANDLED;
}

// kernel module info macros

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linux GPIO Device Driver with Interrupt Handling DESD Sep-2023 @ Sunbeam Infotech");
MODULE_AUTHOR("Nilesh Ghule <nilesh@sunbeaminfo.com>");
