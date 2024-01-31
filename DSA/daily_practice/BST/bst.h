#ifndef __BST_H
#define __BST_H

#include<stdio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node_t;

typedef struct bst
{
    node_t *root;
}bst_t;

void init_bst(bst_t *tree);
int is_empty(bst_t *tree);

node_t *create_node(int data);
void add_node_bst(bst_t *tree, int data);
void delete_node_bst(bst_t *tree, int data);

void preorder(node_t *trav);
void inorder(node_t *trav);
void postorder(node_t  *trav);
void DFS_traversal(node_t *trav);
void BFS_traversal(node_t *trav);
node_t *search_node(bst_t *tree, int key);
node_t *search_node_with_parent(bst_t *tree,int key,node_t **pparent);
int height(node_t *trav);
#endif