#include <stdio.h>

#define SIZE 11
#define EMPTY -1

int table[SIZE];

int hash(int key)
{
    return key % SIZE;
}

void initialize(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = EMPTY;
    }
}

int insert(int key)
{
    int start = hash(key);

    for (int i = 0; i < SIZE; i++)
    {
        int index = (start + i * i) % SIZE;

        if (table[index] == EMPTY)
        {
            table[index] = key;
            return index;
        }
    }

    return -1;
}

int main(void)
{
    initialize();

    insert(22);
    insert(33);
    insert(44);
    insert(55);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: %d\n", i, table[i]);
    }

    return 0;
}
