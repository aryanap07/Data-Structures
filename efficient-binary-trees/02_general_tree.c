#include <stdio.h>

#define CHILDREN 3

typedef struct Node
{
    int data;
    struct Node *child[CHILDREN];
} Node;

int main(void)
{
    Node root = {1, {NULL, NULL, NULL}};
    Node a = {2, {NULL, NULL, NULL}};
    Node b = {3, {NULL, NULL, NULL}};
    Node c = {4, {NULL, NULL, NULL}};

    root.child[0] = &a;
    root.child[1] = &b;
    root.child[2] = &c;

    printf("Root: %d\n", root.data);

    for (int i = 0; i < CHILDREN; i++)
    {
        printf("Child %d: %d\n", i + 1, root.child[i]->data);
    }

    return 0;
}
