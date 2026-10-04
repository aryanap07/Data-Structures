#include <stdio.h>

void print_array(int numbers[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");
}

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    print_array(numbers, length);

    return 0;
}
