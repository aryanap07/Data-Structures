#include <stdio.h>

#define SIZE 100

int hash(int key)
{
    long long square = (long long)key * key;
    int middle = (int)((square / 10) % 100);

    return middle % SIZE;
}

int main(void)
{
    int keys[] = {12, 25, 37, 49, 58};
    int length = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < length; i++)
    {
        printf("Key %d -> index %d\n", keys[i], hash(keys[i]));
    }

    return 0;
}
