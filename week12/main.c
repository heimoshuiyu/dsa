#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 16

int main(void) {
	Node *root = NULL;

	printTree(root);

	printf("After inserting 10:\n");
	insertNode(&root, 10);
	printTree(root);

	printf("\nAfter inserting 5:\n");
	insertNode(&root, 5);
	printTree(root);

	printf("\nAfter inserting 15:\n");
	insertNode(&root, 15);
	printTree(root);

	printf("\nAfter inserting 9, 13:\n");
	insertNode(&root, 9);
	insertNode(&root, 13);
	printTree(root);

	printf("\nAfter inserting 2, 6, 12 (single right rotation), 14:\n");
	insertNode(&root, 2);
	insertNode(&root, 6);
	insertNode(&root, 12);
	insertNode(&root, 14);
	printTree(root);

	printf("\nSearching for 10, 6, 13, 14, 1, 3, 11, 16:\n");
	printf(findNode(root, 10)->key == 10 ? "true\n" : "false\n");
	printf(findNode(root, 6)->key == 6 ? "true\n" : "false\n");
	printf(findNode(root, 13)->key == 13 ? "true\n" : "false\n");
	printf(findNode(root, 14)->key == 14 ? "true\n" : "false\n");
	printf(findNode(root, 1) == NULL ? "true\n" : "false\n");
	printf(findNode(root, 3) == NULL ? "true\n" : "false\n");
	printf(findNode(root, 11) == NULL ? "true\n" : "false\n");
	printf(findNode(root, 16) == NULL ? "true\n" : "false\n");

	printf("\nAfter deleting 12 (double right left rotation):\n");
	free(deleteNode(&root, 12));
	printTree(root);

	printf("\nAfter deleting 13 (which has no children):\n");
	free(deleteNode(&root, 13));
	printTree(root);

	printf("\nAfter deleting 9 (which has a left child):\n");
	free(deleteNode(&root, 9));
	printTree(root);

	printf("\nAfter deleting 5 (which has two children):\n");
	free(deleteNode(&root, 5));
	printTree(root);

	printf("\nAfter deleting 10 (which has two children):\n");
	free(deleteNode(&root, 10));
	printTree(root);

	destroyTree(root);

	printf("\n--------------------\nSee slides 16-17, chapter 10, and slides "
			"10-13, chapter 11:\n\n");

	root = NULL;
	int values[SIZE] = {3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
	for (int i = 0; i < SIZE; i++) {
		printf("inserting %d:\n", values[i]);
		insertNode(&root, values[i]);
		printTree(root);
		printf("\n");
	}
	for (int i = 0; i < SIZE; i++) {
		printf("deleting %d:\n", values[i]);
		deleteNode(&root, values[i]);
		printTree(root);
		printf("\n");
	}
	return 0;
}
