#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    int length = 5;
    int position = 2;

    for (int i = position; i < length - 1; i++)
    {
        numbers[i] = numbers[i + 1];
    }

    length--;

    printf("Array after deletion:\n");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    return 0;
}
