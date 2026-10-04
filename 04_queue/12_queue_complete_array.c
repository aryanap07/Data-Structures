#include <stdio.h>

#define MAX 5

typedef struct
{
    int items[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int is_empty(Queue *queue)
{
    return queue->front == -1;
}

int is_full(Queue *queue)
{
    return queue->rear == MAX - 1;
}

void enqueue(Queue *queue, int value)
{
    if (is_full(queue))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (is_empty(queue))
    {
        queue->front = 0;
    }

    queue->items[++queue->rear] = value;
}

int dequeue(Queue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue->items[queue->front++];

    if (queue->front > queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }

    return value;
}

int main(void)
{
    Queue queue;

    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Dequeue: %d\n", dequeue(&queue));
    printf("Dequeue: %d\n", dequeue(&queue));
    printf("Dequeue: %d\n", dequeue(&queue));

    return 0;
}
