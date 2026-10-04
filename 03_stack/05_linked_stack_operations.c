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

int peek(void)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return top->data;
}

void free_stack(void)
{
    while (top != NULL)
    {
        Node *node = top;
        top = top->next;
        free(node);
    }
}

int main(void)
{
    push(10);
    push(20);
    push(30);

    printf("Peek: %d\n", peek());
    printf("Pop: %d\n", pop());
    printf("Peek: %d\n", peek());

    free_stack();

    return 0;
}
