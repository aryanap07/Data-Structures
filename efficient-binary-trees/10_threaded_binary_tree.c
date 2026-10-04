#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int left_thread;
    int right_thread;
} Node;

Node *leftmost(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->left != NULL && !root->left_thread)
    {
        root = root->left;
    }

    return root;
}

void inorder(Node *root)
{
    Node *current = leftmost(root);

    while (current != NULL)
    {
        printf("%d ", current->data);

        if (current->right_thread)
        {
            current = current->right;
        }
        else
        {
            current = leftmost(current->right);
        }
    }
}

int main(void)
{
    Node n1 = {20, NULL, NULL, 0, 0};
    Node n2 = {10, NULL, &n1, 0, 1};
    Node n3 = {30, &n1, NULL, 1, 0};

    n1.left = &n2;
    n1.right = &n3;

    printf("Threaded inorder: ");
    inorder(&n1);
    printf("\n");

    return 0;
}
