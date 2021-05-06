/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_Problem_3
 * uncompress using AST method
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "uncompress.h"

ASTScanner *CreateASTScanner(char *string) {
	/* Special case define in pdf */
	if (string == NULL) {
		string = "NULL";
	}

	/* allocate scanner memory space */
	ASTScanner *scanner = (ASTScanner *)malloc(sizeof(ASTScanner));
	if (scanner == NULL) {
		fprintf(stderr, "allocate scanner memory failed\n");
		exit(1);
	}

	/* init values */
	scanner->string = string;
	scanner->length = strlen(string);
	scanner->current_index = 0;

	return scanner;
}

char ASTScan(ASTScanner *scanner, ASTNode **ret_node) {
	size_t i;

	/* return if it reached the end */
	if (scanner->current_index == scanner->length) {
		*ret_node = NULL;
		return 0;
	}

	/* allocate memory space */
	ASTNode *node = (ASTNode *)calloc(1, sizeof(ASTNode));
	if (node == NULL) {
		fprintf(stderr, "allocate ASTNode memory failed\n");
		exit(1);
	}

	/* read until end or '(' or ')',
	 * after the loop, i point after '(' or ')' */
	i = scanner->current_index;
	while (i < scanner->length) {
		if (scanner->string[i] == '(' || scanner->string[i] == ')') {
			i++;
			break;
		}
		i++;
	}

	/* if read ( */
	if (scanner->string[i - 1] == '(') {
		node->type = 2;

		/* check is there is any number before ( */
		if (i - 1 == 0) {
			fprintf(stderr, "Syntax error: invailed value of repeat at begining\n");
			return 1;
		}
		if (!IsNumber(scanner->string[i - 2])) {
			fprintf(stderr, "Syntax error: invailed value of repeat at index %ld\n",
					i - 1);
			return 1;
		}

		/* get number and the string before the number */
		node->repeat = GetNumber(scanner->string, scanner->current_index, i - 1,
				&node->string);
		/* if the string exists */
		if (node->string.string) {
			/* change type to 1 */
			node->type = 1;
			node->repeat = 0;
			i = node->string.end;
		}

		/* if read ) */
	} else if (scanner->string[i - 1] == ')') {
		node->type = 3;

		/* if there are string before ) */
		if (i - 1 != scanner->current_index) {

			/* change type to 1 */
			node->type = 1;
			node->string.string = scanner->string;
			node->string.start = scanner->current_index;
			node->string.end = i - 1;
			i = i - 1;
		}

		/* until the end is a string */
	} else {
		node->type = 1;
		node->string.string = scanner->string;
		node->string.start = scanner->current_index;
		node->string.end = i;
	}

	/* set current_index */
	scanner->current_index = i;

	/* set return node */
	*ret_node = node;

	return 0;
}

unsigned int GetNumber(char *string, size_t start, size_t end,
		ASTString *other_string) {
	unsigned int result = 0;
	size_t index = end - 1;

	/* convert string to integer */
	for (unsigned count = 1; IsNumber(string[index]); index--, count++) {
		result = result + (string[index] - '0') * Power(10, count);
	}

	/* if there is a string before the number,
	 * set to other_string */
	if (index + 1 != start) {
		other_string->string = string;
		other_string->start = start;
		other_string->end = index + 1;
	}

	return result;
}

bool IsNumber(const char c) { return c >= '0' && c <= '9'; }

unsigned int Power(int x, int y) {
	unsigned int result = 1;
	for (int i = 1; i < y; i++) {
		result = result * x;
	}
	return result;
}

void DEBUG_NODE(ASTNode *root) {
	ASTNode *currNode = root;
	while (currNode) {
		printf("[%p] type: %d, next: %p, child: %p, repeat: %d, string: %ld-%ld\n",
				currNode, currNode->type, currNode->next, currNode->child,
				currNode->repeat, currNode->string.start, currNode->string.end);

		if (currNode->type == 2) {
			/* recursion to child */
			DEBUG_NODE(currNode->child);
		}

		/* move forward */
		currNode = currNode->next;
	}
}

