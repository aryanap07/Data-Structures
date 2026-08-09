#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void initialize(Queue *queue)
{
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

bool isEmpty(const Queue *queue)
{
    return queue->count == 0;
}

bool isFull(const Queue *queue)
{
    return queue->count == MAX_SIZE;
}

bool enqueue(Queue *queue, int value)
{
    if (isFull(queue)) {
        return false;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
    queue->count++;

    return true;
}

bool dequeue(Queue *queue, int *value)
{
    if (isEmpty(queue)) {
        return false;
    }

    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;

    return true;
}

bool peek(const Queue *queue, int *value)
{
    if (isEmpty(queue)) {
        return false;
    }

    *value = queue->data[queue->front];

    return true;
}

int size(const Queue *queue)
{
    return queue->count;
}

void display(const Queue *queue)
{
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % MAX_SIZE;
        printf("%d ", queue->data[index]);
    }

    printf("\n");
}

int main(void)
{
    Queue queue;
    int value;

    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    printf("Queue: ");
    display(&queue);

    if (peek(&queue, &value)) {
        printf("Front: %d\n", value);
    }

    if (dequeue(&queue, &value)) {
        printf("Dequeued: %d\n", value);
    }
  
    enqueue(&queue, 50);
  
    printf("Queue after dequeue: ");
    display(&queue);

    printf("Size: %d\n", size(&queue));

    return 0;
}
