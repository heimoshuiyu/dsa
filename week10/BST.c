/*
 * Author: Walter
 * Student ID: 1930006025
 * week_10_BST
 */

#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

Node *insertNode(Node **proot, int x) {
	/* create if empty */
	if ((*proot) == NULL) {
		*proot = (Node *)malloc(sizeof(Node));
		if (*proot == NULL) {
			fprintf(stderr, "Can not allocate new space for node\n");
			exit(1);
		}
		(*proot)->key = x;
		(*proot)->left = (*proot)->right = NULL;
		return *proot;
	}

	if (x < (*proot)->key) {
		return insertNode(&((*proot)->left), x);
	} else if (x > (*proot)->key) {
		return insertNode(&((*proot)->right), x);
	}

	/* equal, do nothing and return NULL,
	 * because insertion is not successful */
	return NULL;
}

Node *findNode(Node *root, int x) {
	/* empty tree */
	if (root == NULL) {
		return NULL;
	}

	if (x < root->key) {
		return findNode(root->left, x);
	} else if (x > root->key) {
		return findNode(root->right, x);
	}

	/* equal */
	return root;
}

Node *deleteNode(Node **proot, int x) {
	Node *tmpNode;

	/* not found */
	if (*proot == NULL) {
		return NULL;
	}

	/* find the node needs to be delete */
	if (x < (*proot)->key) {
		return deleteNode(&((*proot)->left), x);
	} else if (x > (*proot)->key) {
		return deleteNode(&((*proot)->right), x);
	}

	if ((*proot)->left && (*proot)->right) {
		/* two child, find the min on right to replace */
		tmpNode = (*proot)->right;
		while (tmpNode->left) {
			tmpNode = tmpNode->left;
		}
		/* simply replace key value */
		(*proot)->key = tmpNode->key;
		/* delete tmpNode, which has one or zero child */
		return deleteNode(&(*proot)->right, tmpNode->key);
	} else if ((*proot)->left || (*proot)->right) {
		/* one child */
		tmpNode = *proot;
		if ((*proot)->left) {
			*proot = (*proot)->left;
		}
		if ((*proot)->right) {
			*proot = (*proot)->right;
		}
	} else {
		/* no child */
		tmpNode = *proot;
		*proot = NULL;
	}

	return tmpNode;
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
