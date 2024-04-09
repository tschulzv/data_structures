/********
* Linked List Queue Implementation
*********/

#include <stdlib.h>
#include <stdio.h>
#define MAX 5

struct aNode {
	int val;
	struct aNode *next;
};

typedef struct aNode *Node;

typedef struct _LLQueue {
	Node front;
	Node end;
} LLQueue;

typedef LLQueue* Queue;

Queue create(){
	Queue q;
	q = (Queue)malloc(sizeof(LLQueue));
	if (q == NULL) {return NULL;} 
	q->front = NULL;
	q->end = NULL;
	return q;
}


int isEmpty(Queue q){
	return (q->front == NULL && q-> end == NULL);
}

int enqueue(Queue q, int x) {
	if (q == NULL) { return 1; }
	Node n = (Node)malloc(sizeof(struct aNode));
	if (n == NULL) { return 1; }
	
	n->val = x;
	n->next = NULL;
	if (isEmpty(q)) { 
	    q -> front = n ; 
	    q -> end = n;
	}
	q->end->next = n;
	q->end = n;
	return 0;
}

int dequeue(Queue q){
	if (q == NULL) { return 1; }
	if (!isEmpty(q)){
		Node front = q->front;
		int val = q->front->val;
		q->front = q->front->next;
		free(front);
		return val;
	}
	printf("Queue is empty\n");
	return 1;
}


void print(Queue q){
	if (q == NULL) {return;}
	if (!isEmpty(q)){
		Node n = q -> front;
		while(n != NULL){
		    int v = n->val;
			printf("%d \n", v);
			n = n->next;
		}
	}
}

int main()
{
	Queue q = create();
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	print(q);
	dequeue(q);
	printf("after dequeue\n");
	print(q);
    free(q);

	return 0;
}
