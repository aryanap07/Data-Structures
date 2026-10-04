#include <stdio.h>

#define MAX 5

int main(void)
{
    int stack[MAX];
    int top = -1;

    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    printf("Stack elements:\n");

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    return 0;
}
