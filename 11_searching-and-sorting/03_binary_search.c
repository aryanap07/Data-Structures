#include <stdio.h>

int binary_search(const int array[], int length, int target)
{
    int low = 0;
    int high = length - 1;

    while (low <= high)
    {
        int middle = low + (high - low) / 2;

        if (array[middle] == target)
        {
            return middle;
        }

        if (target < array[middle])
        {
            high = middle - 1;
        }
        else
        {
            low = middle + 1;
        }
    }

    return -1;
}

int main(void)
{
    int array[] = {10, 20, 30, 40, 50};
    int length = sizeof(array) / sizeof(array[0]);
    int target = 40;

    int index = binary_search(array, length, target);

    if (index != -1)
    {
        printf("Found at index %d\n", index);
    }
    else
    {
        printf("Not found\n");
    }

    return 0;
}
