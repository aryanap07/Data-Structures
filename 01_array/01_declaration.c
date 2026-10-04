#include <stdio.h>

int main(void)
{
    int numbers[5];

    printf("Array contains %zu elements.\n", sizeof(numbers) / sizeof(numbers[0]));

    return 0;
}
