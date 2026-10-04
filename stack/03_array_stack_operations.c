#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

int pop(void)
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

int peek(void)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }

    return stack[top];
}

int main(void)
{
    push(10);
    push(20);
    push(30);

    printf("Peek: %d\n", peek());
    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());
    printf("Peek: %d\n", peek());

    return 0;
}
