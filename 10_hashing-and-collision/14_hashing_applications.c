#include <stdio.h>

#define SIZE 10

int table[SIZE];

void initialize(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = -1;
    }
}

int hash(int key)
{
    return key % SIZE;
}

void store(int key)
{
    int index = hash(key);
    table[index] = key;
}

int contains(int key)
{
    return table[hash(key)] == key;
}

int main(void)
{
    initialize();

    store(101);
    store(205);
    store(309);

    printf("Student ID 101: %s\n",
           contains(101) ? "Present" : "Absent");

    printf("Student ID 202: %s\n",
           contains(202) ? "Present" : "Absent");

    printf("Hashing is commonly used for caches, symbol tables,");
    printf(" databases, dictionaries and membership lookup.\n");

    return 0;
}
