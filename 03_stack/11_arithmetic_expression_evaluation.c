#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop(void)
{
    return stack[top--];
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

    return 0;
}

int apply_operator(int left, int right, char operator)
{
    switch (operator)
    {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        default:
            return 0;
    }
}

int main(void)
{
    const char *expression = "2+3*4";
    int values[MAX];
    char operators[MAX];
    int value_top = -1;
    int operator_top = -1;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char current = expression[i];

        if (current == ' ')
        {
            continue;
        }

        if (isdigit((unsigned char)current))
        {
            values[++value_top] = current - '0';
        }
        else if (current == '(')
        {
            operators[++operator_top] = current;
        }
        else if (current == ')')
        {
            while (operator_top >= 0 && operators[operator_top] != '(')
            {
                int right = values[value_top--];
                int left = values[value_top--];
                char operator = operators[operator_top--];

                values[++value_top] = apply_operator(left, right, operator);
            }

            if (operator_top >= 0)
            {
                operator_top--;
            }
        }
        else
        {
            while (operator_top >= 0 &&
                   operators[operator_top] != '(' &&
                   precedence(operators[operator_top]) >= precedence(current))
            {
                int right = values[value_top--];
                int left = values[value_top--];
                char operator = operators[operator_top--];

                values[++value_top] = apply_operator(left, right, operator);
            }

            operators[++operator_top] = current;
        }
    }

    while (operator_top >= 0)
    {
        int right = values[value_top--];
        int left = values[value_top--];
        char operator = operators[operator_top--];

        values[++value_top] = apply_operator(left, right, operator);
    }

    printf("Result: %d\n", values[value_top]);

    return 0;
}
