#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Header
{
    int count;
    Node *next;
} Header;

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node != NULL)
    {
        node->data = value;
        node->next = NULL;
    }

    return node;
}

void print_list(Header *header)
{
    Node *current = header->next;

    printf("Count = %d\n", header->count);

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

void free_list(Header *header)
{
    Node *current = header->next;

    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(header);
}

int main(void)
{
    Header *header = malloc(sizeof(Header));

    if (header == NULL)
    {
        return 1;
    }

    header->count = 0;
    header->next = NULL;

    Node *first = create_node(10);
    Node *second = create_node(20);

    if (first == NULL || second == NULL)
    {
        free(first);
        free(second);
        free(header);
        return 1;
    }

    header->next = first;
    first->next = second;
    header->count = 2;

    print_list(header);
    free_list(header);

    return 0;
}
