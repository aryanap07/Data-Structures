#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int main(void)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return 1;
    }

    node->data = 10;
    node->next = NULL;

    printf("Data: %d\n", node->data);
    printf("Next: %p\n", (void *)node->next);

    free(node);
    return 0;
}
