#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(Node *root)
{
    return root == NULL ? 0 : root->height;
}

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->data = value;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int balance_factor(Node *root)
{
    return root == NULL ? 0 : height(root->left) - height(root->right);
}

Node *rotate_right(Node *y)
{
    Node *x = y->left;
    Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *rotate_left(Node *x)
{
    Node *y = x->right;
    Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
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
    else
    {
        return root;
    }

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = balance_factor(root);

    if (balance > 1 && value < root->left->data)
    {
        return rotate_right(root);
    }

    if (balance < -1 && value > root->right->data)
    {
        return rotate_left(root);
    }

    if (balance > 1 && value > root->left->data)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (balance < -1 && value < root->right->data)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

Node *search(Node *root, int value)
{
    while (root != NULL)
    {
        if (root->data == value)
        {
            return root;
        }

        root = value < root->data ? root->left : root->right;
    }

    return NULL;
}

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
    int values[] = {30, 20, 10, 25, 28, 27};
    int length = sizeof(values) / sizeof(values[0]);
    Node *root = NULL;

    for (int i = 0; i < length; i++)
    {
        root = insert(root, values[i]);
    }

    printf("AVL inorder: ");
    inorder(root);
    printf("\n");

    printf("Search 25: %s\n",
           search(root, 25) != NULL ? "Found" : "Not found");

    printf("Height: %d\n", height(root));

    free_tree(root);

    return 0;
}
