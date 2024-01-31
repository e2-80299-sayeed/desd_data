#include"bst.h"

int main(void)
{
    bst_t tree;
    
    init_bst(&tree);

    add_node_bst(&tree, 8);
    add_node_bst(&tree, 3);
    add_node_bst(&tree, 10);
    add_node_bst(&tree, 1);
    add_node_bst(&tree, 6);
    add_node_bst(&tree, 14);
    add_node_bst(&tree, 4);
    add_node_bst(&tree, 7);
    add_node_bst(&tree, 13);

   /* 
    printf("Inorder : ");
    inorder(tree.root);
    printf("\n");

    printf("Preorder :");
    preorder(tree.root);
    printf("\n");

    printf("Postorder :");
    postorder(tree.root);
    printf("\n");

    DFS_traversal(tree.root);
    BFS_traversal(tree.root);
    node_t *temp = search_node(&tree,15);
    if(temp != NULL)
        printf("%d key is found \n",temp->data);
    else    
        printf("Key is not found\n");
    */
    printf("Inorder : ");
    inorder(tree.root);
    printf("\n");

    delete_node_bst(&tree, 1);
    delete_node_bst(&tree, 14);

    printf("Inorder : ");
    inorder(tree.root);
    printf("\n");

    printf("Height = %d\n",height(tree.root));
    
    return 0;
}