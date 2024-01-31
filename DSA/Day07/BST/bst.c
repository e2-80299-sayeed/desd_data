#include"bst.h"

void init_bst(bst_t *bst){
    bst->root = NULL;
}

int is_empty(bst_t *bst)
{
    return bst->root == NULL;
}