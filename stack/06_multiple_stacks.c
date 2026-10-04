#include <stdio.h>

#define MAX 10

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int value)
{
    if (top1 + 1 >= top2)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top1] = value;
}

void push2(int value)
{
    if (top1 + 1 >= top2)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[--top2] = value;
}

int pop1(void)
{
    if (top1 == -1)
    {
        printf("Stack 1 Underflow\n");
        return -1;
    }

    return stack[top1--];
}

int pop2(void)
{
    if (top2 == MAX)
    {
        printf("Stack 2 Underflow\n");
        return -1;
    }

    return stack[top2++];
}

int main(void)
{
    push1(10);
    push1(20);

    push2(30);
    push2(40);

    printf("Stack 1 pop: %d\n", pop1());
    printf("Stack 2 pop: %d\n", pop2());

    return 0;
}