void DestroyASTTree(ASTTree *tree) {
	ASTNode *currNode, *delNode;

	/* push root node into stack */
	Push(&tree->stack, tree->root);

	/* loop to destroy all node */
	while (!IsEmpty(&tree->stack)) {

		/* get node from stack */
		Pop(&tree->stack, &currNode);

		while (currNode) {

			if (currNode->type == 2) {
				/* store child node into stack */
				Push(&tree->stack, currNode->child);
			}

			/* delete node */
			delNode = currNode;
			currNode = currNode->next;
			free(delNode);
		}
	}

	/* finally do not forget to free everything */
	DestroyStack(&tree->stack);
	free(tree);
}

ASTTree *CreateASTTree() {
	/* allocate memory */
	ASTTree *tree = (ASTTree *)calloc(1, sizeof(ASTTree));
	if (tree == NULL) {
		fprintf(stderr, "Can not allocate AST Tree memory\n");
		exit(1);
	}

	/* create stack with tree */
	CreateStack(&tree->stack, DEFAULT_STACK_SIZE);

	return tree;
}

void ASTCompileTree(ASTTree *tree, FILE *file) {

	ASTCompileNode(tree->root, file);

	/* new line at the end */
	//fputc('\n', file);
}

void ASTCompileNode(ASTNode *root, FILE *file) {
	ASTNode *currNode = root;

	/* loop for node and its all next node */
	for (; currNode; currNode = currNode->next) {

		if (currNode->type == 2) {
			/* repeat to compile child node */
			for (unsigned int i = 0; i < currNode->repeat; i++) {
				/* recursion */
				ASTCompileNode(currNode->child, file);
			}

		} else if (currNode->type == 1) {
			/* print string */
			for (size_t i = currNode->string.start; i < currNode->string.end; i++) {
				fputc(currNode->string.string[i], file);
			}
		}
	}
}

char ASTScanAll(ASTTree *tree, ASTScanner *scanner) {
	bool goback = false;
	char err;
	ASTNode *node = NULL, *last = NULL;

	/* scan the first (root) node */
	ASTScan(scanner, &node);
	tree->root = node;
	tree->max++;
	last = tree->root;

	/* set last node as last type 2 node */
	if (node != NULL) {
		if (node->type == 2) {
			Push(&tree->stack, node);
		}
	}

	/* scan until end */
	while (err = ASTScan(scanner, &node), node) {

		/* raise error */
		if (err != 0) {
			return err;
		}

		/* set goback flag, set last node as last type 2 node */
		if (node->type == 3) {
			goback = true;
			Pop(&tree->stack, &last);
			free(node);
			continue;
			/* uf node type is 2, record in stack */
		} else if (node->type == 2) {
			Push(&tree->stack, node);
		}

		/* connect to last node */
		if (last->type == 1) {
			last->next = node;
		} else if (last->type == 2) {
			if (goback) {
				last->next = node;
				goback = false;
			} else {
				last->child = node;
			}
		}

		/* record last node, increase max */
		last = node;
		tree->max++;
	}
	return 0;
}

char* Uncompress(char *string) {
	char *result = (char *)calloc(10000, sizeof(char));
	char *ret = (char *)calloc(10000, sizeof(char));
	FILE *file = fmemopen(result, 10000, "w");
	char err;

	/* create scanner and AST tree */
	ASTScanner *scanner = CreateASTScanner(string);
	ASTTree *tree = CreateASTTree();

	/* scan all token into tree */
	err = ASTScanAll(tree, scanner);
	if (err != 0) {
		fprintf(stderr, "EXITED");
		exit(1);
	}

	/*
	   printf("---debug---\n");
	   DEBUG_NODE(tree->root);
	   printf("---debug---\n");
	   */

	/* compile */
	ASTCompileTree(tree, file);

	/* free memory */
	DestroyASTTree(tree);
	DestroyASTScanner(scanner);

	fclose(file);
	file = fmemopen(result, strlen(result), "r");
	char ch;
	int i=0;
	while((ch = fgetc(file)) != EOF) {
		ret[i++] = ch;
	}
	ret[i] = 0;

	return result;
}

void DestroyASTScanner(ASTScanner *scanner) { free(scanner); }
