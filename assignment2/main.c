#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

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

	printf("\nAfter inserting 2, 6, 12, 14:\n");
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

	printf("\nAfter deleting 12 (which has no children):\n");
	free(deleteNode(&root, 12));
	printTree(root);

	printf("\nAfter deleting 13 (which has a right child):\n");
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
	return 0;
}
