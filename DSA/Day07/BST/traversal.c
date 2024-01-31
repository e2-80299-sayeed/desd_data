#include"bst.h"

void inorder(node_t *trav)
{
    if(trav == NULL)
        return;
    inorder(trav->left);
    printf("%-4d", trav->data);
    inorder(trav->right);
}