/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_Problem_3
 * the shared data structure
 */

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

#include <stddef.h>
#include <stdbool.h>


/* Used for AST Node's string */
typedef struct ASTString_str {
	char *string;

	/* the start index */
	size_t start;

	/* the end index */
	size_t end;

} ASTString;

/* AST Node structure, describe in ./README.md */
typedef struct ASTNode_str {

	/* 1: string, 2: left (, 3: right ) */
	char type;

	/* valid when type==2 */
	unsigned int repeat;

	/* valid when type==1 */
	ASTString string;

	/* next node */
	struct ASTNode_str *next;

	/* child node */
	struct ASTNode_str *child;
} ASTNode;

/* struct for stack */
typedef struct Stack_str {
	/* the size of stack */
	int size;
	/* top index, empty is -1 */
	int top;
	/* data */
	ASTNode **data;
} Stack;

/* AST Scanner struct */
typedef struct ASTScanner_str {
	/* pointer to string, string will not be modified */
	char *string;

	size_t length;
	size_t current_index;
} ASTScanner;

/* AST Tree structure */
typedef struct ASTTree_str {
	ASTNode *root;
	ASTNode *currNode;
	Stack stack;
	size_t max;
	size_t count;
} ASTTree;

#endif
