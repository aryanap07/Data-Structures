#include <stdio.h>

#define SIZE 10

int main(void)
{
    int table[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        table[i] = -1;
    }

    int keys[] = {23, 45, 12, 67};
    int length = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < length; i++)
    {
        int index = keys[i] % SIZE;
        table[index] = keys[i];
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: %d\n", i, table[i]);
    }

    return 0;
}
