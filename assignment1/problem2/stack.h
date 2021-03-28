/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_problem_2
 * allow to create empty stack
 */

#ifndef MY_STACK
#define MY_STACK

#include <stdbool.h>

/* struct for stack */
typedef struct Stack_str {
	/* the size of stack */
	int size;
	/* top index, empty is -1 */
	int top;
	/* data */
	char *data;
} Stack;

/* create an stack with size */
bool CreateStack(Stack *stack, int size);

/* check a stack whether it contains data */
bool IsEmpty(Stack *stack);

/* check full of stack */
bool IsFull(Stack *stack);

/* get the top value of a stack */
bool Top(Stack *stack, char *x);

/* add a value to stack */
bool Push(Stack *stack, char x);

/* delete a value from stack */
bool Pop(Stack *stack, char *x);

/* print the stack */
void DisplayStack(Stack *stack);

/* delete a stack */
void DestroyStack(Stack *stack);

#endif
