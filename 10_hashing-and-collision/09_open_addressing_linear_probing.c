#include <stdio.h>

#define SIZE 10
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
        int index = (start + i) % SIZE;

        if (table[index] == EMPTY)
        {
            table[index] = key;
            return index;
        }
    }

    return -1;
}

int search(int key)
{
    int start = hash(key);

    for (int i = 0; i < SIZE; i++)
    {
        int index = (start + i) % SIZE;

        if (table[index] == EMPTY)
        {
            return -1;
        }

        if (table[index] == key)
        {
            return index;
        }
    }

    return -1;
}

void display(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: %d\n", i, table[i]);
    }
}

int main(void)
{
    initialize();

    insert(10);
    insert(20);
    insert(30);
    insert(15);

    display();

    printf("Search 30: %d\n", search(30));

    return 0;
}
