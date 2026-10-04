#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node != NULL)
    {
        node->data = value;
        node->prev = NULL;
        node->next = NULL;
    }

    return node;
}

void print_forward(Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);

        if (head->next != NULL)
        {
            printf(" <-> ");
        }

        head = head->next;
    }

    printf("\n");
}

void free_list(Node *head)
{
    while (head != NULL)
    {
        Node *next = head->next;
        free(head);
        head = next;
    }
}

int main(void)
{
    Node *first = create_node(10);
    Node *second = create_node(20);
    Node *third = create_node(30);

    if (first == NULL || second == NULL || third == NULL)
    {
        free(first);
        free(second);
        free(third);
        return 1;
    }

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;

    Node *node = create_node(25);

    if (node == NULL)
    {
        free_list(first);
        return 1;
    }

    node->prev = second;
    node->next = third;
    second->next = node;
    third->prev = node;

    print_forward(first);
    free_list(first);

    return 0;
}
