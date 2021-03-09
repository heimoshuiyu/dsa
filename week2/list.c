/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_2
 */

#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Write all your functions here.
bool IsEmpty(Node *head) {
	if (head == NULL) {
		return true;
	} else {
		return false;
	}
}

/* code from pdf */
Node *InsertNode(Node **phead, int index, double x) {
	if (index < 0)
		return NULL;
	int currIndex = 1;
	Node *currNode = *phead;
	while (currNode != NULL && index > currIndex) {
		currNode = currNode->next;
		currIndex++;
	}
	if (index > 0 && currNode == NULL)
		return NULL;
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = x;
	if (index == 0) {
		newNode->next = *phead;
		*phead = newNode;
	} else {
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	return newNode;
}

int FindNode(Node *head, double x) {
	int position;
	Node *pnode;

	/* position start from 1 */
	for (pnode = head, position = 1; pnode; pnode = pnode->next, position++) {
		if (pnode->data == x) {
			return position;
		}
	}

	return 0;
}

int DeleteNode(Node **phead, double x) {
	/* position start from 1 */
	int position;
	Node *pnode;
	Node *delNode;

	/* if delete the first node */
	if ((*phead)->data == x) {
		delNode = *phead;
		*phead = (*phead)->next;
		free(delNode);
		return 1;
	}

	/* if not the first node */
	for (pnode=*phead, position=2; pnode->next; pnode=pnode->next, position++) {
		/* loop for pnode->next->data == x */
		if (pnode->next->data == x) {
			/* delete node */
			delNode = pnode->next;
			pnode->next = pnode->next->next;
			free(delNode);
			return position;
		}
	}
	
	/* if node not found, return 0 */
	return 0;
}

void DisplayList(Node *head) {
	Node *pnode;
	/* loop for each node */
	for (pnode=head; pnode; pnode=pnode->next) {
		printf("%f ", pnode->data);
	}
	/* new line at the end */
	printf("\n");
}

void DestroyList(Node *head) {
	Node *pnode = head;
	Node *delNode;
	/* loop for each node */
	while (pnode) {
		/* store the tmp node */
		delNode = pnode;
		pnode = pnode->next;
		free(delNode);
	}
}

// Testing all the functions:
int main(void) {
	Node *head = NULL;

	// Output: true
	printf("%s\n", IsEmpty(head) ? "true" : "false");

	// Must output an empty line:
	DisplayList(head);

	// Must output "insert failed":
	Node *result = InsertNode(&head, 20, 7);
	printf("%s\n", result == NULL ? "insert failed" : "insert succeeded");

	// Output: 0.000000 1.000000 2.000000 3.000000 4.000000
	for (int i = 0; i < 5; i++) {
		InsertNode(&head, i, i);
	}
	DisplayList(head);

	// Output: false
	printf("%s\n", IsEmpty(head) ? "true" : "false");

	// Output: 4.000000 3.000000 2.000000 1.000000 0.000000
	// 0.000000 1.000000 2.000000 3.000000 4.000000
	for (int i = 0; i < 5; i++) {
		InsertNode(&head, 0, i);
	}
	DisplayList(head);

	// Output: 0.000000 is at position 5
	//         2.000000 is at position 3
	//         4.000000 is at position 1
	//         6.000000 is not in the list
	for (int i = 0; i < 7; i += 2) {
		int idx = FindNode(head, i);
		if (idx > 0) {
			printf("%f is at position %d\n", (double)i, idx);
		} else {
			printf("%f is not in the list\n", (double)i);
		}
	}

	// Output: inserted 10.000000
	//         4.000000 3.000000 2.000000 10.000000 1.000000 0.000000
	//         0.000000 1.000000 2.000000 3.000000 4.000000
	Node *in = InsertNode(&head, 3, 10);
	printf("inserted %f\n", in->data);
	DisplayList(head);

	// Output: 4.000000 3.000000 2.000000 10.000000 1.000000
	// 0.000000 1.000000 2.000000 3.000000 4.000000
	//         3.000000 2.000000 10.000000 1.000000
	//         0.000000 1.000000 2.000000 3.000000 4.000000
	//         3.000000 2.000000 10.000000 1.000000
	//         0.000000 1.000000 2.000000 3.000000
	DeleteNode(&head, 0); // Delete in the middle of the list.
	DisplayList(head);
	DeleteNode(&head, 4); // Delete at the front of the list.
	DisplayList(head);
	DeleteNode(&head, 4); // Delete at the end of the list.
	DisplayList(head);

	DestroyList(head);
	head = NULL;

	return 0;
}
