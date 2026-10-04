#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return;
    }

    node->data = value;
    node->next = top;
    top = node;
}

int pop(void)
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    Node *node = top;
    int value = node->data;

    top = top->next;
    free(node);

    return value;
}

int main(void)
{
    push(10);
    push(20);
    push(30);

    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());

    return 0;
}
