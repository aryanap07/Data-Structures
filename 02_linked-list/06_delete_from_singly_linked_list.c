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

Node *delete_value(Node *head, int value)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == value)
    {
        Node *next = head->next;
        free(head);
        return next;
    }

    Node *current = head;

    while (current->next != NULL)
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

    head = delete_value(head, 20);

    print_list(head);
    free_list(head);

    return 0;
}
