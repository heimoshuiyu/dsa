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
void Uncompress(char *string, FILE *file);

#endif
