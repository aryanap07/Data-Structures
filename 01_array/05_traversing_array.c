#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < length; i++)
    {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    return 0;
}
