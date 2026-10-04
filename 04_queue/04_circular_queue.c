#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int is_full(void)
{
    return front == (rear + 1) % MAX;
}

int is_empty(void)
{
    return front == -1;
}

void enqueue(int value)
{
    if (is_full())
    {
        printf("Queue Overflow\n");
        return;
    }

    if (is_empty())
    {
        front = 0;
    }

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

int dequeue(void)
{
    if (is_empty())
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = queue[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    return value;
}

void display(void)
{
    if (is_empty())
    {
        printf("Empty queue\n");
        return;
    }

    int i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Queue: ");
    display();

    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());

    enqueue(50);
    enqueue(60);

    printf("Queue: ");
    display();

    return 0;
}
