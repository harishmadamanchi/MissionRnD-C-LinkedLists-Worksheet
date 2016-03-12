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

struct node * sortLinkedList(struct node *head) {
	struct node *temp1, *temp2, *temp;
	int flag = 0;
	if (head != NULL){
		temp1 = head;
		while (temp1 != NULL){
			flag = 0;
			temp2 = head;
			temp = temp2;
			while (temp2->next != NULL){
				if ((temp2->next)->num < temp2->num)
				{
					if (temp2 == head){
						temp1 = head;
						temp2 = temp2->next;
						head = temp2;
						temp1->next = temp2->next;
						head->next = temp1;
					}
					else
					{
						temp1 = temp2;
						temp2 = temp2->next;
						temp1->next = temp2->next;
						temp2->next = temp1;
						temp->next = temp2;
					}
					flag = 1;
				}
				temp = temp2;
				temp2 = temp2->next;
			}
			if (flag == 0)
				return head;
		}
	}
	return NULL;
}