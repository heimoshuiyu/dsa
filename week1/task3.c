/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_1_Task_3
 * Read in and compute the greatest common divisor (GCD) of
 * two natural numbers using recursion
 */

#include <stdio.h>
#include <assert.h>

int GCD(int x, int y);

/* the real GCD function */
int _GCD(int x, int y);

int main() {
	int x, y;
	printf("Please input x\n");
	scanf("%d", &x);
	printf("Please input y\n");
	scanf("%d", &y);
	printf("Result is %d\n", GCD(x, y));
	return 0;
}

int GCD(int x, int y) {
	/* check x y are natural numbers */
	assert(x >= 0);
	assert(y >= 0);

	/* make sure x >= y,
	 * then call the read GCD function */
	if (x >= y) {
		return _GCD(x, y);
	} else {
		return _GCD(y, x);
	}
}

int _GCD(int x, int y) {
	/* end of recursion */
	if (y == 0) {
		return x;
	}

	return _GCD(y, x % y);
}
