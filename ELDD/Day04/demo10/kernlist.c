#include<linux/module.h>
#include<linux/list.h>
#include<linux/slab.h>

struct student{
	char name[12];
	int rollno;
	int std;
	struct list_head list;
};

struct list_head head;

static __init int desd_init(void)
{
	struct student *ptr;
	struct list_head *trav;

	// initialise list head
	INIT_LIST_HEAD(&head);

	// Allocate memory to 1 student dynamically
	ptr = kmalloc(sizeof(struct student), GFP_KERNEL);
	if(ptr == NULL)
	{
		printk(KERN_ERR "kmalloc() is failed to allocate memory\n");
		goto kmalloc_failed;
	}
	// fill content of student into allocated space
	strcpy(ptr->name, "abc");
	ptr->rollno = 20;
	ptr->std = 3;
	// add node into linked list
	list_add(&ptr->list, &head);

	// Allocate memory to 1 student dynamically
	ptr = kmalloc(sizeof(struct student), GFP_KERNEL);
	if(ptr == NULL)
	{
		printk(KERN_ERR "kmalloc() is failed to allocate memory\n");
		goto kmalloc_failed;
	}
	// fill content of student into allocated space
	strcpy(ptr->name, "pqr");
	ptr->rollno = 81;
	ptr->std = 5;
	// add node into linked list
	list_add_tail(&ptr->list, &head);

	// Allocate memory to 1 student dynamically
	ptr = kmalloc(sizeof(struct student), GFP_KERNEL);
	if(ptr == NULL)
	{
		printk(KERN_ERR "kmalloc() is failed to allocate memory\n");
		goto kmalloc_failed;	
	}
	// fill content of student into allocated space
	strcpy(ptr->name, "mno");
	ptr->rollno = 50;
	ptr->std = 3;
	// add node into linked list
	list_add_tail(&ptr->list, &head);

	// traverse the list and print it

	// option1
	list_for_each(trav, &head)
	{
		ptr = list_entry(trav, struct student, list);
		printk(KERN_INFO " %s : name = %s, rollno = %d, std = %d\n", THIS_MODULE->name, ptr->name, ptr->rollno, ptr->std);
	}

	// option2
	list_for_each_entry(ptr, &head, list)
	{
		printk(KERN_INFO " %s : name = %s, rollno = %d, std = %d\n", THIS_MODULE->name, ptr->name, ptr->rollno, ptr->std);
	}

	return 0;
kmalloc_failed:
	list_for_each_entry(ptr, &head, list)
	{
		list_del(&ptr->list);
		kfree(ptr);
	}

	return -1;
}

static __exit void desd_exit(void)
{
	struct student *ptr;
	list_for_each_entry(ptr, &head, list)
	{
		list_del(&ptr->list);
		kfree(ptr);
	}
}

module_init(desd_init);
module_exit(desd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DESD @ SUNBEAM");
MODULE_DESCRIPTION("This is demo of Kernel Linked List");

















