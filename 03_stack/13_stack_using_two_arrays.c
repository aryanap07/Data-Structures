#include <stdio.h>

#define MAX 5

int first[MAX];
int second[MAX];
int top_first = -1;
int top_second = -1;

void push(int stack[], int *top, int value)
{
    if (*top == MAX - 1)
    {
        return;
    }

    stack[++(*top)] = value;
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        return -1;
    }

    return stack[(*top)--];
}

int main(void)
{
    push(first, &top_first, 10);
    push(first, &top_first, 20);

    push(second, &top_second, 30);
    push(second, &top_second, 40);

    printf("First stack pop: %d\n", pop(first, &top_first));
    printf("Second stack pop: %d\n", pop(second, &top_second));

    return 0;
}
