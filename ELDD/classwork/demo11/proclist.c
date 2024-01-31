#include<linux/module.h>
#include<linux/list.h>
#include<linux/init_task.h>

static __init int sayeed_init(void)
{	
	struct task_struct *trav;
	
	list_for_each_entry(trav, &init_task.tasks,tasks)
	{
		printk(KERN_INFO "%s : pid = %d, name = %s\n",THIS_MODULE->name, trav->pid, trav->comm);
		
	}	
	
	return 0;
}

static __exit void sayeed_exit(void)
{
	printk(KERN_INFO "%s : sayeed_exit() : de-initialisation is successful\n",THIS_MODULE->name);
}

module_init(sayeed_init);
module_exit(sayeed_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sayeed");
MODULE_DESCRIPTION("This is my proclist module");

