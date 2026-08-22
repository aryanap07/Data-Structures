#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct Node { 
    int data; 
    struct Node *left; 
    struct Node *right; 
} Node; 
 
Node *create_node(int data) { 
    Node *node = malloc(sizeof(Node)); 
 
    if (node == NULL) { 
        perror("malloc"); 
        exit(EXIT_FAILURE); 
    } 
 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
 
    return node; 
} 
 
Node *insert(Node *root, int data) { 
    if (root == NULL) 
        return create_node(data); 
 
    if (data < root->data) 
        root->left = insert(root->left, data); 
    else if (data > root->data) 
        root->right = insert(root->right, data); 
 
    return root; 
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
 
    return root; 
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
 
size_t height(Node *root) { 
    if (root == NULL) 
        return 0; 
 
    size_t left_height = height(root->left); 
    size_t right_height = height(root->right); 
 
    return 1 + (left_height > right_height ? left_height : right_height); 
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
 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 70); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 60); 
    root = insert(root, 80); 
 
    printf("Inorder: "); 
    inorder(root); 
    printf("\n"); 
 
    printf("Preorder: "); 
    preorder(root); 
    printf("\n"); 
 
    printf("Postorder: "); 
    postorder(root); 
    printf("\n"); 
 
    printf("Size: %zu\n", size(root)); 
    printf("Height: %zu\n", height(root)); 
 
    if (search(root, 60) != NULL) 
        printf("60 found\n"); 
    else 
        printf("60 not found\n"); 
 
    Node *minimum = find_min(root); 
    Node *maximum = find_max(root); 
 
    if (minimum != NULL) 
        printf("Minimum: %d\n", minimum->data); 
 
    if (maximum != NULL) 
        printf("Maximum: %d\n", maximum->data); 
 
    root = delete(root, 20); 
    root = delete(root, 30); 
    root = delete(root, 50); 
 
    printf("Inorder after deletion: "); 
    inorder(root); 
    printf("\n"); 
 
    destroy(&root); 
 
    return 0; 
}
