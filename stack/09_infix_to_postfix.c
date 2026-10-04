#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value)
{
    stack[++top] = value;
}

char pop(void)
{
    return stack[top--];
}

char peek(void)
{
    return stack[top];
}

int precedence(char operator)
{
    if (operator == '+' || operator == '-')
    {
        return 1;
    }

    if (operator == '*' || operator == '/')
    {
        return 2;
    }

    if (operator == '^')
    {
        return 3;
    }

    return 0;
}

int main(void)
{
    const char *infix = "A+B*C";
    char postfix[MAX];
    int index = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char current = infix[i];

        if (isalnum((unsigned char)current))
        {
            postfix[index++] = current;
        }
        else if (current == '(')
        {
            push(current);
        }
        else if (current == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[index++] = pop();
            }

            if (top != -1)
            {
                pop();
            }
        }
        else
        {
            while (top != -1 && peek() != '(' &&
                   precedence(peek()) >= precedence(current))
            {
                postfix[index++] = pop();
            }

            push(current);
        }
    }

    while (top != -1)
    {
        postfix[index++] = pop();
    }

    postfix[index] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}
