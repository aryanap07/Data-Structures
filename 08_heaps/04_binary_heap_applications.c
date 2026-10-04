#include <stdio.h>

#define MAX 20

typedef struct
{
    int data[MAX];
    int size;
} MaxHeap;

void insert(MaxHeap *heap, int value)
{
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

int remove_max(MaxHeap *heap)
{
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

int main(void)
{
    MaxHeap heap = {.size = 0};
    int values[] = {30, 10, 50, 20, 40};
    int length = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < length; i++)
    {
        insert(&heap, values[i]);
    }

    printf("Priority order: ");

    while (heap.size > 0)
    {
        printf("%d ", remove_max(&heap));
    }

    printf("\n");

    return 0;
}
