#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        return;
    }

    queue[++rear] = value;
}

int dequeue(void)
{
    if (front > rear)
    {
        return -1;
    }

    return queue[front++];
}

int main(void)
{
    enqueue(101);
    enqueue(102);
    enqueue(103);

    printf("Serving customer %d\n", dequeue());
    printf("Serving customer %d\n", dequeue());
    printf("Serving customer %d\n", dequeue());

    return 0;
}
