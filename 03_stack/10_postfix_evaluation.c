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

int power(int base, int exponent)
{
    int result = 1;

    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }

    return result;
}

int main(void)
{
    const char *expression = "23*54*+";

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char current = expression[i];

        if (isdigit((unsigned char)current))
        {
            push(current - '0');
        }
        else
        {
            int right = pop();
            int left = pop();
            int result = 0;

            switch (current)
            {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
                case '^':
                    result = power(left, right);
                    break;
                default:
                    return 1;
            }

            push(result);
        }
    }

    printf("Result: %d\n", pop());

    return 0;
}
