#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

int max(int a, int b) {
    return a > b ? a : b;
}

int height(Node *root) {
    return root == NULL ? 0 : root->height;
}

Node *create_node(int data) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void update_height(Node *root) {
    root->height = 1 + max(height(root->left), height(root->right));
}

int balance_factor(Node *root) {
    return root == NULL ? 0 : height(root->left) - height(root->right);
}

Node *rotate_right(Node *root) {
    Node *child = root->left;
    Node *subtree = child->right;

    child->right = root;
    root->left = subtree;

    update_height(root);
    update_height(child);

    return child;
}

Node *rotate_left(Node *root) {
    Node *child = root->right;
    Node *subtree = child->left;

    child->left = root;
    root->right = subtree;

    update_height(root);
    update_height(child);

    return child;
}

Node *rebalance(Node *root) {
    update_height(root);

    int balance = balance_factor(root);

    if (balance > 1) {
        if (balance_factor(root->left) < 0)
            root->left = rotate_left(root->left);

        return rotate_right(root);
    }

    if (balance < -1) {
        if (balance_factor(root->right) > 0)
            root->right = rotate_right(root->right);

        return rotate_left(root);
    }

    return root;
}

Node *insert(Node *root, int data) {
    if (root == NULL)
        return create_node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    return rebalance(root);
}

Node *search(Node *root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

Node *find_min(Node *root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node *find_max(Node *root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

Node *delete(Node *root, int data) {
    if (root == NULL)
        return NULL;

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            Node *right = root->right;
            free(root);
            return right;
        }

        if (root->right == NULL) {
            Node *left = root->left;
            free(root);
            return left;
        }

        Node *successor = find_min(root->right);
        root->data = successor->data;
        root->right = delete(root->right, successor->data);
    }

    return rebalance(root);
}

void inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

size_t size(Node *root) {
    if (root == NULL)
        return 0;

    return 1 + size(root->left) + size(root->right);
}

void destroy(Node **root) {
    if (*root == NULL)
        return;

    destroy(&(*root)->left);
    destroy(&(*root)->right);

    free(*root);
    *root = NULL;
}

int main(void) {
    Node *root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 35);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Height: %d\n", height(root));
    printf("Size: %zu\n", size(root));

    if (search(root, 25) != NULL)
        printf("25 found\n");
    else
        printf("25 not found\n");

    Node *minimum = find_min(root);
    Node *maximum = find_max(root);

    if (minimum != NULL)
        printf("Minimum: %d\n", minimum->data);

    if (maximum != NULL)
        printf("Maximum: %d\n", maximum->data);

    root = delete(root, 10);
    root = delete(root, 40);
    root = delete(root, 30);

    printf("Inorder after deletion: ");
    inorder(root);
    printf("\n");

    destroy(&root);

    return 0;
}
