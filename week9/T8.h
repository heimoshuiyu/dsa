#include <time.h>


void QuickSort(int *A, int left, int right);

int Partition(int *A, int left, int right);

void HeapSort(int *A, int n);

void PercDown(int *A, int i, int n);

bool Check(int *A, int size);

void Swap(int *a, int *b);

void PrintTimeDuration(clock_t start_time, clock_t end_time);
