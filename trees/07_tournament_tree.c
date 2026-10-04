#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_leaf(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *create_match(Node *left, Node *right)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->left = left;
    node->right = right;
    node->value = left->value > right->value ? left->value : right->value;

    return node;
}

void print_winner(Node *root)
{
    if (root != NULL)
    {
        printf("Winner: %d\n", root->value);
    }
}

void free_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void)
{
    Node *a = create_leaf(10);
    Node *b = create_leaf(25);
    Node *c = create_leaf(18);
    Node *d = create_leaf(30);

    if (a == NULL || b == NULL || c == NULL || d == NULL)
    {
        free_tree(a);
        free_tree(b);
        free_tree(c);
        free_tree(d);
        return 1;
    }

    Node *left_match = create_match(a, b);
    Node *right_match = create_match(c, d);

    if (left_match == NULL || right_match == NULL)
    {
        free_tree(left_match);
        free_tree(right_match);
        return 1;
    }

    Node *root = create_match(left_match, right_match);

    if (root == NULL)
    {
        free_tree(left_match);
        free_tree(right_match);
        return 1;
    }

    print_winner(root);
    free_tree(root);

    return 0;
}
