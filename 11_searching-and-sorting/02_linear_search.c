#include <stdio.h>

int linear_search(const int array[], int length, int target)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main(void)
{
    int array[] = {10, 20, 30, 40, 50};
    int length = sizeof(array) / sizeof(array[0]);
    int target = 30;

    int index = linear_search(array, length, target);

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
