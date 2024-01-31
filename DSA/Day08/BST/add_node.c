#include"bst.h"
#include<stdlib.h>

node_t *create_node(int data)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    if(newnode != NULL)
    {
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
    }
    return newnode;
}

void add_node_bst(bst_t *bst, int data)
{
    //1. create node with given data
    node_t *newnode = create_node(data);
    //2. if tree is empty
    if(is_empty(bst))
	    //a. add newnode into root itself
        bst->root = newnode;
    //3. if tree is not empty
    else
    {
    	//3.1 create trav pointer and start at root
        node_t *trav = bst->root;
        while(1)
        {
    	    //3.2 compare data with current node data
            if(data < trav->data)
            {
	    	    //3.2.1 if data is less than current node data
		    	    //3.2.1.1 if left of current node is empty
			    	if(trav->left == NULL) 
                    {   
                        // add newnode into left of current node
                        trav->left = newnode;
                        break;
                    }
                    //3.2.1.2 if left of current node is not empty
			    	else
                        // go into left of current node
                        trav = trav->left;
            }
            else
            {
                //3.2.2 if data is greater than current node data
			        //3.2.2.1 if right of current node is empty
				    if(trav->right == NULL)   
                    { 
                        // add newnode into right of current node
                        trav->right = newnode;
                        break;
                    }
                    //3.2.2.2 if right of current node is not empty
			    	else
                        // go into right of current node
                        trav = trav->right;
            }
        }//3.3 repeat step 3.2 untill node is added
    }
}