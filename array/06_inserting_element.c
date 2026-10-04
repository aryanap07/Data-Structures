#include <stdio.h>

int main(void)
{
    int numbers[10] = {10, 20, 30, 40, 50};
    int length = 5;
    int position = 2;
    int value = 99;

    for (int i = length; i > position; i--)
    {
        numbers[i] = numbers[i - 1];
    }

    numbers[position] = value;
    length++;

    printf("Array after insertion:\n");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}
