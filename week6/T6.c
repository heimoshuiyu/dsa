/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_6
 * InsertionSort and MergeSort
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "T6.h"

int main() {
	/* size of test data */
	int size = 100000;

	int *A;
	clock_t start, end;

	printf("Allocating test data space...\n");
	A = (int *)malloc(sizeof(int) * size);
	if (A == NULL) {
		printf("Fatal: can not allocate A space\n");
		exit(1);
	}

	printf("Generating random integer...\n");
	for (int i = 0; i < size; i++) {
		A[i] = rand();
	}

	printf("Testing merge sort...\n");
	start = clock();
	MergeSort(A, 0, size - 1);
	end = clock();
	PrintClockInterval(start, end);

	printf("Checking result... %s\n", Check(A, size) ? "pass" : "fail");

	printf("Generating random integer...\n");
	for (int i = 0; i < size; i++) {
		A[i] = rand();
	}

	printf("Testing insertion sort...\n");
	start = clock();
	InsertionSort(A, size);
	end = clock();
	PrintClockInterval(start, end);

	printf("Checking result... %s\n", Check(A, size) ? "pass" : "fail");

	return 0;
}

bool Check(int *A, int size) {
	if (size == 1) {
		return true;
	}
	for (int i = 0; i < size - 1; i++) {
		if (A[i] > A[i + 1]) {
			/* if found, return immeditily */
			return false;
		}
	}
	return true;
}

void MergeSort(int *A, int left, int right) {
	/* alloce space */
	int *tmp = (int *)malloc(sizeof(int) * (right - left + 1));
	if (tmp == NULL) {
		printf("Fatal: can not allocate space\n");
		exit(1);
	}

	/* real merge function */
	_MergeSort(A, tmp, left, right);

	free(tmp);
}

void _MergeSort(int *A, int *tmp, int left, int right) {
	int center;
	if (left < right) {
		center = (left + right) / 2;
		_MergeSort(A, tmp, left, center);
		_MergeSort(A, tmp, center + 1, right);
		Merge(A, tmp, left, center + 1, right);
	}
}

void Merge(int *A, int *tmp, int lpos, int rpos, int rightEnd) {
	int i, leftEnd, num, tmpPos;

	/* lpos -> leftEnd -> rpos -> rightEnd */
	leftEnd = rpos - 1;
	tmpPos = lpos;
	num = rightEnd - lpos + 1;

	/* main loop */
	while (lpos <= leftEnd && rpos <= rightEnd) {
		if (A[lpos] <= A[rpos]) {
			tmp[tmpPos++] = A[lpos++];
		} else {
			tmp[tmpPos++] = A[rpos++];
		}
	}

	/* copy rest of first half */
	while (lpos <= leftEnd) {
		tmp[tmpPos++] = A[lpos++];
	}
	/* copy rest of second half */
	while (rpos <= rightEnd) {
		tmp[tmpPos++] = A[rpos++];
	}

	/* copy tmp array back */
	for (i = 0; i < num; i++, rightEnd--) {
		A[rightEnd] = tmp[rightEnd];
	}
}

void InsertionSort(int *A, int n) {
	int j, p;

	int tmp;

	/* loop of p from 1 to n */
	for (p = 1; p < n; p++) {

		/* store A[p] */
		tmp = A[p];

		/* loop of j from p to 0 or
		 * until A[j-1] <= A[p] */
		for (j = p; j > 0 && A[j - 1] > tmp; j--) {
			/* move */
			A[j] = A[j - 1];
		}

		/* insert tmp to right position */
		A[j] = tmp;
	}
}

void PrintClockInterval(clock_t start, clock_t end) {
	printf("Time cost is %ld ms\n", (end - start) / (CLOCKS_PER_SEC / 1000));
}
