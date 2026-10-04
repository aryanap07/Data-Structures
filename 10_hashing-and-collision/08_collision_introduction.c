#include <stdio.h>

#define SIZE 5

int hash(int key)
{
    return key % SIZE;
}

int main(void)
{
    int first = 10;
    int second = 15;

    printf("%d -> index %d\n", first, hash(first));
    printf("%d -> index %d\n", second, hash(second));
    printf("Both keys produce the same index, so a collision occurs.\n");

    return 0;
}
