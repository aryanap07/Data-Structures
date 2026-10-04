#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

Node *table[SIZE];

int hash(int key)
{
    return key % SIZE;
}

void initialize(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = NULL;
    }
}

int insert(int key)
{
    int index = hash(key);
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return 0;
    }

    node->key = key;
    node->next = table[index];
    table[index] = node;

    return 1;
}

Node *search(int key)
{
    int index = hash(key);
    Node *current = table[index];

    while (current != NULL)
    {
        if (current->key == key)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void display(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        Node *current = table[i];

        printf("%d: ", i);

        while (current != NULL)
        {
            printf("%d -> ", current->key);
            current = current->next;
        }

        printf("NULL\n");
    }
}

void free_table(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        while (table[i] != NULL)
        {
            Node *next = table[i]->next;
            free(table[i]);
            table[i] = next;
        }
    }
}

int main(void)
{
    initialize();

    insert(10);
    insert(17);
    insert(24);
    insert(31);

    display();

    printf("Search 24: %s\n",
           search(24) != NULL ? "Found" : "Not found");

    free_table();

    return 0;
}
