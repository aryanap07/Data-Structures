#include <stdio.h>

void print_element(int value)
{
    printf("Element = %d\n", value);
}

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};

    print_element(numbers[2]);

    return 0;
}
