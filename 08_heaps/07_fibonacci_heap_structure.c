#include <stdio.h>
#include <stdlib.h>

typedef struct FibNode
{
    int key;
    int degree;
    int mark;
    struct FibNode *parent;
    struct FibNode *child;
    struct FibNode *left;
    struct FibNode *right;
} FibNode;

FibNode *create_node(int key)
{
    FibNode *node = malloc(sizeof(FibNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->key = key;
    node->degree = 0;
    node->mark = 0;
    node->parent = NULL;
    node->child = NULL;
    node->left = node;
    node->right = node;

    return node;
}

int main(void)
{
    FibNode *first = create_node(10);
    FibNode *second = create_node(20);

    if (first == NULL || second == NULL)
    {
        free(first);
        free(second);
        return 1;
    }

    first->right = second;
    second->left = first;
    second->right = first;
    first->left = second;

    printf("First key: %d\n", first->key);
    printf("Second key: %d\n", second->key);
    printf("First degree: %d\n", first->degree);
    printf("First mark: %d\n", first->mark);

    free(first);
    free(second);

    return 0;
}
