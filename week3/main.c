#include <stdio.h>
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
