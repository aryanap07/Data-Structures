#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *down;
} Node;

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node != NULL)
    {
        node->data = value;
        node->next = NULL;
        node->down = NULL;
    }

    return node;
}

void print_list(Node *head)
{
    Node *row = head;

    while (row != NULL)
    {
        Node *current = row;

        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }

        printf("NULL\n");
        row = row->down;
    }
}

void free_list(Node *head)
{
    while (head != NULL)
    {
        Node *row = head;
        head = head->down;

        while (row != NULL)
        {
            Node *next = row->next;
            free(row);
            row = next;
        }
    }
}

int main(void)
{
    Node *a = create_node(1);
    Node *b = create_node(2);
    Node *c = create_node(3);
    Node *d = create_node(4);

    if (a == NULL || b == NULL || c == NULL || d == NULL)
    {
        free(a);
        free(b);
        free(c);
        free(d);
        return 1;
    }

    a->next = b;
    a->down = c;
    c->next = d;

    print_list(a);
    free_list(a);

    return 0;
}
