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

    head = delete_value(head, 20);

    print_list(head);
    free_list(head);

    return 0;
}
