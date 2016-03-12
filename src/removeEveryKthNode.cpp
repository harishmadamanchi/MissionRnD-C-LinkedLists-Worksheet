/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	struct node *temp;
	int count = 1;
	temp = head;
	if (K == 1){
		head = NULL;
	}
	else if (temp != NULL&&K > 0){
		while (temp->next != NULL){
			if ((count+1)%K == 0){
				temp->next = (temp->next)->next;
				count = count + 2;
			}
			else{
				count++;
			}
			if (temp->next != NULL)
				temp = temp->next;
			else
				break;
		}
	}
	else{
		head = NULL;
	}
	return head;
}