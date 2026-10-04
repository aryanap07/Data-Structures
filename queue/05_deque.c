#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

int is_empty(void)
{
    return front == -1;
}

int is_full(void)
{
    return (front == 0 && rear == MAX - 1) ||
           (front == rear + 1);
}

void insert_front(int value)
{
    if (is_full())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (is_empty())
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = value;
}

void insert_rear(int value)
{
    if (is_full())
    {
        printf("Deque Overflow\n");
        return;
    }

    if (is_empty())
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

int delete_front(void)
{
    if (is_empty())
    {
        printf("Deque Underflow\n");
        return -1;
    }

    int value = deque[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    return value;
}

int delete_rear(void)
{
    if (is_empty())
    {
        printf("Deque Underflow\n");
        return -1;
    }

    int value = deque[rear];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }

    return value;
}

void display(void)
{
    if (is_empty())
    {
        printf("Empty deque\n");
        return;
    }

    int i = front;

    while (1)
    {
        printf("%d ", deque[i]);

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
    insert_rear(10);
    insert_rear(20);
    insert_front(5);

    printf("Deque: ");
    display();

    printf("Delete front: %d\n", delete_front());
    printf("Delete rear: %d\n", delete_rear());

    printf("Deque: ");
    display();

    return 0;
}
