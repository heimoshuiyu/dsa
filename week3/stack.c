#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <assert.h>

#include "stack.h"

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
	assert(size > 0);

	stack->data = (double *)malloc(sizeof(double) * size);
	if (stack->data == NULL) {
		return false;
	}

	stack->top = -1;
	stack->size = size;

	return true;
}

bool IsEmpty(Stack *stack) {
	return stack->top < 0;
}

bool IsFull(Stack *stack) {
	return stack->top >= stack->size;
}

bool Top(Stack *stack, double *x) {
	if (IsEmpty(stack)) {
		return false;
	}
	*x = stack->data[stack->top];
	return true;
}

bool Push(Stack *stack, double x) {
	if (IsFull(stack)) {
		return false;
	}
	stack->data[++stack->top] = x;
	return true;
}

bool Pop(Stack *stack, double *x) {
	if (IsEmpty(stack)) {
		return false;
	}
	*x = stack->data[stack->top--];
	return true;
}

void DisplayStack(Stack *stack) {
	double *top_p = stack->data + stack->top;

	printf("top --> ");
	
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
}
