/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_problem_2
 * validbrackets function
 */

#include <stddef.h>
#include <string.h>

#include "stack.h"
#include "validbrackets.h"

/* all the left brackets */
static char LEFTBRACKETS[]  = "({[<";

/* all the right brackets */
static char RIGHTBRACKETS[] = ")}]>";

/* number of brackets pairs */
static int BRACKETS_LEN = 4;

bool ValidBrackets(char *str) {

	/* if string pass all the test, will return default value 'true' */
	bool result = true;

	/* null pointer will return false */
	if (str == NULL) {
		return false;
	}
	
	/* tmp value to store the left brackets */
	char left;
	
	/* length of string */
	size_t str_len = strlen(str);

	Stack stack;
	/* only half length of the string is enougth,
	 * empty stack is allowed */
	CreateStack(&stack, str_len/2);

	/* loop for all char in string */
	for (size_t i=0; i<str_len; i++) {

		/* full stack means the string is not vailed */
		if (IsFull(&stack)) {
			result = false;
			break;
		}

		/* if it is not left brackets will return -1 */
		if (IndexLeftBracket(str[i]) != -1) {
			/* store the left brackets in stack */
			Push(&stack, str[i]);
		} else {
			/* check empty stack before pop from stack */
			if (IsEmpty(&stack)) {
				result = false;
				break;
			}
			/* get the pair left brackets from stack */
			Pop(&stack, &left);

			/* check if the left and right brackets matched */
			if (!MatchBracket(left, str[i])) {
				result = false;
				break;
			}
		}
	}
	/* if finally the stack is not empty, return falsle */
	if (!(IsEmpty(&stack))) {
		result = false;
	}
	/* no memory leak */
	DestroyStack(&stack);

	return result;
}

int IndexLeftBracket(char c) {
	for (int i=0; i<BRACKETS_LEN; i++) {
		if (c == LEFTBRACKETS[i]) {
			return i;
		}
	}
	/* if c is not left brackets, return -1 */
	return -1;
}

int IndexRightBracket(char c) {
	for (int i=0; i<BRACKETS_LEN; i++) {
		if (c == RIGHTBRACKETS[i]) {
			return i;
		}
	}
	/* if c is not right brackets, return -1 */
	return -1;
}

bool MatchBracket(char left, char right) {
	/* check whether left and right brackets are matched */
	return IndexLeftBracket(left) == IndexRightBracket(right);
}
