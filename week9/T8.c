/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_9_task_8
 * HeapSort
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "T8.h"

int main() {
	int size = 5000000;
	clock_t start_time, end_time;

	int *A1 = (int *)malloc(sizeof(int) * size);
	if (A1 == NULL) {
		printf("Fatal: Can not allocate memory of A1 with size=%d\n", size);
		exit(1);
	}

	int *A2 = (int *)malloc(sizeof(int) * size);
	if (A2 == NULL) {
		printf("Fatal: Can not allocate memory of A2 with size=%d\n", size);
		exit(1);
	}

	/* generate random number */
	for (int i = 0; i < size; i++) {
		A1[i] = A2[i] = rand();
	}

	printf("Testing HeapSort function ... ");
	start_time = clock();
	HeapSort(A1, size);
	end_time = clock();
	printf("%s\n", Check(A1, size) ? "pass" : "failed");
	PrintTimeDuration(start_time, end_time);

	printf("Testing QuickSort function ... ");
	start_time = clock();
	QuickSort(A2, 0, size - 1);
	end_time = clock();
	printf("%s\n", Check(A1, size) ? "pass" : "failed");
	PrintTimeDuration(start_time, end_time);

	return 0;
}

bool Check(int *A, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (A[i] > A[i + 1]) {
			return false;
		}
	}
	return true;
}

void QuickSort(int *A, int left, int right) {
	int i, j;
	int pivot;

	if (left >= right) {
		return;
	}

	pivot = Median3(A, left, right);
	i = left;
	j = right - 1;

	while (1) {
		while (A[++i] < pivot) {
		}
		while (A[--j] > pivot) {
		}
		if (i >= j) {
			break;
		}
		Swap(&A[i], &A[right - 1]);
	}
	Swap(&A[i], &A[right - 1]);

	QuickSort(A, left, i - 1);
	QuickSort(A, i + 1, right);
}

int Median3(int *A, int left, int right) {
	int center = (left + right) / 2;

	if (A[left] > A[center]) {
		Swap(&A[left], &A[center]);
	}
	if (A[left] > A[right]) {
		Swap(&A[left], &A[right]);
	}
	if (A[center] > A[right]) {
		Swap(&A[center], &A[right]);
	}

	Swap(&A[center], &A[right - 1]);
	return A[right - 1];
}

void HeapSort(int *A, int n) {
	int i;
	for (i = n / 2; i >= 0; i--) {
		PercDown(A, i, n);
	}
	for (i = n - 1; i > 0; i--) {
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}

void PercDown(int *A, int i, int n) {
	int child, tmp;

	for (tmp = A[i]; (2 * i + 1) < n; i = child) {
		child = 2 * i + 1;
		if (child != n - 1 && A[child + 1] > A[child]) {
			child++;
		}
		if (tmp < A[child]) {
			A[i] = A[child];
		} else {
			break;
		}
	}
	A[i] = tmp;
}

void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintTimeDuration(clock_t start_time, clock_t end_time) {
	printf("Time cost: %ld ms\n",
			(end_time - start_time) / (CLOCKS_PER_SEC / 1000));
}
