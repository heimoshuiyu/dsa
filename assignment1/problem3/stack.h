#ifndef MY_STACK_H
#define MY_STACK_H

/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_Problem_3
 * Stack, with functioin automaticlly increase the size
 */

#include <stdbool.h>

#include "struct.h"

#define DEFAULT_STACK_SIZE 16

/* create an stack, size will automaticlly increase */
bool CreateStack(Stack *stack, int size);

/* check a stack whether it contains data */
bool IsEmpty(Stack *stack);

/* check full of stack */
bool IsFull(Stack *stack);

/* get the top value of a stack */
bool Top(Stack *stack, ASTNode **x);

/* add a value to stack */
bool Push(Stack *stack, ASTNode *x);

/* delete a value from stack */
bool Pop(Stack *stack, ASTNode **x);

/* print the stack */
void DisplayStack(Stack *stack);

/* delete a stack */
void DestroyStack(Stack *stack);

#endif
