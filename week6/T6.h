/*
 * Author: Walter
 * Student ID: 1930006025
 * Week_6
 * InsertionSort and MergeSort
 */

#include <stdbool.h>
#include <time.h>

/* insertion sort array A, with size n */
void InsertionSort(int *A, int n);

/* merge sort array A, start at left, end at right */
void MergeSort(int *A, int left, int right);

/* real merge sort function */
void _MergeSort(int *A, int *tmp, int left, int right);

/* merge function used in merge short */
void Merge(int *A, int *tmp, int lpos, int rpos, int rend);

/* check a sorted array */
bool Check(int *A, int size);

/* print one line to stdout about interval in ms */
void PrintClockInterval(clock_t start, clock_t end);
