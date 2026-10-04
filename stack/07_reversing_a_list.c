#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

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

void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

Node *reverse_list(Node *head)
{
    Node *previous = NULL;
    Node *current = head;

    while (current != NULL)
    {
        Node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
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
    second->next = third;

    printf("Original list: ");
    print_list(first);

    first = reverse_list(first);

    printf("Reversed list: ");
    print_list(first);

    free_list(first);

    return 0;
}
