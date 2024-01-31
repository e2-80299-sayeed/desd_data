#include"bst.h"
#include"stack.h"
#include"queue.h"

void preorder(node_t *trav)
{
    if(trav == NULL)
        return;
    // visit current node
    printf("%-4d", trav->data);
    // go into left of current node
    preorder(trav->left);
    // go into right of current node
    preorder(trav->right);
}

void inorder(node_t *trav)
{
    if(trav == NULL)
        return;
    // go into left of current node
    inorder(trav->left);
    // visit current node
    printf("%-4d", trav->data);
    // go into right of current node
    inorder(trav->right);
}

void postorder(node_t *trav)
{
    if(trav == NULL)
        return;
    // go into left of current node
    postorder(trav->left);
    // go into right of current node
    postorder(trav->right);
    // visit current node
    printf("%-4d", trav->data);
}

void DFS_traversal(node_t *trav)
{
    stack_t st;
    init_stack(&st);
    printf("DFS Traversal : ");
    //1. push root on stack
    push(&st, trav);
    while (!s_is_empty(&st))
    {   
        //2. pop one node from stack
        trav = pop(&st);
        //3. visit(print) node
        printf("%-4d", trav->data);
        //4. if right exist, push it on stack
        if(trav->right != NULL)
            push(&st, trav->right);
        //5. if left exist, push it on stack
        if(trav->left != NULL)
            push(&st, trav->left);
        //6. while stack is not empty 
	}//repeat ste 2 to 5
    printf("\n");
}

void BFS_traversal(node_t *trav)
{
    queue_t q;
    q_init(&q);
    printf("BFS Traversal : ");
    //1. push root on queue
    q_push(&q, trav);
    while (!q_is_empty(&q))
    {
        //2. pop one node from queue
        trav = q_pop(&q);    
        //3. visit(print) node
        printf("%-4d", trav->data);
        //4. if left exist, push it on queue
        if(trav->left != NULL)
            q_push(&q, trav->left);
        //5. if right exist, push it on queue
        if(trav->right != NULL)
            q_push(&q, trav->right);
    }//6. while queue is not empty repeat ste 2 to 5
    printf("\n");
}


