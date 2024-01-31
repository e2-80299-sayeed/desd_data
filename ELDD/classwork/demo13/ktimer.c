#include<linux/module.h>
#include<linux/timer.h>

struct timer_list mytimer;
int ticks;
int count = 0;
int sec = 3;

module_param(sec, int, 0644);

void mytimer_function(struct timer_list *ptimer)
{
	printk(KERN_INFO "%s : mytimer_function	: count = %d\n",THIS_MODULE->name, count);
	count++;
	mod_timer(&mytimer, jiffies + ticks);
}
static __init int sayeed_init(void)
{
	ticks = sec * HZ; 

	timer_setup(&mytimer, mytimer_function, 0);
	mytimer.expires = jiffies + ticks;
	add_timer(&mytimer);

	printk(KERN_INFO "%s : Timer initialisation is done successfully\n",THIS_MODULE->name);
	return 0;
}

static __exit void sayeed_exit(void)
{
	del_timer_sync(&mytimer);
	printk(KERN_INFO "%s : Timer deinitialisation is done successfully\n",THIS_MODULE->name);
}

module_init(sayeed_init);
module_exit(sayeed_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DESD @ Sunbeam");
MODULE_DESCRIPTION("This is demo of kernel timers");
