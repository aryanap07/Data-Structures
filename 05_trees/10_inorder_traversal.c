#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(void)
{
    Node n4 = {4, NULL, NULL};
    Node n5 = {5, NULL, NULL};
    Node n2 = {2, &n4, &n5};
    Node n3 = {3, NULL, NULL};
    Node n1 = {1, &n2, &n3};

    inorder(&n1);
    printf("\n");

    return 0;
}
