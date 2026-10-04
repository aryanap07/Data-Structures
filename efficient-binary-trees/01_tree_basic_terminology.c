#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

int main(void)
{
    Node root = {1, NULL, NULL};
    Node left = {2, NULL, NULL};
    Node right = {3, NULL, NULL};

    root.left = &left;
    root.right = &right;

    printf("Root: %d\n", root.data);
    printf("Left child: %d\n", root.left->data);
    printf("Right child: %d\n", root.right->data);

    return 0;
}
