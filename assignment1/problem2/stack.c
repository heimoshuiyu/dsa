/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_problem_2
 * stack lib, allow to create empty stack
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <assert.h>

#include "stack.h"

bool CreateStack(Stack *stack, int size) {
	/* check, allow create empty stack */
	assert(size >= 0);

	/* memory allocate */
	stack->data = (char *)malloc(sizeof(char) * size);
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
	/* if full, stack->top = stack->size */
	return stack->top >= stack->size;
}

bool Top(Stack *stack, char *x) {
	/* check empty */
	if (IsEmpty(stack)) {
		return false;
	}

	/* get top */
	*x = stack->data[stack->top];

	return true;
}

bool Push(Stack *stack, char x) {
	/* check */
	if (IsFull(stack)) {
		return false;
	}

	/* push */
	stack->data[++stack->top] = x;

	return true;
}

bool Pop(Stack *stack, char *x) {
	/* check */
	if (IsEmpty(stack)) {
		return false;
	}

	/* get x, and top - 1 */
	*x = stack->data[stack->top--];
	return true;
}

void DisplayStack(Stack *stack) {
	char *top_p = stack->data + stack->top;

	/* print the top pointer hint */
	printf("top --> ");
	
	/* loop for stack data */
	for (; top_p >= stack->data; top_p--) {

		/* print top --> hint */
		if (top_p != stack->data + stack->top) {
			printf("        ");
		}

		printf("|  %c  |\n", *top_p);
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
