#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(void)
{
    Node a1 = {1, NULL, NULL};
    Node a2 = {2, NULL, NULL};
    Node a3 = {3, NULL, NULL};
    Node b1 = {4, NULL, NULL};
    Node b2 = {5, NULL, NULL};

    a1.left = &a2;
    a1.right = &a3;

    b1.left = &b2;

    printf("Tree 1: ");
    preorder(&a1);

    printf("\nTree 2: ");
    preorder(&b1);

    printf("\n");

    return 0;
}
