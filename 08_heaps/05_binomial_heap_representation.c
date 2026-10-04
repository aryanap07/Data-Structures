#include <stdio.h>
#include <stdlib.h>

typedef struct BinomialNode
{
    int key;
    int degree;
    struct BinomialNode *parent;
    struct BinomialNode *child;
    struct BinomialNode *sibling;
} BinomialNode;

BinomialNode *create_node(int key)
{
    BinomialNode *node = malloc(sizeof(BinomialNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->key = key;
    node->degree = 0;
    node->parent = NULL;
    node->child = NULL;
    node->sibling = NULL;

    return node;
}

void print_tree(BinomialNode *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->key);
    print_tree(root->child);
    print_tree(root->sibling);
}

void free_tree(BinomialNode *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->child);
    free_tree(root->sibling);
    free(root);
}

int main(void)
{
    BinomialNode *root = create_node(10);
    BinomialNode *child = create_node(20);

    if (root == NULL || child == NULL)
    {
        free(root);
        free(child);
        return 1;
    }

    root->child = child;
    child->parent = root;
    root->degree = 1;

    printf("Binomial tree: ");
    print_tree(root);
    printf("\nDegree: %d\n", root->degree);

    free_tree(root);

    return 0;
}
