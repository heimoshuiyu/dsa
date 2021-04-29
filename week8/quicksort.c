#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "quicksort.h"

int main() {
	/* size of test data */
	int size_1 = 10;
	int size_2 = 100000;

	int *A1, *A2;
	clock_t start, end;

	printf("Allocating 10 test data space for A1...\n");
	A1 = (int *)malloc(sizeof(int) * size_1);
	if (A1 == NULL) {
		printf("Fatal: can not allocate A1 space\n");
		exit(1);
	}

	printf("Create random integer for A1...\n");
	for (int i = 0; i < size_1; i++) {
		A1[i] = rand();
	}

	printf("Testing quick sort...\n");
	start = clock();
	QuickSort(A1, 0, size_1 - 1);
	end = clock();
	_PrintClockInterval(start, end);

	if (Check(A1, size_1)) {
		printf("Checking result... pass\n");
	} else {
		printf("Checking result... fail\n");
	}

	printf("Freeing space of A1\n");
	free(A1);
	A1 = NULL;

	printf("Allocating 100000 test data space for A2...\n");
	A2 = (int *)malloc(sizeof(int) * size_2);
	if (A2 == NULL) {
		printf("Fatal: can not allocate A1 space\n");
		exit(1);
	}

	printf("Create random integer for A2...\n");
	for (int i = 0; i < size_2; i++) {
		A2[i] = rand();
	}

	printf("Testing merge sort...\n");
	start = clock();
	QuickSort(A2, 0, size_2 - 1);
	end = clock();
	PrintClockInterval(start, end);

	if (Check(A2, size_2)) {
		printf("Checking result... pass\n");
	} else {
		printf("Checking result... fail\n");
	}

	printf("Freeing space of A2\n");
	free(A2);
	A2 = NULL;

	return 0;
}

void QuickSort(int *A, int left, int right) {
	int q;
	if (left >= right) {
		return;
	}
	/* q is the position of the pivot */
	q = Partition(A, left, right);
	QuickSort(A, left, q - 1);
	QuickSort(A, q + 1, right);
}

int Partition(int *A, int left, int right) {
	/* p is the position of the pivot */
	int p;
	p = Pivot(A, left, right);
	/* use i, j, pivot to locate left, right, and pivot */
	int i, j, pivot;
	Swap(A, p, right);
	i = left, j = right - 1, pivot = A[right];
	while (true) {
		while (i < right && A[i] < pivot)
			i++;
		while (j >= left && A[j] > pivot)
			j--;
		if (i < j)
			Swap(A, i++, j--);
		else
			break;
	}
	Swap(A, i, right);
	return i;
}

int Pivot(int *A, int left, int right) {
	int middle = 0;
	middle = (left + right) / 2;

	if (A[left] > A[middle]) {
		if (A[middle] > A[right]) {
			middle = middle;
		} else if (A[right] > A[left]) {
			middle = left;
		} else {
			middle = right;
		}
	} else {
		if (A[middle] < A[right]) {
			middle = middle;
		} else if (A[right] < A[left]) {
			middle = left;
		} else {
			middle = right;
		}
	}
	return middle;
}

void Swap(int *A, int x, int y) {
	int tmp;
	tmp = A[x];
	A[x] = A[y];
	A[y] = tmp;
}

bool Check(int *A, int size) {
	if (size == 1) {
		return true;
	}

	for (int i = 0; i < size - 1; i++) {
		/* return false if find any disorder */
		if (A[i] > A[i + 1]) {
			return false;
		}
	}

	return true;
}

void PrintClockInterval(clock_t start, clock_t end) {
	printf("the time cost of this algorithms is %ld ms\n",
			(end - start) / (CLOCKS_PER_SEC / 1000));
}

/* use this to check small size of data */
void _PrintClockInterval(clock_t start, clock_t end) {
	printf("the time cost of this algorithms is %ld ms\n", (end - start));
}
