#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(const Stack *stack)
{
    return stack->top == -1;
}

bool isFull(const Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

bool push(Stack *stack, int value)
{
    if (isFull(stack))
        return false;

    stack->data[++stack->top] = value;
    return true;
}

bool pop(Stack *stack, int *value)
{
    if (isEmpty(stack))
        return false;

    *value = stack->data[stack->top--];
    return true;
}

bool peek(const Stack *stack, int *value)
{
    if (isEmpty(stack))
        return false;

    *value = stack->data[stack->top];
    return true;
}

int size(const Stack *stack)
{
    return stack->top + 1;
}

void display(const Stack *stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    for (int i = stack->top; i >= 0; i--)
        printf("%d\n", stack->data[i]);
}

int main(void)
{
    Stack stack;
    int value;

    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Stack:\n");
    display(&stack);

    if (peek(&stack, &value))
        printf("Top: %d\n", value);
	
    if (pop(&stack, &value))
        printf("Popped: %d\n", value);
	
	push(&stack, 50);
	
    printf("Size: %d\n", size(&stack));

    return 0;
}
