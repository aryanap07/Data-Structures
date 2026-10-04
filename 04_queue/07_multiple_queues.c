#include <stdio.h>

#define MAX 10

int queue[MAX];
int front1 = -1;
int rear1 = -1;
int front2 = MAX;
int rear2 = MAX;

void enqueue1(int value)
{
    if (rear1 + 1 == rear2)
    {
        printf("No space available\n");
        return;
    }

    if (front1 == -1)
    {
        front1 = 0;
    }

    queue[++rear1] = value;
}

void enqueue2(int value)
{
    if (rear1 + 1 == rear2)
    {
        printf("No space available\n");
        return;
    }

    if (front2 == MAX)
    {
        front2 = MAX - 1;
        rear2 = MAX - 1;
    }
    else
    {
        front2--;
        rear2--;
    }

    queue[rear2] = value;
}

int dequeue1(void)
{
    if (front1 == -1 || front1 > rear1)
    {
        printf("Queue 1 Underflow\n");
        return -1;
    }

    int value = queue[front1++];

    if (front1 > rear1)
    {
        front1 = -1;
        rear1 = -1;
    }

    return value;
}

int dequeue2(void)
{
    if (front2 == MAX || rear2 < front2)
    {
        printf("Queue 2 Underflow\n");
        return -1;
    }

    int value = queue[front2--];

    if (front2 < rear2)
    {
        front2 = MAX;
        rear2 = MAX;
    }

    return value;
}

int main(void)
{
    enqueue1(10);
    enqueue1(20);

    enqueue2(30);
    enqueue2(40);

    printf("Queue 1 dequeue: %d\n", dequeue1());
    printf("Queue 2 dequeue: %d\n", dequeue2());

    return 0;
}
