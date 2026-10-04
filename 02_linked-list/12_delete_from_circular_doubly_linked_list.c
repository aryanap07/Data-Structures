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
        node->prev = node;
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

    Node *current = head;

    do
    {
        if (current->data == value)
        {
            if (current->next == current)
            {
                free(current);
                return NULL;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == head)
            {
                head = current->next;
            }

            free(current);
            return head;
        }

        current = current->next;
    } while (current != head);

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
        printf("%d <-> ", current->data);
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
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = head;
    head->prev = third;

    head = delete_value(head, 20);

    print_list(head);
    free_list(head);

    return 0;
}
