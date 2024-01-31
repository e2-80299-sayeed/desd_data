#include<linux/module.h>
#include<linux/list.h>
#include<linux/slab.h>

struct student {
	char name[12];
	int rollno;
	int std;
	struct list_head list;
};

struct list_head head;

static __init int sayeed_init(void)
{
	struct student *ptr;
	struct list_head *trav;
	
	INIT_LIST_HEAD(&head);
	
	ptr = kmalloc(sizeof(struct student), GFP_KERNEL);
	if(ptr == NULL)
	{
		printk(KERN_ERR "kmalloc() is failed to allocate memory\n");
		
		goto kmalloc_failed;	
	}
	
	strcpy(ptr->name, "Sayeed");
	ptr->rollno = 20;
	ptr->std = 3;
	list_add(&ptr->list, &head);

		
	ptr = kmalloc(sizeof(struct student), GFP_KERNEL);
	if(ptr == NULL)
	{
		printk(KERN_ERR "kmalloc() is failed to allocate memory\n");
		
		goto kmalloc_failed;	
	}
	
	strcpy(ptr->name, "Sourac");
	ptr->rollno = 12;
	ptr->std = 5;
	list_add(&ptr->list, &head);
	
	
	ptr = kmalloc(sizeof(struct student), GFP_KERNEL);
	if(ptr == NULL)
	{
		printk(KERN_ERR "kmalloc() is failed to allocate memory\n");
		
		goto kmalloc_failed;	
	}
	
	strcpy(ptr->name, "Neha");
	ptr->rollno = 22;
	ptr->std = 4;
	list_add(&ptr->list, &head);

	list_for_each(trav, &head)
	{
		ptr = list_entry(trav, struct student, list);
		printk(KERN_INFO "%s : name = %s, rollno = %d, std = %d\n",THIS_MODULE->name, ptr->name, ptr->rollno, ptr->std);	
	}

	return 0;
	
kmalloc_failed:
	
	list_for_each_entry(ptr, &head, list)
	{
		list_del_init(&ptr->list);
		kfree(ptr);
	}
	
	return -1;
}

static __exit void sayeed_exit(void)
{
	
	struct student *trav, *temp ;
	
	printk(KERN_INFO "exit before free\n");
	
	list_for_each_entry_safe(trav,temp, &head, list)
	{
		list_del_init(&trav->list);
		kfree(trav);	
	}
	
	printk(KERN_INFO "exit after free\n");
}


module_init(sayeed_init);
module_exit(sayeed_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAYEED");
MODULE_DESCRIPTION("This is my kernel list module");

