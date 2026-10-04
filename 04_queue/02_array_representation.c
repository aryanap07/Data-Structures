#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    queue[++rear] = value;
}

int dequeue(void)
{
    if (front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    return queue[front++];
}

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());

    return 0;
}
