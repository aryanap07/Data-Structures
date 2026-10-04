#include <stdio.h>

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

int is_matching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int check_parentheses(const char *expression)
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char current = expression[i];

        if (current == '(' || current == '[' || current == '{')
        {
            if (top == MAX - 1)
            {
                return 0;
            }

            push(current);
        }
        else if (current == ')' || current == ']' || current == '}')
        {
            if (top == -1)
            {
                return 0;
            }

            if (!is_matching(pop(), current))
            {
                return 0;
            }
        }
    }

    return top == -1;
}

int main(void)
{
    const char *expression = "{[2 + (3 * 4)]}";

    if (check_parentheses(expression))
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not balanced\n");
    }

    return 0;
}
