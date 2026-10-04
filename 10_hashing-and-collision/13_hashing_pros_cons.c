#include <stdio.h>

int main(void)
{
    printf("Advantages of hashing:\n");
    printf("Fast average-case insertion, search and deletion.\n");
    printf("Direct access through a hash index.\n");
    printf("Useful for dictionaries, sets and lookup tables.\n");

    printf("\nDisadvantages of hashing:\n");
    printf("Collisions must be handled.\n");
    printf("Performance depends on hash function and load factor.\n");
    printf("Poor hashing can create long collision chains.\n");
    printf("Open addressing requires careful deletion handling.\n");

    return 0;
}
