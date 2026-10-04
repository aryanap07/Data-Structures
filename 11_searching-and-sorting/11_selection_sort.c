#include <stdio.h>

void selection_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minimum = i;

        for (int j = i + 1; j < length; j++)
        {
            if (array[j] < array[minimum])
            {
                minimum = j;
            }
        }

        if (minimum != i)
        {
            int temp = array[i];
            array[i] = array[minimum];
            array[minimum] = temp;
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
    int array[] = {64, 25, 12, 22, 11};
    int length = sizeof(array) / sizeof(array[0]);

    selection_sort(array, length);
    print_array(array, length);

    return 0;
}
