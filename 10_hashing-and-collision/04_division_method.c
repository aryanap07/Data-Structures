#include <stdio.h>

#define SIZE 11

int hash(int key)
{
    return key % SIZE;
}

int main(void)
{
    int keys[] = {22, 34, 57, 68, 79};
    int length = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < length; i++)
    {
        printf("Key %d -> index %d\n", keys[i], hash(keys[i]));
    }

    return 0;
}
