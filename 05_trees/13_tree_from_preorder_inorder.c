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

int find_index(const int inorder[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == value)
        {
            return i;
        }
    }

    return -1;
}

Node *build_tree(
    const int preorder[],
    const int inorder[],
    int *preorder_index,
    int inorder_start,
    int inorder_end)
{
    if (inorder_start > inorder_end)
    {
        return NULL;
    }

    Node *root = create_node(preorder[*preorder_index]);
    (*preorder_index)++;

    int index = find_index(
        inorder,
        inorder_start,
        inorder_end,
        root->data
    );

    if (index == -1)
    {
        free(root);
        return NULL;
    }

    root->left = build_tree(
        preorder,
        inorder,
        preorder_index,
        inorder_start,
        index - 1
    );

    root->right = build_tree(
        preorder,
        inorder,
        preorder_index,
        index + 1,
        inorder_end
    );

    return root;
}

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
    const int preorder[] = {1, 2, 4, 5, 3};
    const int inorder[] = {4, 2, 5, 1, 3};
    int length = sizeof(inorder) / sizeof(inorder[0]);
    int preorder_index = 0;

    Node *root = build_tree(
        preorder,
        inorder,
        &preorder_index,
        0,
        length - 1
    );

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    free_tree(root);

    return 0;
}
