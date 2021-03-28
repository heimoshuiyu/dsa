/* author: Walter
 * Student_ID: 1930006025
 * Assignment_problem_1
 * This is a test unit file contain some test function and a main function to run it
 */

#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void test_inverse_empty_list();
void test_inverse_one_list();
void test_inverst_list();
void test_remove_duplicate();

int main() {
	test_inverse_empty_list();
	test_inverse_one_list();
	test_inverst_list();
	test_remove_duplicate();
}

void test_inverse_empty_list() {
	Node *head = NULL;
	printf("test_inverse_empty_list(): except 2 empty line:\n");
	DisplayList(head);
	InverstNode(&head);
	DisplayList(head);
}

void test_inverse_one_list() {
	Node *head = NULL;
	printf("test_inverse_one_list(): except two same node:\n");
	InsertNode(&head, 0, 39.0);
	DisplayList(head);
	InverstNode(&head);
	DisplayList(head);
	DestroyList(head);
	head = NULL;
}

void test_inverst_list() {
	Node *head = NULL;
	printf("test_inverst_list(): except inverse list:\n");
	for (int i=39; i<45; i++) {
		InsertNode(&head, 0, (double)i);
	}
	DisplayList(head);
	InverstNode(&head);
	DisplayList(head);
	DestroyList(head);
	head = NULL;
}

/* four test cases from pdf */
void test_remove_duplicate() {
	Node *head = NULL;

	printf("test_remove_duplicate(): except 1.0   4.0:\n");
	InsertNode(&head, 0, 1.0);
	InsertNode(&head, 1, 2.0);
	InsertNode(&head, 2, 2.0);
	InsertNode(&head, 3, 4.0);
	InsertNode(&head, 4, 6.0);
	InsertNode(&head, 5, 6.0);
	DisplayList(head);
	RemoveDuplicates(&head);
	DisplayList(head);
	DestroyList(head);
	head = NULL;

	printf("test_remove_duplicate(): except two empty line:\n");
	head = NULL;
	DisplayList(head);
	RemoveDuplicates(&head);
	DisplayList(head);
	DestroyList(head);
	head = NULL;

	printf("test_remove_duplicate(): except empty line in result:\n");
	head = NULL;
	InsertNode(&head, 0, 6.0);
	InsertNode(&head, 1, 6.0);
	InsertNode(&head, 2, 6.0);
	InsertNode(&head, 3, 7.0);
	InsertNode(&head, 4, 7.0);
	DisplayList(head);
	RemoveDuplicates(&head);
	DisplayList(head);
	DestroyList(head);
	head = NULL;
	
	printf("test_remove_duplicate(): except 6.0   7.0:\n");
	head = NULL;
	InsertNode(&head, 0, 6.0);
	InsertNode(&head, 1, 7.0);
	DisplayList(head);
	RemoveDuplicates(&head);
	DisplayList(head);
	DestroyList(head);
	head = NULL;
	return;
}


/* old test function
// Testing all the functions:
int main(void) {
	Node *head = NULL;

	// Output: true
	printf("%s\n", IsEmpty(head) ? "true" : "false");

	// Must output an empty line:
	DisplayList(head);

	// Must output "insert failed":
	Node *result = InsertNode(&head, 20, 7);
	printf("%s\n", result == NULL ? "insert failed" : "insert succeeded");

	// Output: 0.000000 1.000000 2.000000 3.000000 4.000000
	for (int i = 0; i < 5; i++) {
		InsertNode(&head, i, i);
	}
	DisplayList(head);

	// Output: false
	printf("%s\n", IsEmpty(head) ? "true" : "false");

	// Output: 4.000000 3.000000 2.000000 1.000000 0.000000
	// 0.000000 1.000000 2.000000 3.000000 4.000000
	for (int i = 0; i < 5; i++) {
		InsertNode(&head, 0, i);
	}
	DisplayList(head);

	// Output: 0.000000 is at position 5
	//         2.000000 is at position 3
	//         4.000000 is at position 1
	//         6.000000 is not in the list
	for (int i = 0; i < 7; i += 2) {
		int idx = FindNode(head, i);
		if (idx > 0) {
			printf("%f is at position %d\n", (double)i, idx);
		} else {
			printf("%f is not in the list\n", (double)i);
		}
	}

	// Output: inserted 10.000000
	//         4.000000 3.000000 2.000000 10.000000 1.000000 0.000000
	//         0.000000 1.000000 2.000000 3.000000 4.000000
	Node *in = InsertNode(&head, 3, 10);
	printf("inserted %f\n", in->data);
	DisplayList(head);

	// Output: 4.000000 3.000000 2.000000 10.000000 1.000000
	// 0.000000 1.000000 2.000000 3.000000 4.000000
	//         3.000000 2.000000 10.000000 1.000000
	//         0.000000 1.000000 2.000000 3.000000 4.000000
	//         3.000000 2.000000 10.000000 1.000000
	//         0.000000 1.000000 2.000000 3.000000
	DeleteNode(&head, 0); // Delete in the middle of the list.
	DisplayList(head);
	DeleteNode(&head, 4); // Delete at the front of the list.
	DisplayList(head);
	DeleteNode(&head, 4); // Delete at the end of the list.
	DisplayList(head);

	printf("Reverse List ...\n");
	InverstNode(&head);
	DisplayList(head);

	DestroyList(head);
	head = NULL;

	return 0;
}
*/
