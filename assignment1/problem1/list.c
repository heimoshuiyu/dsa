/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_problem_1
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
	for (pnode = *phead, position = 2; pnode->next;
			pnode = pnode->next, position++) {
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
	for (pnode = head; pnode; pnode = pnode->next) {
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

void InverstNode(Node **head) {
	/* empty list */
	if (*head == NULL) {
		return;
	}

	/* only one node in list */
	if ((*head)->next == NULL) {
		return;
	}

	/* reverse Node */
	Node *a, *b, *c;
	a = NULL;
	b = *head;
	c = (*head)->next;

	/* when c == NULL, b is the end of linked list */
	while (c) {
		/* reverse node */
		b->next = a;
		/* move a, b, c forward */
		a = b;
		b = c;
		c = c->next;
	}
	/* finanl step */
	b->next = a;
	/* reset head */
	*head = b;
}

void RemoveDuplicates(Node **head) {
	Node *newHead = NULL, *currNode = *head;
	double oldValue;
	int position;

	/* empty list, no need to do anything */
	if ((*head) == NULL) {
		return;
	}

	/* only one node in the list, no need to do anything */
	if ((*head)->next == NULL) {
		return;
	}

	/* loop until currNode point at NULL */
	while (currNode) {
		/* check whether there is any same value node after this node */
		position = FindNode(currNode->next, currNode->data);

		/* position is not 0, means this is the duplicated value */
		if (position) {
			/* record current duplicated value */
			oldValue = currNode->data;

			/* then use a for loop jump pass the duplicated value,
			 * use for loop to check currNode is not NULL
			 * before get currNode->data */
			for (; currNode; currNode=currNode->next) {
				/* exit when we find a new value */
				if (currNode->data != oldValue) {
					break;
				}
			}

			continue;
		}

		/* if this is not a duplicated value,
		 * add unique node to new linked list */
		InsertNode(&newHead, 0, currNode->data);

		/* move to next */
		currNode = currNode->next;
	}

	/* Inverst to original direction */
	InverstNode(&newHead);
	/* reset head, remember to destory old list, avoid memory leak */
	DestroyList(*head);
	*head = newHead;
}
