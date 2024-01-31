
#include"bst.h"

int main(void)
{
    bst_t bst;
    init_bst(&bst);

    add_node_bst(&bst, 8);
    add_node_bst(&bst, 3);
    add_node_bst(&bst, 10);
    add_node_bst(&bst, 1);
    add_node_bst(&bst, 6);
    add_node_bst(&bst, 14);
    add_node_bst(&bst, 4);
    add_node_bst(&bst, 7);
    add_node_bst(&bst, 13);

    printf("Inorder : ");
    inorder(bst.root);
    printf("\n");

    return 0;
}