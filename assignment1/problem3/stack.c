/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_Problem_3
 * Stack, with functioin automaticlly increase the size
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>

#include "stack.h"

bool CreateStack(Stack *stack, int size) {
	/* check */
	assert(size > 0);

	/* memory allocate */
	stack->data = (ASTNode **)malloc(sizeof(ASTNode *) * size);
	if (stack->data == NULL) {
		return false;
	}

	/* init attribute */
	stack->top = -1;
	stack->size = size;

	return true;
}

bool IsEmpty(Stack *stack) {
	/* if empty, stack->top = -1 */
	return stack->top < 0;
}

bool IsFull(Stack *stack) {
	/* if full, stack->top = stack->size - 1 */
	return stack->top == stack->size - 1;
}

bool Top(Stack *stack, ASTNode **x) {
	/* check empty */
	if (IsEmpty(stack)) {
		return false;
	}

	/* get top */
	*x = stack->data[stack->top];

	return true;
}

bool Push(Stack *stack, ASTNode *x) {
	/* check, enlarge stack */
	if (IsFull(stack)) {
		Stack newStack;

		/* create new stack, with 2 bigger size */
		CreateStack(&newStack, stack->size * 2);

		/* copy data */
		memcpy(newStack.data, stack->data, stack->size * sizeof(ASTNode *));
		newStack.top = stack->top;

		/* delete old stack */
		DestroyStack(stack);

		/* set new stack */
		*stack = newStack;
	}

	/* push */
	stack->data[++stack->top] = x;

	return true;
}

bool Pop(Stack *stack, ASTNode **x) {
	/* check */
	if (IsEmpty(stack)) {
		return false;
	}

	/* get x, and top - 1 */
	*x = stack->data[stack->top--];
	return true;
}

void DisplayStack(Stack *stack) {
	ASTNode **top_p = stack->data + stack->top;

	/* print the top pointer hint */
	printf("top --> ");

	/* loop for stack data */
	for (; top_p >= stack->data; top_p--) {

		/* print top --> hint */
		if (top_p != stack->data + stack->top) {
			printf("        ");
		}

		printf("|  %p  |\n", top_p);
	}

	/* print top --> hint */
	if (top_p != stack->data + stack->top) {
		printf("        ");
	}

	printf("+--------------+\n");
}

void DestroyStack(Stack *stack) {
	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
	stack->top = -1;
}
