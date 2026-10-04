#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return create_node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

Node *smallest(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
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
    int values[] = {50, 30, 70, 20, 40};
    int length = sizeof(values) / sizeof(values[0]);
    Node *root = NULL;

    for (int i = 0; i < length; i++)
    {
        root = insert(root, values[i]);
    }

    Node *node = smallest(root);

    if (node != NULL)
    {
        printf("Smallest node: %d\n", node->data);
    }

    free_tree(root);

    return 0;
}
