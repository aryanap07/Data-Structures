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

Node *insert_at_end(Node *head, int value)
{
    Node *node = create_node(value);

    if (node == NULL)
    {
        return head;
    }

    if (head == NULL)
    {
        return node;
    }

    Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;
    node->prev = current;

    return head;
}

Node *delete_value(Node *head, int value)
{
    Node *current = head;

    while (current != NULL)
    {
        if (current->data == value)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
            }

            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }

            free(current);
            return head;
        }

        current = current->next;
    }

    return head;
}

void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
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
    Node *head = NULL;

    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);

    print_list(head);

    head = delete_value(head, 20);

    print_list(head);
    free_list(head);

    return 0;
}
