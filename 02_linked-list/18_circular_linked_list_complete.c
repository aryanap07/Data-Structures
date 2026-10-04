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

    while (current->next != head)
    {
        current = current->next;
    }

    current->next = node;
    node->next = head;

    return head;
}

Node *delete_value(Node *head, int value)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == value)
    {
        if (head->next == head)
        {
            free(head);
            return NULL;
        }

        Node *last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        Node *new_head = head->next;
        last->next = new_head;
        free(head);

        return new_head;
    }

    Node *current = head;

    while (current->next != head)
    {
        if (current->next->data == value)
        {
            Node *to_delete = current->next;
            current->next = to_delete->next;
            free(to_delete);
            return head;
        }

        current = current->next;
    }

    return head;
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
