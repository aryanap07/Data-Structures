#include <stdio.h>

#define MAX 20

typedef struct
{
    int data[MAX];
    int size;
} MaxHeap;

void initialize(MaxHeap *heap)
{
    heap->size = 0;
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
    MaxHeap heap;

    initialize(&heap);

    heap.data[0] = 90;
    heap.data[1] = 70;
    heap.data[2] = 60;
    heap.data[3] = 40;
    heap.data[4] = 50;
    heap.size = 5;

    printf("Binary max heap: ");
    display(&heap);

    return 0;
}
