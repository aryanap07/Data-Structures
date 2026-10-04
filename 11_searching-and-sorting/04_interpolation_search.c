#include <stdio.h>

int interpolation_search(const int array[], int length, int target)
{
    int low = 0;
    int high = length - 1;

    while (low <= high &&
           target >= array[low] &&
           target <= array[high])
    {
        if (array[low] == array[high])
        {
            return array[low] == target ? low : -1;
        }

        int position = low +
            (int)(((double)(target - array[low]) *
                   (high - low)) /
                  (array[high] - array[low]));

        if (array[position] == target)
        {
            return position;
        }

        if (array[position] < target)
        {
            low = position + 1;
        }
        else
        {
            high = position - 1;
        }
    }

    return -1;
}

int main(void)
{
    int array[] = {10, 20, 30, 40, 50, 60, 70};
    int length = sizeof(array) / sizeof(array[0]);
    int target = 50;

    int index = interpolation_search(array, length, target);

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
