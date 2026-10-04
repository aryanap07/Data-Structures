#include <stdio.h>

#define SIZE 100

int hash(int key)
{
    int sum = 0;

    while (key > 0)
    {
        sum += key % 100;
        key /= 100;
    }

    return sum % SIZE;
}

int main(void)
{
    int keys[] = {123456, 234567, 345678, 456789};
    int length = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < length; i++)
    {
        printf("Key %d -> index %d\n", keys[i], hash(keys[i]));
    }

    return 0;
}
