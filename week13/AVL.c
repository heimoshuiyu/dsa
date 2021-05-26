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

int getHeight(Node *N) {
	if (N == NULL)
		return -1;

	int x = getHeight(N->left);
	int y = getHeight(N->right);

	if (x >= y)
		return x + 1;

	return y + 1;
}

int getBalance(Node *N) { return getHeight(N->left) - getHeight(N->right); }

Node *findNode(Node *root, int x) {
	if (root == NULL) {
		return NULL;
	}

	if (root->key == x) {
		return root;
	}

	if (x < root->key) {
		return findNode(root->left, x);
	}

	return findNode(root->right, x);
}

Node *rightRotate(Node *N) {
	Node *N1 = N->left;
	Node *N2 = N1->right;

	N1->right = N;
	N->left = N2;

	N->height = max(getHeight(N->left), getHeight(N->right)) + 1;
	N1->height = max(getHeight(N1->left), getHeight(N1->right)) + 1;

	return N1;
}

Node *leftRotate(Node *N) {
	Node *N1 = N->right;
	Node *N2 = N1->left;

	N1->left = N;
	N->right = N2;

	N->height = max(getHeight(N->left), getHeight(N->right)) + 1;
	N1->height = max(getHeight(N1->left), getHeight(N1->right)) + 1;

	return N1;
}

Node *minNode(Node *N) {
	while (N->left != NULL) {
		N = N->left;
	}
	return N;
}

Node *insertNode(Node **root, int x) {
	Node *ans;

	/* insert the data */
	if (*root == NULL) {
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->key = x;
		temp->height = 0;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
		ans = temp;
		return ans;
	} else if ((*root)->key > x) {
		ans = insertNode(&(*root)->left, x);
	} else if ((*root)->key < x) {
		ans = insertNode(&(*root)->right, x);
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

	return ans;
}

Node *deleteNode(Node **root, int x) {
	Node *temp = *root;

	if (*root == NULL)
		return *root;

	if (x < (*root)->key) {
		temp = deleteNode(&(*root)->left, x);
	}

	else if (x > (*root)->key) {
		temp = deleteNode(&(*root)->right, x);
	}

	else {
		if ((*root)->left == NULL || (*root)->right == NULL) {
			Node *child = (*root)->left != NULL ? (*root)->left : (*root)->right;

			if (child == NULL) { // no child case;
				*root = NULL;
				return temp;
			} else {
				(*root)->key = child->key;
				if ((*root)->left &&
						(*root)->left->key == child->key) { // left child case;
					temp = deleteNode(&(*root)->left, child->key);
				} else if ((*root)->right &&
						(*root)->right->key == child->key) { // right child case;
					temp = deleteNode(&(*root)->right, child->key);
				}
			}
		} else { // two children case;
			Node *child = minNode((*root)->right);
			(*root)->key = child->key;
			temp = deleteNode(&(*root)->right, child->key);
		}
	}

	if ((*root) == NULL)
		return *root;

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

	return temp;
}

void destroyTree(Node *root) {
	if (root == NULL)
		return;

	destroyTree(root->left);
	destroyTree(root->right);

	free(root);
}
