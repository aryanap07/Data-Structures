#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int temporary[], int left, int middle, int right)
{
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right)
    {
        if (array[i] <= array[j])
        {
            temporary[k++] = array[i++];
        }
        else
        {
            temporary[k++] = array[j++];
        }
    }

    while (i <= middle)
    {
        temporary[k++] = array[i++];
    }

    while (j <= right)
    {
        temporary[k++] = array[j++];
    }

    for (i = left; i <= right; i++)
    {
        array[i] = temporary[i];
    }
}

void merge_sort_recursive(
    int array[],
    int temporary[],
    int left,
    int right)
{
    if (left >= right)
    {
        return;
    }

    int middle = left + (right - left) / 2;

    merge_sort_recursive(array, temporary, left, middle);
    merge_sort_recursive(array, temporary, middle + 1, right);

    merge(array, temporary, left, middle, right);
}

int main(void)
{
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    int length = sizeof(array) / sizeof(array[0]);
    int *temporary = malloc((size_t)length * sizeof(int));

    if (temporary == NULL)
    {
        return 1;
    }

    merge_sort_recursive(array, temporary, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    free(temporary);

    return 0;
}
