/* 
 * Authro: Walter
 * Student ID: 1930006025
 * Week4_queue
 */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

#include <assert.h>

bool CreateQueue(Queue *queue, int size) {
	/* do some check */
	assert(size > 0 && "Error: szie should be positive");

	/* allocate memory */
	queue->values = (double *)malloc(sizeof(double)*size);
	if (queue->values == NULL) {
		return false;
	}

	/* init values */
	queue->front = 0;
	queue->rear = -1;
	queue->counter = 0;
	queue->maxSize = size;

	return true;
}

bool IsEmpty(Queue *queue) {
	return queue->counter == 0;
}

bool IsFull(Queue *queue) {
	return queue->maxSize == queue->counter;
}

bool Enqueue(Queue *queue, double x) {

	/* check full */
	if (IsFull(queue)) {
		fprintf(stderr, "Error: the queue is full.\n");
		return false;
	}

	/* move rear, add counter */
	queue->rear++;
	queue->counter++;
	if (queue->rear >= queue->maxSize) {
		queue->rear = 0;
	}

	/* enqueue value */
	queue->values[queue->rear] = x;

	return true;
}

bool Dequeue(Queue *queue, double *x) {

	/* check */
	if (IsEmpty(queue)) {
		return false;
	}

	/* dequeue value */
	*x = queue->values[queue->front];

	/* move front and decrease counter */
	queue->front++;
	queue->counter--;
	if (queue->front >= queue->maxSize) {
		queue->front = 0;
	}

	return true;
}

void DisplayQueue(Queue *queue) {
	int pos = queue->front;

	/* loop for counter */
	for (int i=0; i<queue->counter; i++) {

		/* print front hint */
		if (i == 0) {
			printf("front --> ");
		} else {
			printf("          ");
		}

		printf("%f", queue->values[pos]);

		pos++;
		/* set pos to zero if it gets to end */
		if (pos >= queue->maxSize) {
			pos = 0;
		}

		/* print end hint */
		if (i == queue->counter - 1) {
			printf(" <-- rear\n");
		} else {
			printf("\n");
		}
	}
}

void DestroyQueue(Queue *queue) {
	free(queue->values);
	/* reset values */
	queue->counter = 0;
	queue->maxSize = 0;
	queue->front = 0;
	queue->rear = -1;
}
