#include<linux/module.h>
#include<linux/init_task.h>
#include<linux/list.h>
#include<asm/current.h>
#include<linux/thread_info.h>

static __init int sayeed_init(void)
{
	struct task_struct *ptr;
	printk(KERN_INFO "%s : sayeed_init() is called\n",THIS_MODULE->name);
	
	printk(KERN_INFO "%s : current pid = %d, name = %s.\n",THIS_MODULE->name, current->pid, current->comm);

	list_for_each_entry(ptr, &current->tasks, tasks)
	{
		
		printk(KERN_INFO "%s :  pid = %d, name = %s.\n",THIS_MODULE->name, ptr->pid, ptr->comm);
	}
		return 0;
} 
	
static __exit void sayeed_exit(void)
{
		printk(KERN_INFO "%s : sayeed_exit() is called.\n",THIS_MODULE->name);
}

module_init(sayeed_init);
module_exit(sayeed_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sayeed");
MODULE_DESCRIPTION("This is my curr_proclist module");
