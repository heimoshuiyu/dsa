#include <stdbool.h>
#include <time.h>


/* Sort array A[left..right] using quick sort */
/* Pivot is picked using median-of-3 */
void QuickSort(int *A, int left, int right);

/* Sort the array in order */
int Partition(int *A, int left, int right);

/* pick the middle value between A[left], A[middle], A[right] */
int Pivot(int *A, int left, int right);

/* Swap A[x], A[y] */
void Swap(int *A, int x,int y);

/* create check functions */
bool Check(int *A, int size);

/* print the time of small data */
void PrintClockInterval(clock_t start, clock_t end);

/* use this to check small size of data */
void _PrintClockInterval(clock_t start, clock_t end);

