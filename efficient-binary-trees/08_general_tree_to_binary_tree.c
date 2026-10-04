#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *first_child;
    struct Node *next_sibling;
} Node;

Node *create_node(int value)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->data = value;
    node->first_child = NULL;
    node->next_sibling = NULL;

    return node;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->first_child);
    preorder(root->next_sibling);
}

void free_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->first_child);
    free_tree(root->next_sibling);
    free(root);
}

int main(void)
{
    Node *root = create_node(1);
    Node *a = create_node(2);
    Node *b = create_node(3);
    Node *c = create_node(4);
    Node *d = create_node(5);

    if (root == NULL || a == NULL || b == NULL || c == NULL || d == NULL)
    {
        free_tree(root);
        free_tree(a);
        free_tree(b);
        free_tree(c);
        free_tree(d);
        return 1;
    }

    root->first_child = a;
    a->next_sibling = b;
    b->next_sibling = c;
    a->first_child = d;

    printf("First-child next-sibling representation: ");
    preorder(root);
    printf("\n");

    free_tree(root);

    return 0;
}
