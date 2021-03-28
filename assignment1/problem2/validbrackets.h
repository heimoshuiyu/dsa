/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_problem_2
 * validbrackets header files
 */

#ifndef VAILDBRACKETS
#define VAILDBRACKETS

#include <stdbool.h>

#include "stack.h"

/* cvalid a string brackets,
 * return true if empty string,
 * return false if NULL string pointer */
bool ValidBrackets(char *str);

/* get the index number of left bracket,
 * return -1 if c is not a left bracket */
int IndexLeftBracket(char c);

/* get the index number of right breacket,
 * return -1 if c is not a left bracket */
int IndexRightBracket(char c);

/* compare two brackets if they match */
bool MatchBracket(char left, char right);

#endif
