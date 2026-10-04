#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct BinomialNode
{
    int key;
    int degree;
    struct BinomialNode *parent;
    struct BinomialNode *child;
    struct BinomialNode *sibling;
} BinomialNode;

typedef struct
{
    BinomialNode *head;
} BinomialHeap;

BinomialNode *create_node(int key)
{
    BinomialNode *node = malloc(sizeof(BinomialNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->key = key;
    node->degree = 0;
    node->parent = NULL;
    node->child = NULL;
    node->sibling = NULL;

    return node;
}

BinomialNode *merge_root_lists(
    BinomialNode *first,
    BinomialNode *second)
{
    BinomialNode *head = NULL;
    BinomialNode **tail = &head;

    while (first != NULL && second != NULL)
    {
        if (first->degree <= second->degree)
        {
            *tail = first;
            first = first->sibling;
        }
        else
        {
            *tail = second;
            second = second->sibling;
        }

        tail = &(*tail)->sibling;
    }

    *tail = first != NULL ? first : second;

    return head;
}

void link_tree(BinomialNode *child, BinomialNode *parent)
{
    child->parent = parent;
    child->sibling = parent->child;
    parent->child = child;
    parent->degree++;
}

BinomialHeap union_heaps(BinomialHeap first, BinomialHeap second)
{
    BinomialHeap result = {
        .head = merge_root_lists(first.head, second.head)
    };

    if (result.head == NULL)
    {
        return result;
    }

    BinomialNode *previous = NULL;
    BinomialNode *current = result.head;
    BinomialNode *next = current->sibling;

    while (next != NULL)
    {
        if (current->degree != next->degree ||
            (next->sibling != NULL &&
             next->sibling->degree == current->degree))
        {
            previous = current;
            current = next;
        }
        else if (current->key <= next->key)
        {
            current->sibling = next->sibling;
            link_tree(next, current);
        }
        else
        {
            if (previous == NULL)
            {
                result.head = next;
            }
            else
            {
                previous->sibling = next;
            }

            link_tree(current, next);
            current = next;
        }

        next = current->sibling;
    }

    return result;
}

void insert(BinomialHeap *heap, int key)
{
    BinomialHeap single = {.head = create_node(key)};
    BinomialHeap result = union_heaps(*heap, single);

    heap->head = result.head;
}

BinomialNode *find_min(BinomialHeap *heap)
{
    if (heap->head == NULL)
    {
        return NULL;
    }

    BinomialNode *minimum = heap->head;
    BinomialNode *current = heap->head->sibling;

    while (current != NULL)
    {
        if (current->key < minimum->key)
        {
            minimum = current;
        }

        current = current->sibling;
    }

    return minimum;
}

int extract_min(BinomialHeap *heap)
{
    BinomialNode *minimum = find_min(heap);

    if (minimum == NULL)
    {
        return INT_MIN;
    }

    BinomialNode *previous = NULL;
    BinomialNode *current = heap->head;

    while (current != minimum)
    {
        previous = current;
        current = current->sibling;
    }

    if (previous == NULL)
    {
        heap->head = minimum->sibling;
    }
    else
    {
        previous->sibling = minimum->sibling;
    }

    BinomialNode *child = minimum->child;
    BinomialNode *reversed = NULL;

    while (child != NULL)
    {
        BinomialNode *next = child->sibling;
        child->parent = NULL;
        child->sibling = reversed;
        reversed = child;
        child = next;
    }

    BinomialHeap children = {.head = reversed};
    BinomialHeap combined = union_heaps(*heap, children);
    heap->head = combined.head;

    int value = minimum->key;
    free(minimum);

    return value;
}

void free_heap(BinomialHeap *heap)
{
    while (heap->head != NULL)
    {
        BinomialNode *root = heap->head;
        heap->head = root->sibling;
        free_tree:
        if (root->child != NULL)
        {
            BinomialNode *stack[64];
            int top = 0;
            stack[top++] = root->child;

            while (top > 0)
            {
                BinomialNode *node = stack[--top];

                if (node->child != NULL)
                {
                    stack[top++] = node->child;
                }

                if (node->sibling != NULL)
                {
                    stack[top++] = node->sibling;
                }

                free(node);
            }
        }

        free(root);
    }
}

int main(void)
{
    BinomialHeap heap = {.head = NULL};

    insert(&heap, 20);
    insert(&heap, 5);
    insert(&heap, 15);
    insert(&heap, 10);

    BinomialNode *minimum = find_min(&heap);

    if (minimum != NULL)
    {
        printf("Minimum: %d\n", minimum->key);
    }

    printf("Extracted: %d\n", extract_min(&heap));

    minimum = find_min(&heap);

    if (minimum != NULL)
    {
        printf("New minimum: %d\n", minimum->key);
    }

    free_heap(&heap);

    return 0;
}
