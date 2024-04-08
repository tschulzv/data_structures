/******************************************************************************
Queue - Array implementation
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct _arrqueue {
	int* arr;
	int front;
	int end;
	int max;
} AQueue;

typedef AQueue* Queue;

Queue create() {
	Queue q;
	q = (Queue)malloc(sizeof(AQueue));
	q->arr = (int*)malloc(sizeof(int));
	q->front = 0;
	q->end = 0; // if queue has n elements, end is n index 
	q->max = MAX;
	return q;
}


int isEmpty(Queue q) {
	return (q->front == q->end);
}

int isFull(Queue q) {
	return ((q->end - q->front) == q->max);
}

int enqueue(Queue q, int x) {
	if (q == NULL) { return 1; }
	if (!isFull(q)) {
		q->arr[q->end] = x;
		q->end++;
		return 0;
	}
	printf("Queue is full\n");
	return 1;
}

int dequeue(Queue q) {
	if (q == NULL) { return 1; }
	if (!isEmpty(q)) {
		int val = q->arr[q->front];
		q->front++;
		return val;
	}
	printf("Queue is empty\n");
	return 1;
}

int front(Queue q) {
	if (q == NULL) { return -1; }
	return q->arr[q->front];
}


// after dequeue, all the items move one spot closer to the front
int dequeueMove(Queue q) {
	if (q == NULL) { return -1; }
	if (!isEmpty(q)) {
		int val = q->arr[q->front];
		for (int i = q->front; i < q->end - 1; i++) {
			q->arr[i] = q->arr[i + 1];
		}
		q->end--;
		return val;
	}
	printf("Queue is empty\n");
	return 1;
}

void print(Queue q) {
	if (q == NULL) { return; }
	if (!isEmpty(q)) {
		for (int i = q->front; i < q->end; i++) {
		printf("[%d], %d", i, q->arr[i]);
	}
	}
}



int main()
{
	Queue q = create();
	int empty = isEmpty(q);
	printf("is empty? %d \n", empty);
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	empty = isEmpty(q);
	printf("is empty? %d \n", empty);
	print(q);
    dequeueMove(q);
    print(q);

	return 0;
}
