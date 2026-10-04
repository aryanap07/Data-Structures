#include <stdio.h>

int main(void)
{
    printf("Algorithm       Best       Average      Worst       Extra Space\n");
    printf("Bubble Sort      O(n)       O(n^2)       O(n^2)      O(1)\n");
    printf("Insertion Sort   O(n)       O(n^2)       O(n^2)      O(1)\n");
    printf("Selection Sort   O(n^2)     O(n^2)       O(n^2)      O(1)\n");
    printf("Merge Sort       O(nlogn)   O(nlogn)     O(nlogn)    O(n)\n");
    printf("Quick Sort       O(nlogn)   O(nlogn)     O(n^2)      O(logn)\n");
    printf("Heap Sort        O(nlogn)   O(nlogn)     O(nlogn)    O(1)\n");
    printf("Shell Sort       depends on gap sequence                   \n");
    printf("Radix Sort       O(dn)      O(dn)        O(dn)       O(n+k)\n");
    printf("Tree Sort        O(nlogn)   O(nlogn)     O(n^2)      O(n)\n");

    return 0;
}
