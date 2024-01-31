#include<stdlib.h>
#include"bst.h"

void delete_node_bst(bst_t *bst, int data)
{
    //1. search node with parent
    node_t *parent;
    node_t *temp = search_node_with_parent(bst, data, &parent);

    //1.1 if node is not found
    if(temp == NULL)
        return;
        
    //2. node with 2 childs
    if(temp->left != NULL && temp->right != NULL)
    {
	    //a. find predecessor of node
	    node_t *pred = temp->left;
	    parent = temp;
	    while(pred->right != NULL)
	    {
		    parent = pred;
		    pred = pred->right;
	    }
	    //b. replace data by predecessor
	    temp->data = pred->data;
        //c. move temp on predecessor
        temp = pred;
    }
    //3. node with single child(right)
    if(temp->left == NULL)
    {
	    if(temp == bst->root)				// root node
	    	bst->root = temp->right;
	    else if(temp == parent->left)		// parent's left
	    	parent->left = temp->right;
	    else								// parent;s right
		    parent->right = temp->right;
    }
    //4. node with single child(left) 
    else //if(temp->right == NULL)
    {
	    if(temp == bst->root)					// root
		    bst->root = temp->left;
	    else if(temp == parent->left)		// parent's left
		    parent->left = temp->left;
	    else								// parent;s right
	    	parent->right = temp->left;
    }
    // release memory of temp
    free(temp);
}