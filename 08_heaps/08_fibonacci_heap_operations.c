#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct FibNode
{
    int key;
    int degree;
    int mark;
    struct FibNode *parent;
    struct FibNode *child;
    struct FibNode *left;
    struct FibNode *right;
} FibNode;

typedef struct
{
    FibNode *minimum;
    int size;
} FibonacciHeap;

FibNode *create_node(int key)
{
    FibNode *node = malloc(sizeof(FibNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->key = key;
    node->degree = 0;
    node->mark = 0;
    node->parent = NULL;
    node->child = NULL;
    node->left = node;
    node->right = node;

    return node;
}

void add_to_root_list(FibonacciHeap *heap, FibNode *node)
{
    if (heap->minimum == NULL)
    {
        node->left = node;
        node->right = node;
        heap->minimum = node;
        return;
    }

    FibNode *minimum = heap->minimum;

    node->left = minimum;
    node->right = minimum->right;
    minimum->right->left = node;
    minimum->right = node;

    if (node->key < heap->minimum->key)
    {
        heap->minimum = node;
    }
}

void insert(FibonacciHeap *heap, int key)
{
    FibNode *node = create_node(key);

    if (node == NULL)
    {
        return;
    }

    add_to_root_list(heap, node);
    heap->size++;
}

void remove_from_list(FibNode *node)
{
    node->left->right = node->right;
    node->right->left = node->left;
    node->left = node;
    node->right = node;
}

FibNode *minimum_node(FibonacciHeap *heap)
{
    return heap->minimum;
}

void free_node_tree(FibNode *node)
{
    if (node == NULL)
    {
        return;
    }

    FibNode *start = node;
    FibNode *current = start;

    do
    {
        FibNode *next = current->right;
        free_node_tree(current->child);
        free(current);
        current = next;
    } while (current != start);
}

int extract_min(FibonacciHeap *heap)
{
    if (heap->minimum == NULL)
    {
        return INT_MIN;
    }

    FibNode *minimum = heap->minimum;

    if (minimum->right == minimum)
    {
        heap->minimum = minimum->child;
    }
    else
    {
        FibNode *next = minimum->right;
        remove_from_list(minimum);
        heap->minimum = next;
    }

    if (minimum->child != NULL)
    {
        FibNode *child = minimum->child;
        FibNode *start = child;

        do
        {
            FibNode *next = child->right;
            child->parent = NULL;
            remove_from_list(child);
            add_to_root_list(heap, child);
            child = next;
        } while (child != start);
    }

    if (heap->minimum != NULL)
    {
        FibNode *current = heap->minimum;
        FibNode *start = current;

        do
        {
            if (current->key < heap->minimum->key)
            {
                heap->minimum = current;
            }

            current = current->right;
        } while (current != start);
    }

    int value = minimum->key;
    free(minimum);
    heap->size--;

    return value;
}

void free_heap(FibonacciHeap *heap)
{
    if (heap->minimum == NULL)
    {
        return;
    }

    FibNode *current = heap->minimum;
    FibNode *start = current;

    do
    {
        FibNode *next = current->right;

        if (current->child != NULL)
        {
            free_node_tree(current->child);
        }

        free(current);
        current = next;
    } while (current != start);

    heap->minimum = NULL;
    heap->size = 0;
}

int main(void)
{
    FibonacciHeap heap = {
        .minimum = NULL,
        .size = 0
    };

    insert(&heap, 30);
    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 5);

    FibNode *minimum = minimum_node(&heap);

    if (minimum != NULL)
    {
        printf("Minimum: %d\n", minimum->key);
    }

    printf("Extracted: %d\n", extract_min(&heap));

    minimum = minimum_node(&heap);

    if (minimum != NULL)
    {
        printf("New minimum: %d\n", minimum->key);
    }

    free_heap(&heap);

    return 0;
}
