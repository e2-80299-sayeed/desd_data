#include<stdio.h>
#include"list.h"

#define SIZE 10
#define H(k)	k % SIZE

node_t *hash_table[SIZE];

void init_hash_table(void)
{
	for(int i = 0 ; i < SIZE ; i++)
		init_list(&hash_table[i]);
}

void add(int rollno, char *name)
{
	int slot = H(rollno);
	add_node(&hash_table[slot], rollno, name);
}

void print_hash_table(void)
{
	printf("Hash Table : \n");
	for(int i = 0 ; i < SIZE ; i++)
	{
		printf("[%d] : ", i);
		display_list(hash_table[i]);
		printf("\n");
	}
}

int search(int rollno)
{
	int slot = H(rollno);
	node_t *trav = hash_table[slot];
	for( ; trav != NULL ; trav = trav->next)
		if(trav->entry.rollno == rollno)
			return slot;
	return -1;
}

void free_hash_table(void)
{
	for(int i = 0 ; i < SIZE ; i++)
		free_list(&hash_table[i]);
}

int main(void)
{
	init_hash_table();

	add(8, "abc");
	add(3, "xyz");
	add(10, "pqr");
	add(4, "mno");
	add(6, "efg");
	add(13, "uvw");
	add(23, "efg");
	add(24, "abc");

	print_hash_table();

	int key = 20;
	int slot = search(key);
	if(slot == -1)
		printf("%d key is not found in hash table\n", key);
	else
		printf("%d key is found in hash table at slot %d\n", key, slot);


	free_hash_table();
	return 0;
}















