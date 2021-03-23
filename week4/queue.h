/* 
 * Authro: Walter
 * Student ID: 1930006025
 * Week4_queue
 */

#include <stdbool.h>

/* main queue structure */
typedef struct {
	double *values;
	int front; /* last one of queue */
	int rear; /* the newest one in queue */
	int counter;
	int maxSize;
} Queue;

/* create an queue */
bool CreateQueue(Queue *queue, int size);

/* check whether the queue is empty*/
bool IsEmpty(Queue *queue);

/* check whether the queue is full */
bool IsFull(Queue *queue);

/* put value into queue */
bool Enqueue(Queue *queue, double x);

/* get value from queue */
bool Dequeue(Queue *queue, double *x);

/* display queue to stdout */
void DisplayQueue(Queue *queue);

/* destroy an queue */
void DestroyQueue(Queue *queue);
