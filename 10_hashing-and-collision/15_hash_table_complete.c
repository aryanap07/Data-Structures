#include <stdio.h>

#define SIZE 11
#define EMPTY -1

typedef struct
{
    int key;
    int value;
} Entry;

Entry table[SIZE];

int hash(int key)
{
    return key % SIZE;
}

void initialize(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i].key = EMPTY;
        table[i].value = 0;
    }
}

int insert(int key, int value)
{
    int start = hash(key);

    for (int i = 0; i < SIZE; i++)
    {
        int index = (start + i) % SIZE;

        if (table[index].key == EMPTY ||
            table[index].key == key)
        {
            table[index].key = key;
            table[index].value = value;
            return 1;
        }
    }

    return 0;
}

int search(int key, int *value)
{
    int start = hash(key);

    for (int i = 0; i < SIZE; i++)
    {
        int index = (start + i) % SIZE;

        if (table[index].key == EMPTY)
        {
            return 0;
        }

        if (table[index].key == key)
        {
            *value = table[index].value;
            return 1;
        }
    }

    return 0;
}

int delete_key(int key)
{
    int start = hash(key);

    for (int i = 0; i < SIZE; i++)
    {
        int index = (start + i) % SIZE;

        if (table[index].key == EMPTY)
        {
            return 0;
        }

        if (table[index].key == key)
        {
            table[index].key = EMPTY;
            table[index].value = 0;
            return 1;
        }
    }

    return 0;
}

void display(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (table[i].key == EMPTY)
        {
            printf("%d: EMPTY\n", i);
        }
        else
        {
            printf("%d: (%d, %d)\n",
                   i,
                   table[i].key,
                   table[i].value);
        }
    }
}

int main(void)
{
    initialize();

    insert(10, 100);
    insert(21, 200);
    insert(32, 300);
    insert(43, 400);

    display();

    int value;

    if (search(32, &value))
    {
        printf("Key 32 has value %d\n", value);
    }

    delete_key(21);

    printf("After deleting key 21:\n");
    display();

    return 0;
}
