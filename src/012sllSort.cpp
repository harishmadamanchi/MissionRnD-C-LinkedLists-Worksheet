/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	struct node *new_node, *temp;
	int ones = 0, zeros = 0, twos = 0;
	new_node = head;
	while (new_node != NULL){
		if (new_node->data == 0){
			zeros++;
		}
		else if (new_node->data == 1){
			ones++;
		}
		else if (new_node->data == 2){
			twos++;
		}
		new_node = new_node->next;
	}
	temp = head;
	while (zeros > 0){
		temp->data = 0;
		temp = temp->next;
		zeros--;
	}
	while (ones > 0){
		temp->data = 1;
		temp = temp->next;
		ones--;
	}
	while (twos > 0){
		temp->data = 2;
		temp = temp->next;
		twos--;
	}
}