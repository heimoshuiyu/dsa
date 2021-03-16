/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_3
 * Stack
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <assert.h>

#include "stack.h"

/* test function */
int main() {
	Stack stack;
	double val;
	CreateStack(&stack, 5);
	Push(&stack, 5.0);
	Push(&stack, 6.5);
	Push(&stack, -3.0);
	Push(&stack, -8.0);
	DisplayStack(&stack);
	if (Top(&stack, &val)) {
		printf("Top: %f\n", val);
	}
	Pop(&stack, &val);
	if (Top(&stack, &val)) {
		printf("Top: %f\n", val);
	}
	while(!IsEmpty(&stack)) {
		Pop(&stack, &val);
	}
	DisplayStack(&stack);
	DestroyStack(&stack);
	return 0;
}

bool CreateStack(Stack *stack, int size) {
	/* check */
	assert(size > 0);

	/* memory allocate */
	stack->data = (double *)malloc(sizeof(double) * size);
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

bool Top(Stack *stack, double *x) {
	/* check empty */
	if (IsEmpty(stack)) {
		return false;
	}

	/* get top */
	*x = stack->data[stack->top];

	return true;
}

bool Push(Stack *stack, double x) {
	/* check */
	if (IsFull(stack)) {
		return false;
	}

	/* push */
	stack->data[++stack->top] = x;

	return true;
}

bool Pop(Stack *stack, double *x) {
	/* check */
	if (IsEmpty(stack)) {
		return false;
	}

	/* get x, and top - 1 */
	*x = stack->data[stack->top--];
	return true;
}

void DisplayStack(Stack *stack) {
	double *top_p = stack->data + stack->top;

	/* print the top pointer hint */
	printf("top --> ");
	
	/* loop for stack data */
	for (; top_p >= stack->data; top_p--) {

		/* print top --> hint */
		if (top_p != stack->data + stack->top) {
			printf("        ");
		}

		printf("|  % .7f  |\n", *top_p);
	}

	/* print top --> hint */
	if (top_p != stack->data + stack->top) {
		printf("        ");
	}

	printf("+--------------+\n");
}

void DestroyStack(Stack *stack) {
	free(stack->data);
	stack->size = 0;
	stack->top = -1;
}
