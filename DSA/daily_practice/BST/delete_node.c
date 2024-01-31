#include<stdlib.h>
#include"bst.h"

void delete_node_bst(bst_t *tree, int data)
{
    node_t *parent;
    node_t *temp = search_node_with_parent(tree, data, &parent);

    if(temp == NULL)
        return;
    
    if(temp->left != NULL && temp->right != NULL)
    {
        node_t *pred = temp->left;
        parent = temp;
        while(pred->right != NULL)
        {
            parent = pred;
            pred = pred->right;
        }
        
        temp->data = pred->data;

        temp = pred;
    }
    if(temp->left == NULL)
    {
        if(temp == tree->root)
            tree->root = temp->right;
        else if(temp == parent->left)
            parent->left = temp->right;
        else
            parent->right = temp->right;
    }
    else //if(temp->right == NULL)
    {
        if(temp == tree->root)
            tree->root = temp->left;
        else if(temp == parent->left)
            parent->left = temp->left;
        else
            parent->right = temp->left;
    }
    
    free(temp);
} 