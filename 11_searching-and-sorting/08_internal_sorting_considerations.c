#include <stdio.h>

int main(void)
{
    printf("Internal sorting keeps the entire data set in main memory.\n");
    printf("Important considerations include time complexity,");
    printf(" extra memory, stability and whether the algorithm is in-place.\n");

    printf("For small nearly sorted data, insertion sort can be effective.\n");
    printf("For predictable O(n log n) sorting, merge sort is useful.\n");
    printf("Quick sort is often fast in practice but has a worst case of O(n^2).\n");

    return 0;
}
