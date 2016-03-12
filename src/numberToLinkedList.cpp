/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node  *temp;
	temp = NULL;
	int new_data;
	if (N == 0){
		struct node* new_node = (struct node*) malloc(sizeof(struct node));
		new_node->num = N;
		new_node->next = NULL;
		return new_node;
	}
	if (N < 0)
		N = -N;
	while (N != 0){
		struct node* new_node = (struct node*) malloc(sizeof(struct node));
		new_data = N % 10;
		new_node->num = new_data;
		new_node->next = temp;
		temp = new_node;
		N = N / 10;
	}
	return temp;
}