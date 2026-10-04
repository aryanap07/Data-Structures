#include <stdio.h>

void shell_sort(int array[], int length)
{
    for (int gap = length / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < length; i++)
        {
            int value = array[i];
            int j = i;

            while (j >= gap && array[j - gap] > value)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = value;
        }
    }
}

int main(void)
{
    int array[] = {12, 34, 54, 2, 3};
    int length = sizeof(array) / sizeof(array[0]);

    shell_sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
