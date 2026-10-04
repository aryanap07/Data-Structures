#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return;
    }

    node->data = value;
    node->next = NULL;

    if (rear == NULL)
    {
        front = node;
        rear = node;
        return;
    }

    rear->next = node;
    rear = node;
}

int dequeue(void)
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    Node *node = front;
    int value = node->data;

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(node);

    return value;
}

void free_queue(void)
{
    while (front != NULL)
    {
        Node *node = front;
        front = front->next;
        free(node);
    }

    rear = NULL;
}

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());

    free_queue();

    return 0;
}
