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
    Node *head = create_node(10);
    Node *second = create_node(20);
    Node *third = create_node(30);

    if (head == NULL || second == NULL || third == NULL)
    {
        free_list(head);
        free(second);
        free(third);
        return 1;
    }

    head->next = second;
    second->next = third;

    Node *node = create_node(25);

    if (node == NULL)
    {
        free_list(head);
        return 1;
    }

    node->next = third;
    second->next = node;

    print_list(head);
    free_list(head);

    return 0;
}
