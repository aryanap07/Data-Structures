#include <stdio.h>

void heapify(int array[], int length, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < length && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < length && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        heapify(array, length, largest);
    }
}

void heap_sort(int array[], int length)
{
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        heapify(array, length, i);
    }

    for (int i = length - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heapify(array, i, 0);
    }
}

int main(void)
{
    int array[] = {12, 11, 13, 5, 6, 7};
    int length = sizeof(array) / sizeof(array[0]);

    heap_sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
