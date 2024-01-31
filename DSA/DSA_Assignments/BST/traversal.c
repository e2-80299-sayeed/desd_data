#include"bst.h"
#include"stack.h"
#include"queue.h"

void preorder(node_t *trav) //VLR
{
    if(trav == NULL)
        return;
    printf("%-4d", trav->data);//Visit
    preorder(trav->left);// Left
    preorder(trav->right);//Right
}
void inorder(node_t *trav)// LVR
{
    if(trav == NULL)
        return;
    inorder(trav->left);//Left
    printf("%-4d", trav->data);//Visit
    inorder(trav->right);// Right
}

void postorder(node_t  *trav)// LRV
{
    if(trav == NULL)
        return;
    postorder(trav->left);// Left
    postorder(trav->right);// Right
    printf("%-4d",trav->data);// Visit
}

void DFS_traversal(node_t *trav)
{
    stack_t st;
    init_stack(&st);
    printf("DFS Traversal :");

    push(&st, trav);
    while(!s_is_empty(&st))
    {
        trav = pop(&st);
        printf("%-4d",trav->data);

        if(trav->right != NULL)
            push(&st,trav->right);
        
        if(trav->left != NULL)
            push(&st, trav->left);
    }
    printf("\n");
}

void BFS_traversal(node_t *trav)
{
    queue_t q;
    q_init(&q);
    printf("BFS traversal :");

    q_push(&q,trav);
    while(!q_is_empty(&q))
    {
        trav = q_pop(&q);
        printf("%-4d",trav->data);

        if(trav->left !=NULL)
            q_push(&q,trav->left);
        if(trav->right != NULL)
            q_push(&q, trav->right);
    }

    printf("\n");
}