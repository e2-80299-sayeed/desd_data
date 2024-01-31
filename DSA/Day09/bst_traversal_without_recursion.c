#include<stdlib.h>
#include<stdio.h>
#include"bst.h"
#include"stack.h"

void preorder(node_t *trav)
{
	stack_t st;
	s_init(&st);

	//1. start traversing from root(trav already pointing to root)
	while(trav != NULL || !s_is_empty(&st))
	{
		while(trav != NULL)
		{
			//2. visit trav
			printf("%-4d", trav->data);
			//3. if trav has right, push trav->right on stack
			if(trav->right != NULL)
				s_push(trav->right, &st);
			//4. go to left of trav
			trav = trav->left;
		}//5. repeat 2-4 until trav is null
		//6. pop node from stack into trav
		if(!s_is_empty(&st))
		{
			trav = s_peek(&st); s_pop(&st);
		}
	}//7. repeat 2-6, until trav is null or stack is empty
}

void inorder(node_t *trav)
{
	stack_t st;
	s_init(&st);

	//1. start traversing from root
	while(trav != NULL || !s_is_empty(&st))
	{
		while(trav != NULL)
		{
			//2. push trav on stack
			s_push(trav, &st);
			//3. go to left of trav
			trav = trav->left;
		}//4. repeat 2-3 until trav is null
		//5. pop node from stack into trav
		if(!s_is_empty(&st))
		{
			trav = s_peek(&st);
			s_pop(&st);
		}
		//6. visit trav
		printf("%-4d", trav->data);
		//7. go to the right
		trav = trav->right;
	}//8. repeat 2-7, until trav is null or stack is empty
}

void postorder(node_t *trav)
{
	stack_t st;
	s_init(&st);
	// start trav from root
	node_t *trav = root;
	// while trav is not null or stack is not empty
	while(trav != NULL || !s_is_empty(&st))
	{
		// until null is reached
		while(trav != NULL)
		{
			// push trav on stack
			s_push(&st, trav);
			// go to trav's left
			trav = trav->left;
		}
		// if stack is not empty
		if(!s_is_empty(&st))
		{
			// pop node from stack into trav
			trav = s_peek(&st); s_pop(&st);
			// if trav's right is not present or visited
			if(trav->right == NULL || trav->right->visited == 1)
			{
				// visit trav & mark it as visited
				printf("%-4d", trav->data);
				trav->visited = 1;
				// make trav null (so that next node will be popped from stack)
				trav = NULL;
			}
			else// otherwise
			{
				// push node on stack
				s_push(&st, trav);
				// go to its right
				trav = trav->right;
			}
		}
	}
}

void bst_free(node_t *trav)
{
	if(trav == NULL)
		return;
	bst_free(trav->left);
	bst_free(trav->right);
	free(trav);
}

