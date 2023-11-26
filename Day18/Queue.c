#include<stdio.h>
#include<limits.h>
struct Queue
{
    int size, front, rear;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* q= (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity=capacity;
    q->front=q->size=0;
    q->rear=(capacity-1);
    q->array=(int*)malloc(q->capacity*sizeof(int));

    return q;
}

int isFull(struct Queue* q)
{
    return (q->size==q->capacity);
}

int isEmpty(struct Queue* q)
{
    return (q->size==0);
}

void enqueue(struct Queue* q, int item)
{
    if(isFull(q)) return;
    q->rear =(q->rear+1)%(q->capacity);
    q->array[q->rear]=item;
    q->size=q->size+1;
}

void dequeue(struct Queue* q)
{
    if(isEmpty()) return INT_MIN;
    int item =q->array[q->front];
    q->front=(q->front+1)%(q->capacity);
    q->size =q->size+1;
    return item;
}
int front(struct Queue* q)
{
    if(isEmpty(q)) return INT_MIN;
    return q->array[q->front];
}
int rear(struct Queue* q)
{
    if(isEmpty(q)) return INT_MIN;
    return q->array[q->rear];
}