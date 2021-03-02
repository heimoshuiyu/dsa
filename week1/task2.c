/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_1_Task_2
 * Read in and reverse a string using recursion
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverseR(char * str, int length);

int main() {
	char str[50];
	printf("Enter a string: ");
	scanf("%s", str);
	reverseR(str, strlen(str));
	printf("Result: %s\n", str);
	return 0;
}

void reverseR(char *str, int length) {
	/* check */
	assert(length <= 50);
	assert(length >= 0);

	/* end of recursion */
	if (length <= 1) {
		return;
	}

	/* recursion */
	char tmp;
	tmp = str[0];
	str[0] = str[length-1];
	str[length-1] = tmp;

	/* str move forward, length decrese 2 char */
	reverseR(str+1, length-2);
}
