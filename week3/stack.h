/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_3
 * Stack
 */

#include <stdbool.h>

/* struct for stack */
typedef struct Stack_str {
	/* the size of stack */
	int size;
	/* top index, empty is -1 */
	int top;
	/* data */
	double *data;
} Stack;

/* create an stack with size */
bool CreateStack(Stack *stack, int size);

/* check a stack whether it contains data */
bool IsEmpty(Stack *stack);

/* check full of stack */
bool IsFull(Stack *stack);

/* get the top value of a stack */
bool Top(Stack *stack, double *x);

/* add a value to stack */
bool Push(Stack *stack, double x);

/* delete a value from stack */
bool Pop(Stack *stack, double *x);

/* print the stack */
void DisplayStack(Stack *stack);

/* delete a stack */
void DestroyStack(Stack *stack);
