#include"bst.h"

void init_bst(bst_t *bst){
    bst->root = NULL;
}

int is_empty(bst_t *bst)
{
    return bst->root == NULL;
}

node_t *search_node(bst_t *bst, int key)
{
    //1. start from root
    node_t *trav = bst->root;
    while (trav != NULL)
    {    
        //2. if key is equal to current data
        if(key == trav->data)
	        //return current node
            return trav;
        //3. if key is less than current data
        else if(key < trav->data)
        	// search key into left of current node
            trav = trav->left;
        //4. if key is greater than current data
        else
	        // search key into right of current node
            trav = trav->right;
    }//5. repeat step 2 to 4 till leaf nodes 
    //6. if key is not found
    return NULL;
}

node_t *search_node_with_parent(bst_t *bst, int key, node_t **pparent)
{
    //1. start from root
    node_t *trav = bst->root;
    *pparent = NULL;
    while (trav != NULL)
    {    
        //2. if key is equal to current data
        if(key == trav->data)
	        //return current node
            break;
        *pparent = trav;
        //3. if key is less than current data
        if(key < trav->data)
        	// search key into left of current node
            trav = trav->left;
        //4. if key is greater than current data
        else
	        // search key into right of current node
            trav = trav->right;
    }//5. repeat step 2 to 4 till leaf nodes 
    //6. if key is not found
    return trav;
}

int height(node_t *trav)
{
    //0. if left or right sub tree is absent 
    if(trav == NULL)
		return 0;
    //1. find height of left subtree
    int hl = height(trav->left);
    //2. find height of right subtree
    int hr = height(trav->right);
    //3. find max height
    int max = hl > hr ? hl : hr;
    //4. add one into max height(return)
    return max + 1;
}