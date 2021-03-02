/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_1_Task_1
 * Read in a positive number and compute its factorial using resursion
 */

#include <stdio.h>
#include <assert.h>

long int factR(int n);

int main() {
	int n;
	printf("Enter a positive number to get its factorial\n");
	scanf("%d", &n);
	printf("Result is %ld\n", factR(n));
	return 0;
}

long int factR(int n) {
	/* check */
	assert(n > 0);

	/* end of recursion */
	if (n == 1) {
		return 1;
	}

	return n * factR(n-1);
}
