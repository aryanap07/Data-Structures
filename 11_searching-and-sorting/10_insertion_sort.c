#include <stdio.h>

void insertion_sort(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void print_array(const int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main(void)
{
    int array[] = {12, 11, 13, 5, 6};
    int length = sizeof(array) / sizeof(array[0]);

    insertion_sort(array, length);
    print_array(array, length);

    return 0;
}
