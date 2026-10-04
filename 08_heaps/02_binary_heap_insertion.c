#include <stdio.h>

#define MAX 20

typedef struct
{
    int data[MAX];
    int size;
} MaxHeap;

void insert(MaxHeap *heap, int value)
{
    if (heap->size == MAX)
    {
        return;
    }

    int index = heap->size++;
    heap->data[index] = value;

    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (heap->data[parent] >= heap->data[index])
        {
            break;
        }

        int temp = heap->data[parent];
        heap->data[parent] = heap->data[index];
        heap->data[index] = temp;

        index = parent;
    }
}

void display(MaxHeap *heap)
{
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->data[i]);
    }

    printf("\n");
}

int main(void)
{
    MaxHeap heap = {.size = 0};

    insert(&heap, 50);
    insert(&heap, 30);
    insert(&heap, 40);
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 60);

    printf("After insertion: ");
    display(&heap);

    return 0;
}
