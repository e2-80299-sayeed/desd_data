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

void add_node_bst(bst_t *tree, int data)
{
    node_t *newnode = create_node(data);

    if(is_empty(tree))
        tree->root = newnode;
    else
    {
        node_t *trav = tree->root;
        while(1)
        {
            if(data < trav->data)
            {
                if(trav->left == NULL)
                {    
                    trav->left = newnode;
                    break;
                }
                else
                    trav = trav->left;
            }
            else
            {
                if(trav->right == NULL)
                {
                    trav->right = newnode;
                     break;
                }
                else
                    trav = trav->right;
            }
        }

    }
}