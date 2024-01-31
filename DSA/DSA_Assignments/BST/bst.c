#include"bst.h"

void init_bst(bst_t *tree)
{
    tree->root = NULL;
}

int is_empty(bst_t *tree)
{
    return tree->root == NULL;
}

node_t *search_node(bst_t *tree, int key)
{
    node_t *trav = tree->root;
    while (trav != NULL)
    {
        if(key == trav->data)
            return trav;
        else if(key < trav->data)
            trav = trav->left;
        else
            trav = trav->right;
    }
    return NULL;
}

node_t *search_node_with_parent(bst_t *tree, int key, node_t **pparent)
{
    node_t *trav = tree->root;
    *pparent = NULL;
    while (trav != NULL)
    {
        if(key == trav->data)
            break;
        *pparent = trav;
        if(key < trav->data)
            trav = trav->left;
        else
            trav = trav->right;
    }
        return trav;   
}

int height(node_t *trav)
{
    if(trav == NULL)
        return 0;
        
    int hl = height(trav->left);
    int hr = height(trav->right);

    int max = hl > hr ? hl : hr;

    return max + 1;
}