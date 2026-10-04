#include <stdio.h>

typedef struct
{
    int key;
    int block;
} IndexEntry;

int search_index(IndexEntry entries[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int middle = (low + high) / 2;

        if (entries[middle].key == key)
        {
            return entries[middle].block;
        }

        if (key < entries[middle].key)
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
    IndexEntry index[] =
    {
        {10, 100},
        {20, 200},
        {30, 300},
        {40, 400},
        {50, 500}
    };

    int size = sizeof(index) / sizeof(index[0]);
    int key = 30;
    int block = search_index(index, size, key);

    if (block != -1)
    {
        printf("Key %d is stored in block %d.\n", key, block);
    }
    else
    {
        printf("Key not found.\n");
    }

    return 0;
}
