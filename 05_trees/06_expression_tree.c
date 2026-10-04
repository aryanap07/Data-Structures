#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(char value)
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

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL || root->right != NULL)
    {
        printf("(");
    }

    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);

    if (root->left != NULL || root->right != NULL)
    {
        printf(")");
    }
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
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
    Node *plus = create_node('+');
    Node *multiply = create_node('*');
    Node *two = create_node('2');
    Node *three = create_node('3');
    Node *four = create_node('4');

    if (plus == NULL || multiply == NULL || two == NULL ||
        three == NULL || four == NULL)
    {
        free_tree(plus);
        free_tree(multiply);
        free_tree(two);
        free_tree(three);
        free_tree(four);
        return 1;
    }

    plus->left = multiply;
    plus->right = four;
    multiply->left = two;
    multiply->right = three;

    printf("Infix: ");
    inorder(plus);
    printf("\nPostfix: ");
    postorder(plus);
    printf("\n");

    free_tree(plus);

    return 0;
}
