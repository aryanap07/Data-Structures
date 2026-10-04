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
        node->next = node;
    }

    return node;
}

void print_list(Node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    Node *current = head;

    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("HEAD\n");
}

void free_list(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *current = head->next;

    while (current != head)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(head);
}

int main(void)
{
    Node *head = create_node(10);
    Node *second = create_node(20);
    Node *third = create_node(30);

    if (head == NULL || second == NULL || third == NULL)
    {
        free(head);
        free(second);
        free(third);
        return 1;
    }

    head->next = second;
    second->next = third;
    third->next = head;

    Node *node = create_node(40);

    if (node == NULL)
    {
        free_list(head);
        return 1;
    }

    node->next = head->next;
    head->next = node;

    print_list(head);
    free_list(head);

    return 0;
}
