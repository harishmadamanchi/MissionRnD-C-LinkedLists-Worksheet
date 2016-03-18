/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node *merge(struct node *, struct node *);
void mergesort(struct node **);
void  partion(struct node *, struct node **, struct node **);


void mergesort(struct node **head1)
{
	struct node *header = *head1;
	struct node *a;
	struct node *b;
	if (header == NULL || header->next == NULL)
	{
		return;
	}
	partion(header, &a, &b);
	mergesort(&a);
	mergesort(&b);
	*head1 = merge(a, b);
}


struct node *merge(struct node *a, struct node *b)
{
	struct node *temp = NULL;
	if (a == NULL)
		return(b);

	else if (b == NULL)
		return(a);
	if (a->num <= b->num)
	{

		temp = a;
		temp->next = merge(a->next, b);
	}
	else  if (b->num <= a->num)
	{
		temp = b;
		temp->next = merge(a, b->next);
	}
	return(temp);
}


void  partion(struct node *src, struct node **first, struct node **last)
{
	struct node *fast;
	struct node *slow;
	if (src == NULL || src->next == NULL)
	{
		*first = src;
		*last = NULL;
	}
	else
	{

		fast = src->next;
		slow = src;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}

		}
		*first = src;
		*last = slow->next;
		slow->next = NULL;
	}
}

struct node * sortLinkedList(struct node *head) {
	if (head != NULL)
	{
		mergesort(&head);
		return head;
	}
	return NULL;
}