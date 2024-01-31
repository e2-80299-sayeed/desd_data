#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left, *right;
	int height;
}node_t;

typedef struct avl_tree
{
	node_t *root;
}avl_tree_t;

avl_tree_t t1;

node_t *create_node(int val)
{
	node_t *newnode = (node_t *)malloc(sizeof(node_t));
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 1;

	return newnode;
}
int get_height(node_t *node)
{
	if(node==NULL)
		return 0;
	return node->height;
}
int get_bf(node_t *node)
{
	if(node==NULL)
		return 0;
	return get_height(node->left) - get_height(node->right);
}

void delete_all(node_t *trav)
{
	if(trav==NULL)
		return;
	delete_all(trav->left);
	delete_all(trav->right);
	free(trav);
}

int max(int v1, int v2)
{
	return v1 > v2 ? v1 : v2;
}

node_t* left_rotate(node_t *parent, node_t *axis)
{
	if(axis==NULL || axis->right==NULL)
		return NULL;
	node_t *newaxis = axis->right;
	axis->right = newaxis->left;
	newaxis->left = axis;
	if(axis==t1.root)
		t1.root = newaxis;
	else if(axis==parent->left)
		parent->left = newaxis;
	else
		parent->right = newaxis;
	axis->height = max(get_height(axis->left), get_height(axis->right))+1;
	newaxis->height = max(get_height(newaxis->left), get_height(newaxis->right))+1;
	return newaxis;
}
node_t* right_rotate(node_t *parent, node_t *axis)
{
	if(axis==NULL || axis->left==NULL)
		return NULL;
	node_t *newaxis = axis->left;
	axis->left = newaxis->right;
	newaxis->right = axis;
	if(axis==t1.root)
		t1.root = newaxis;
	else if(axis==parent->left)
		parent->left = newaxis;
	else
		parent->right = newaxis;
	axis->height = max(get_height(axis->left), get_height(axis->right))+1;
	newaxis->height = max(get_height(newaxis->left), get_height(newaxis->right))+1;
	return newaxis;
}
void add_node(node_t *parent, node_t *trav, int val)
{
	// simple add node -- recursive
	if(val < trav->data)
	{
		if(trav->left == NULL)
			trav->left = create_node(val);
		else
			add_node(trav, trav->left, val);
	}
	else
	{
		if(trav->right == NULL)
			trav->right = create_node(val);
		else
			add_node(trav, trav->right, val);
	}
	// adjust height of node.
	trav->height = max(get_height(trav->left), get_height(trav->right)) + 1;
	int bf = get_bf(trav);
	// left-left case
	if(bf > 1 && val < trav->left->data)
	{
		printf("LL = %d\n", trav->data);
		right_rotate(parent, trav);
		return;
	}
	// right-right case
	if(bf < -1 && val > trav->right->data)
	{
		printf("RR = %d\n", trav->data);
		left_rotate(parent, trav);
		return;
	}
	// left-right case
	if(bf > 1 && val > trav->left->data)
	{
		printf("LR = %d\n", trav->data);
		left_rotate(trav, trav->left);
		right_rotate(parent, trav);
		return;
	}
	// right-left case
	if(bf < -1 && val < trav->right->data)
	{
		printf("RL = %d\n", trav->data);
		right_rotate(trav, trav->right);
		left_rotate(parent, trav);
		return;
	}
}
void add(int val)
{
	if(t1.root==NULL)
		t1.root = create_node(val);
	else
		add_node(NULL, t1.root, val);
}
void preorder(node_t *trav)
{
	if(trav==NULL)
		return;
	printf("%d (%d) ", trav->data, trav->height);
	preorder(trav->left);
	preorder(trav->right);
}

void del_node(node_t *parent, node_t *trav, int val)
{
	// node not found.
	if(trav==NULL)
		return;
	// delete in left sub-tree
	if(val < trav->data)
		del_node(trav, trav->left, val);
	// delete in right sub-tree
	else if(val > trav->data)
		del_node(trav, trav->right, val);
	// if have right child
	else if(trav->left==NULL)
	{
		if(trav==t1.root)
			t1.root = trav->right;
		else if(trav==parent->left)
			parent->left = trav->right;
		else
			parent->right = trav->right;
		free(trav);
		trav = NULL;
	}
	// if have left child
	else if(trav->right==NULL)
	{
		if(trav==t1.root)
			t1.root = trav->left;
		else if(trav==parent->left)
			parent->left = trav->left;
		else
			parent->right = trav->left;
		free(trav);
		trav = NULL;
	}
	// if both child nodes
	else if(trav->left!=NULL && trav->right!=NULL)
	{
		// find inorder successsor
		node_t *temp = trav->right;
		while(temp->left != NULL)
			temp = temp->left;
		trav->data = temp->data;
		del_node(trav, trav->right, temp->data);
	}
	// if node is deleted or root is reached
	if(trav == NULL)
		return;
	// update heights
	trav->height = max(get_height(trav->left), get_height(trav->right)) + 1;
	int bf = get_bf(trav);
	// left-left case
	if(bf > 1 && get_bf(trav->left) >= 0)
	{
		right_rotate(parent, trav);
		return;
	}
	// left-right case
	if(bf > 1 && get_bf(trav->left) < 0)
	{
		left_rotate(trav, trav->left);
		right_rotate(parent, trav);
		return;
	}
	// right-right case
	if(bf < -1 && get_bf(trav->right) <= 0)
	{
		left_rotate(parent, trav);
		return;
	}
	// right-left case
	if(bf < -1 && get_bf(trav->right) > 0)
	{
		right_rotate(trav, trav->right);
		left_rotate(parent, trav);
		return;
	}
}
void del(int val)
{
	del_node(NULL, t1.root, val);
}

int main()
{
	add(9);
	add(5);
	add(10);
	add(0);
	add(6);
	add(11);
	add(-1);
	add(1);
	add(2);
	preorder(t1.root);
	printf("\n");
	del(10);
	preorder(t1.root);
	return 0;
}
