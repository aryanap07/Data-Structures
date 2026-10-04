#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30};

    int *ptr = numbers;

    printf("First element: %d\n", *ptr);
    printf("Second element: %d\n", *(ptr + 1));
    printf("Third element: %d\n", *(ptr + 2));

    return 0;
}
