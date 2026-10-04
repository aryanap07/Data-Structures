#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int search(Node *head, int value)
{
    int position = 0;

    while (head != NULL)
    {
        if (head->data == value)
        {
            return position;
        }

        head = head->next;
        position++;
    }

    return -1;
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
    Node *first = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *third = malloc(sizeof(Node));

    if (first == NULL || second == NULL || third == NULL)
    {
        free(first);
        free(second);
        free(third);
        return 1;
    }

    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;

    int position = search(first, 20);

    if (position >= 0)
    {
        printf("Value found at position %d.\n", position);
    }
    else
    {
        printf("Value not found.\n");
    }

    free_list(first);
    return 0;
}
