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

void print_forward(Node *head)
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

    first = delete_value(first, 20);

    print_forward(first);
    free_list(first);

    return 0;
}
