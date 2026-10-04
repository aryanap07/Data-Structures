#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(void)
{
    Node n4 = {4, NULL, NULL};
    Node n5 = {5, NULL, NULL};
    Node n2 = {2, &n4, &n5};
    Node n3 = {3, NULL, NULL};
    Node n1 = {1, &n2, &n3};

    postorder(&n1);
    printf("\n");

    return 0;
}
