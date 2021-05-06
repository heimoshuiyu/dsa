/*
 * Author: Walter
 * Student ID: 1930006025
 * Assignment_1_Problem_3
 *
 * AST (Abstract Syntax Tree) is a tree representation of the abstract
 * syntactic structure of source code written in a programming language.
 * Each node of the tree denotes a construct occurring in the source code.
 *
 * First of all, ASTScanner can scan the source code with LL(1) parser,
 * return a token (ASTNode) of source code, there are 3 types of token.
 * 1: string
 * 2: loop start with repeat times
 * 3: end loop
 *
 * Then ASTScanAll() can take all token into tree.
 *
 * For example:
 * source code start3(miku6(aaa)asdf)end will generate the following tree:
 *
 * "start" -> 3 -> "end"
 *            |
 *            -> "miku" -> 6 -> "asdf"
 *                         |
 *                         -> "aaa" 
 *
 * ASTCompileTree() can compile the tree into output.
 */

#ifndef UNCOMPRESS
#define UNCOMPRESS

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "struct.h"

/* return a pointer of a new scanner, string will not be copied */
ASTScanner *CreateASTScanner(char *string);

/* return a pointer of a new Tree */
ASTTree *CreateASTTree();

/* return a pointer of a token, return NULL if reached the end */
char ASTScan(ASTScanner *scanner, ASTNode **ret_node);

/* scan all token from scanner into tree */
char ASTScanAll(ASTTree *tree, ASTScanner *scanner);

/* return the number before a string with index */
unsigned int GetNumber(char *string, size_t start, size_t end,
		ASTString *other_string);

/* Useful function to check whether a char is a number */
bool IsNumber(const char c);

/* math calc, Power(10, 4) return 10000 */
unsigned int Power(int x, int y);

/* destroy AST scanner, memory of string will not be free */
void DestroyASTScanner(ASTScanner *scanner);

/* Destroy AST Tree */
void DestroyASTTree(ASTTree *tree);

/* Display debug information to screen from root node */
void DEBUG_NODE(ASTNode *root);

/* Compile the tree to file stream */
void ASTCompileTree(ASTTree *tree, FILE *file);

/* Compile node and its all next node to file stream */
void ASTCompileNode(ASTNode *root, FILE *file);

/* A short cut function, directly uncompress the raw string to file stream */
char* Uncompress(char *string);

#endif
