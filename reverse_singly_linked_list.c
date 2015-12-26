#include <stdlib.h>
#include <stdio.h>

#define LEN 10

typedef int DataType;
typedef struct ListNode {
	DataType val;
	struct ListNode *next;
} ListNode, *ListNodePtr;

/* insert x in the start of the list */
void insert_list(ListNodePtr *head, DataType x)
{
	ListNodePtr p;
	p = malloc(sizeof(ListNode));
	p->val = x;
	p->next = *head;
	*head = p;
}

/* reverse the singly-linked list */
void reverse_singly_list(ListNodePtr *head)
{
	ListNodePtr curr, np, prev;
	if ( *head == NULL || head == NULL) {
		return ;
	}
	curr = *head;
	prev = NULL;
	np  = NULL;
	while (curr != NULL) {
		np = curr->next;
		curr->next = prev;
		prev = curr;
		curr = np;
	}
	*head = prev;
	return ;
}

/* print the singly-linked list 
 * recursive printing */
void print_list(ListNodePtr head)
{
	if (head != NULL)
	{
		printf("%d\t", head->val);
		print_list(head->next);
	}
	else printf("\n");
}

int main(int argc, const char *argv[])
{
	/* establish a list */
	ListNodePtr listHead = NULL;
	/* insert one item to the lsit */
	insert_list(&listHead, 4);
	insert_list(&listHead, 5);
	insert_list(&listHead, 6);
	/* print the original list */
	print_list(listHead);
	/* reverse the list */
	reverse_singly_list(&listHead);
	/* print reversed list */
	print_list(listHead);
	return 0;
}
