#include <stdio.h>

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;

            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

void quick_sort(int array[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivot_index = partition(array, low, high);

    quick_sort(array, low, pivot_index - 1);
    quick_sort(array, pivot_index + 1, high);
}

int main(void)
{
    int array[] = {10, 7, 8, 9, 1, 5};
    int length = sizeof(array) / sizeof(array[0]);

    quick_sort(array, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
