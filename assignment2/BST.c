/*
 * Author: Walter
 * Student ID: 1930006025
 * programming_assignment_2
 */

#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

Node *insertNode(Node **proot, int x) {
	Node **tmpNode;

	/* find the position needs to be insert */
	tmpNode = proot;
	while (*tmpNode) {
		if (x < (*tmpNode)->key) {
			tmpNode = &(*tmpNode)->left;
		} else if (x > (*tmpNode)->key) {
			tmpNode = &(*tmpNode)->right;
		} else {
			/* same key exists */
			return NULL;
		}
	}

	/* create node */
	*tmpNode = (Node *)malloc(sizeof(Node));
	if (tmpNode == NULL) {
		fprintf(stderr, "Can not allocate new space for node\n");
		exit(1);
	}

	/* copy value */
	(*tmpNode)->key = x;
	(*tmpNode)->left = (*tmpNode)->right = NULL;

	return *tmpNode;
}

Node *findNode(Node *root, int x) {
	while (root) {
		/* find in children */
		if (x < root->key) {
			root = root->left;
		} else if (x > root->key) {
			root = root->right;
		} else {
			/* equal */
			return root;
		}
	}

	/* not found */
	return NULL;
}

Node *deleteNode(Node **proot, int x) {
	Node **rMin, **delNode, *freeNode;

	/* find the node needs to be delete */
	delNode = proot;
	while (*delNode) {
		if (x < (*delNode)->key) {
			delNode = &(*delNode)->left;
		} else if (x > (*delNode)->key) {
			delNode = &(*delNode)->right;
		} else {
			/* found */
			break;
		}
	}
	/* check not found */
	if (!(*delNode)) {
		return NULL;
	}

	if ((*delNode)->left && (*delNode)->right) {
		/* two children, find the right min and replace */
		rMin = &((*delNode)->right);
		while ((*rMin)->left) {
			rMin = &(*rMin)->left;
		}

		/* replace */
		(*delNode)->key = (*rMin)->key;

		/* now let's delete rMin */
		delNode = rMin;
	}

	/* delete delNode, freeNode is the one needs to be free,
	 * here delNode will not have two children */
	freeNode = *delNode;
	if ((*delNode)->left) {
		*delNode = (*delNode)->left;
	} else if ((*delNode)->right) {
		*delNode = (*delNode)->right;
	} else {
		/* no child */
		*delNode = NULL;
	}

	return freeNode;
}

void destroyTree(Node *root) {
	/* end situation */
	if (root == NULL) {
		return;
	}
	destroyTree(root->left);
	destroyTree(root->right);
	free(root);
	return;
}
