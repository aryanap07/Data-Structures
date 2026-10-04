#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void initialize(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

int is_empty(Queue *queue)
{
    return queue->front == NULL;
}

void enqueue(Queue *queue, int value)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return;
    }

    node->data = value;
    node->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = node;
        queue->rear = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

int dequeue(Queue *queue)
{
    if (is_empty(queue))
    {
        return -1;
    }

    Node *node = queue->front;
    int value = node->data;

    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(node);

    return value;
}

void free_queue(Queue *queue)
{
    while (queue->front != NULL)
    {
        Node *node = queue->front;
        queue->front = queue->front->next;
        free(node);
    }

    queue->rear = NULL;
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

    free_queue(&queue);

    return 0;
}
