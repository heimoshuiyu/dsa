/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_problem_2
 * Test function
 */

#include <stdio.h>
#include <stddef.h>

#include "validbrackets.h"

/* test unit */
typedef struct Unit_str {
	char *text;
	bool except;
} Unit;

int main() {

	/* use for converting bool to string */
	static char *BOOL_TEXT[] = {"false", "true"};

	Unit *test;
	static Unit case1 = {"{()<()>}[]", true};
	static Unit case2 = {"(<)>", false};
	static Unit case3 = {"{()}[", false};
	static Unit case4 = {"", true};
	static Unit case5 = {NULL, false};

	static char *HINT = "Test '%s', except: %s, result: %s\n";

	test = &case1; printf(HINT, test->text, BOOL_TEXT[test->except], BOOL_TEXT[ValidBrackets(test->text)]);
	test = &case2; printf(HINT, test->text, BOOL_TEXT[test->except], BOOL_TEXT[ValidBrackets(test->text)]);
	test = &case3; printf(HINT, test->text, BOOL_TEXT[test->except], BOOL_TEXT[ValidBrackets(test->text)]);
	test = &case4; printf(HINT, test->text, BOOL_TEXT[test->except], BOOL_TEXT[ValidBrackets(test->text)]);
	test = &case5; printf(HINT, test->text, BOOL_TEXT[test->except], BOOL_TEXT[ValidBrackets(test->text)]);

	return 0;
}
