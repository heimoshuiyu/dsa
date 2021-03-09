#include <stdbool.h>

typedef struct node {
	double data;
	struct node *next;
} Node;

/* function: tests whether a list is empty
input: head: pointer to the first node
output: true if the list is empty and false otherwise
*/
bool IsEmpty(Node *head);

/* function: inserts a new node with certain data after a certain position
input: phead: pointer to the pointer to the first node
index: the new node is inserted after position index
insert a new node as the head if index is 0
x: data of the new node
output: a pointer to the new node if insertion is successful, NULL otherwise
*/
Node *InsertNode(Node **phead, int index, double x);

/* function: finds node with certain data
input: head: pointer to the first node
x: the first node whose data = x is returned
output: returns the position of the first node whose data = x
returns 0 if no such node exists
*/
int FindNode(Node *head, double x);

/* function: deletes a node with certain data
input: phead: pointer to the pointer to the first node
x: the first node whose data = x is deleted
output: returns the position of the deleted node
returns 0 if no such node exists
*/
int DeleteNode(Node **phead, double x);

/* function: prints all the nodes in the list
input: head: pointer to the first node
*/
void DisplayList(Node *head);

/* function: deletes all the nodes in the list and frees their memory
input: head: pointer to the first node
*/
void DestroyList(Node *head);
