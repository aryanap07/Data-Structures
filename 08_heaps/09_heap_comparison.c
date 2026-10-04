#include <stdio.h>

int main(void)
{
    printf("Heap type       Structure              Typical priority operations\n");
    printf("Binary heap     Array based             Insert O(log n), Extract O(log n)\n");
    printf("Binomial heap   Collection of trees     Insert O(log n), Merge O(log n)\n");
    printf("Fibonacci heap  Collection of trees     Insert O(1) amortized, Merge O(1) amortized\n");

    return 0;
}
