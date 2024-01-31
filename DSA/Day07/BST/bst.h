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
    // int count;
    // int height;
    // ...
}bst_t;

void init_bst(bst_t *bst);
int is_empty(bst_t *bst);

node_t *create_node(int data);
void add_node_bst(bst_t *bst, int data);

void inorder(node_t *bst);


#endif