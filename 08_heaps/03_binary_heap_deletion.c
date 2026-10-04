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

int delete_max(MaxHeap *heap)
{
    if (heap->size == 0)
    {
        return -1;
    }

    int value = heap->data[0];
    heap->data[0] = heap->data[--heap->size];

    int index = 0;

    while (1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap->size &&
            heap->data[left] > heap->data[largest])
        {
            largest = left;
        }

        if (right < heap->size &&
            heap->data[right] > heap->data[largest])
        {
            largest = right;
        }

        if (largest == index)
        {
            break;
        }

        int temp = heap->data[index];
        heap->data[index] = heap->data[largest];
        heap->data[largest] = temp;

        index = largest;
    }

    return value;
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
    insert(&heap, 70);
    insert(&heap, 20);
    insert(&heap, 60);

    printf("Heap before deletion: ");
    display(&heap);

    printf("Deleted: %d\n", delete_max(&heap));

    printf("Heap after deletion: ");
    display(&heap);

    return 0;
}
