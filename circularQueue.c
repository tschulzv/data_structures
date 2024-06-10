// CIRCULAR QUEUE - TANIA SCHULZ
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CONFIRM_NOTNULL(v, retval) \
    if (NULL == v) { \
    printf("Error in line %u of file %s\n",__LINE__, __FILE__); \
    system("pause"); \
    return (retval); \
}

typedef struct CircQueue {
    int front, end;
    int size;
    int max;
    int * arr;
} CircQueue;

typedef CircQueue * Queue;

Queue create(int max){
    Queue q = (Queue)malloc(sizeof(CircQueue));
    CONFIRM_NOTNULL(q, NULL);
    
    int * arr = (int*)malloc(sizeof(int) * max);
    CONFIRM_NOTNULL(arr, NULL);
    
    q->arr = arr;
    q->max = max;
    q->size = 0;
    q->front = 0;
    q->end = max - 1;
    printf("Queue was created succesfully\n");
    return q;
}

int isEmpty(Queue q){
    CONFIRM_NOTNULL(q, INT_MIN);
    return (q->size == 0);
}

int isFull(Queue q){
    CONFIRM_NOTNULL(q, INT_MIN);
    return (q->size == q->max - 1); // one space is left unused
}

int enqueue(Queue q, int x){
    CONFIRM_NOTNULL(q, INT_MIN);
    
    if (!isFull(q)){
        q->end = (q->end + 1) % q->max;
        q->arr[q->end] = x;
        q->size++;
        printf("Value %d was added succesfully\n", x);
        return 0;    
    }    
    
    printf("Queue is full\n");
    return 1;
}

int dequeue(Queue q){
    CONFIRM_NOTNULL(q, INT_MIN);
    if (!isEmpty(q)){
        int temp = q->arr[q->front];
        q->front = (q->front + 1) % q->max;
        q->size--;
         printf("Value %d was removed succesfully\n", temp);
        return temp;
    }
    printf("Queue is empty\n");
    return INT_MIN;
}

int peek(Queue q){
    CONFIRM_NOTNULL(q, -1);
    if (!isEmpty(q)){
        int front = q->arr[q->front];
        printf("Front is %d \n", front);
        return front;
    }
    printf("Queue is empty\n");
    return -1;
}



int main()
{
    Queue q = create(6);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    peek(q);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    
    dequeue(q);
    peek(q);
    dequeue(q);
    peek(q);
    
    return 0;
}
