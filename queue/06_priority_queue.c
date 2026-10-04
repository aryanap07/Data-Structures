#include <stdio.h>

#define MAX 5

typedef struct
{
    int data;
    int priority;
} Item;

Item queue[MAX];
int size = 0;

void enqueue(int data, int priority)
{
    if (size == MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = size - 1;

    while (i >= 0 && queue[i].priority < priority)
    {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1].data = data;
    queue[i + 1].priority = priority;
    size++;
}

Item dequeue(void)
{
    Item item = {0, 0};

    if (size == 0)
    {
        printf("Priority Queue Underflow\n");
        return item;
    }

    item = queue[0];

    for (int i = 1; i < size; i++)
    {
        queue[i - 1] = queue[i];
    }

    size--;

    return item;
}

void display(void)
{
    for (int i = 0; i < size; i++)
    {
        printf("Data: %d, Priority: %d\n",
               queue[i].data,
               queue[i].priority);
    }
}

int main(void)
{
    enqueue(10, 2);
    enqueue(20, 3);
    enqueue(30, 1);

    display();

    Item item = dequeue();

    printf("Removed: %d\n", item.data);

    return 0;
}
