#include "AVL.h"
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int getHeight(Node *node) {
	int x, y;

	if (node == NULL) {
		return -1;
	}

	x = getHeight(node->left);
	y = getHeight(node->right);

	return x >= y ? x + 1 : y + 1;
}

int getBalance(Node *node) {
       return getHeight(node->left) - getHeight(node->right);
}

Node *findNode(Node *root, int x) {
	if (root == NULL) {
		return NULL;
	}

	if (root->key == x) {
		return root;
	}

	return x < root->key ? findNode(root->left, x) : findNode(root->right, x);
}

Node *rightRotate(Node *node) {
	Node *left = node->left;
	Node *right = left->right;

	left->right = node;
	node->left = right;

	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

	return left;
}

Node *leftRotate(Node *node) {
	Node *right = node->right;
	Node *left = right->left;

	right->left = node;
	node->right = left;

	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
	right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

	return right;
}

Node *minNode(Node *node) {
	while (node->left) {
		node = node->left;
	}
	return node;
}

Node *insertNode(Node **root, int x) {
	Node *ret;

	/* insert the data */
	if (*root == NULL) {
		*root = (Node *)malloc(sizeof(Node));
		if (*root == NULL) {
			printf("Can't allocate memory");
			exit(1);
		}
		(*root)->key = x;
		(*root)->height = 0;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return *root;
	} else if ((*root)->key > x) {
		ret = insertNode(&(*root)->left, x);
	} else if ((*root)->key < x) {
		ret = insertNode(&(*root)->right, x);
	}

	/* handle the unbalance problem */
	(*root)->height =
		1 + max(getHeight((*root)->left), getHeight((*root)->right));

	int balance = getBalance(*root);

	/* case 1 left left unbalance */
	if (balance > 1 && getBalance((*root)->left) >= 0) {
		*root = rightRotate(*root);
	}

	/* case 2 left right unbalance */
	if (balance > 1 && getBalance((*root)->left) < 0) {
		(*root)->left = leftRotate((*root)->left);
		*root = rightRotate(*root);
	}

	/* case 3 right left unbalance */
	if (balance < -1 && getBalance((*root)->right) > 0) {
		(*root)->right = rightRotate((*root)->right);
		*root = leftRotate(*root);
	}

	/* case 4 right right unbalance */
	if (balance < -1 && getBalance((*root)->right) <= 0) {
		*root = leftRotate(*root);
	}

	return ret;
}

Node *deleteNode(Node **root, int x) {
	Node *tmp = *root;

	if (*root == NULL)
		return NULL;

	if (x < (*root)->key) {
		tmp = deleteNode(&(*root)->left, x);
	} else if (x > (*root)->key) {
		tmp = deleteNode(&(*root)->right, x);
	} else {
		if ((*root)->left == NULL || (*root)->right == NULL) {
			Node *child = (*root)->left != NULL ? (*root)->left : (*root)->right;

			/* no child case */
			if (child == NULL) {
				*root = NULL;
				return tmp;
			} else {
				(*root)->key = child->key;
				if ((*root)->left &&
						/* left child case */
						(*root)->left->key == child->key) {
					tmp = deleteNode(&(*root)->left, child->key);
				} else if ((*root)->right &&
						/* right child case */
						(*root)->right->key == child->key) {
					tmp = deleteNode(&(*root)->right, child->key);
				}
			}
		/* two child case */
		} else {
			Node *child = minNode((*root)->right);
			(*root)->key = child->key;
			tmp = deleteNode(&(*root)->right, child->key);
		}
	}

	if ((*root) == NULL) {
		return *root;
	}

	int balance = getBalance(*root);

	(*root)->height =
		1 + max(getHeight((*root)->left), getHeight((*root)->right));

	/* case 1 left left unbalance */
	if (balance > 1 && getBalance((*root)->left) >= 0) {
		*root = rightRotate(*root);
	}

	/* case 2 left right unbalance */
	if (balance > 1 && getBalance((*root)->left) < 0) {
		(*root)->left = leftRotate((*root)->left);
		*root = rightRotate(*root);
	}

	/* case 3 right left unbalance */
	if (balance < -1 && getBalance((*root)->right) > 0) {
		(*root)->right = rightRotate((*root)->right);
		*root = leftRotate(*root);
	}

	/* case 4 right right unbalance */
	if (balance < -1 && getBalance((*root)->right) <= 0) {
		*root = leftRotate(*root);
	}

	return tmp;
}

void destroyTree(Node *root) {
	if (root == NULL) {
		return;
	}

	destroyTree(root->left);
	destroyTree(root->right);

	free(root);
}
