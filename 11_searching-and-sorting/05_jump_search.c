#include <stdio.h>

int jump_search(const int array[], int length, int target)
{
    int block = 1;

    while (block * block < length)
    {
        block++;
    }

    int start = 0;
    int end = block;

    while (start < length && array[(end < length ? end : length) - 1] < target)
    {
        start = end;
        end += block;

        if (start >= length)
        {
            return -1;
        }
    }

    if (end > length)
    {
        end = length;
    }

    for (int i = start; i < end; i++)
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
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int length = sizeof(array) / sizeof(array[0]);
    int target = 60;

    int index = jump_search(array, length, target);

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
