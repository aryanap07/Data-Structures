#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int main(void)
{
    Node *first = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));

    if (first == NULL || second == NULL)
    {
        free(first);
        free(second);
        return 1;
    }

    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = NULL;

    printf("%d -> %d -> NULL\n", first->data, second->data);

    free(second);
    free(first);
    return 0;
}
