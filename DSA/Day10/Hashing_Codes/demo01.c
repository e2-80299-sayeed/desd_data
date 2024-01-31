#include<stdio.h>
#include<string.h>

#define SIZE 10

#define H(k)	k % SIZE
#define H_(k)	(k + 1) % SIZE

typedef struct student{
	int rollno;
	char name[20];
}stud_t;

stud_t hash_table[SIZE];

void print_hash_table(void)
{
	printf("Hash Table (key, Value) : \n");
	for(int i = 0 ; i < SIZE ; i++)
		printf("[%d] %d : %s\n", i, hash_table[i].rollno, hash_table[i].name);
	printf("\n");
}

void add(int rollno, char *name)
{
	stud_t st;
	st.rollno = rollno;
	strcpy(st.name, name);
	int slot = H(rollno);
	if(hash_table[slot].rollno == 0)
	{
		hash_table[slot] = st;
		return;
	}
	if(hash_table[slot].rollno == rollno)
	{
		hash_table[slot] = st;
		return;
	}
	

	int newslot = slot;
	for(int i = 0 ; i < SIZE ; i++)
	{
		newslot = H_(newslot);
		if(hash_table[newslot].rollno == 0)
		{
			hash_table[newslot] = st;
			return;
		}
		if(hash_table[newslot].rollno == rollno)
		{
			hash_table[newslot] = st;
			return;
		}
	}
}


int search(int rollno)
{
	int slot = H(rollno);
	if(hash_table[slot].rollno == rollno)
		return slot;

	int newslot = slot;
	for(int i = 0 ; i < SIZE ; i++)
	{
		newslot = H_(newslot);
		if(hash_table[newslot].rollno == rollno)
			return newslot;
	}
	return -1;
}

int main(void)
{
	add(8, "abc");
	add(3, "xyz");
	add(10, "pqr");
	add(4, "mno");
	add(6, "efg");
	add(13, "uvw");

	print_hash_table();
	
	int key = 10;
	int slot = search(key);
	if(slot == -1)
		printf("%d key is not found in hash table\n", key);
	else
		printf("%d key is found in hash table at slot %d", key, slot);

	return 0;
}

