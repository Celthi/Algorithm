#include <stdio.h>
#include <stdlib.h>

/* define some constant numbers */
#define N 10

typedef int DataType;
/* binary search tree interface */

typedef struct treenode *TreeNodePtr;
typedef struct treenode {
	DataType data;
	TreeNodePtr left;
	TreeNodePtr right;
} treenode;

/* insert data to BST */
void insert_BST(TreeNodePtr *rootPtr, DataType data)
{
	TreeNodePtr root = *rootPtr; /* get the root */
	TreeNodePtr ptr;
	ptr = malloc(sizeof(treenode));
	if (root == NULL) {
		ptr->data = data;
		ptr->left = NULL;
		ptr->right = NULL;
		*rootPtr = ptr; /* this is important. Put the new node into the tree. */
		return;
	}
	if (data < root->data) {
		insert_BST(&(root->left), data);
	}
	if (data >= root->data) {
		insert_BST(&(root->right), data);
	}
}

/* travesal tree in order */
void print_BST(TreeNodePtr root)
{
	if (root != NULL) {
		print_BST(root->left);
		printf("%d\t",root->data);
		print_BST(root->right);
	}
}

int main(int argc, const char *argv[])
{
	TreeNodePtr root = NULL;
	insert_BST(&root, 3);
	insert_BST(&root, 5);
	insert_BST(&root, 6);
	insert_BST(&root, 3);
	print_BST(root);
	return 0;
}
