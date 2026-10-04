#include <stdio.h>

void bubble_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
        {
            break;
        }
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
    int array[] = {5, 1, 4, 2, 8};
    int length = sizeof(array) / sizeof(array[0]);

    bubble_sort(array, length);
    print_array(array, length);

    return 0;
}
