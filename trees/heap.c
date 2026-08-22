#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Heap;

Heap *create_heap(size_t capacity) {
    Heap *heap = malloc(sizeof(*heap));

    if (heap == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    heap->data = malloc(capacity * sizeof(*heap->data));

    if (heap->data == NULL) {
        free(heap);
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

void destroy_heap(Heap **heap) {
    if (heap == NULL || *heap == NULL)
        return;

    free((*heap)->data);
    free(*heap);
    *heap = NULL;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void resize_heap(Heap *heap) {
    if (heap->size < heap->capacity)
        return;

    size_t new_capacity = heap->capacity == 0 ? 1 : heap->capacity * 2;
    int *data = realloc(heap->data, new_capacity * sizeof(*data));

    if (data == NULL) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }

    heap->data = data;
    heap->capacity = new_capacity;
}

void heapify_up(Heap *heap, size_t index) {
    while (index > 0) {
        size_t parent = (index - 1) / 2;

        if (heap->data[parent] >= heap->data[index])
            break;

        swap(&heap->data[parent], &heap->data[index]);
        index = parent;
    }
}

void heapify_down(Heap *heap, size_t index) {
    while (1) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t largest = index;

        if (left < heap->size && heap->data[left] > heap->data[largest])
            largest = left;

        if (right < heap->size && heap->data[right] > heap->data[largest])
            largest = right;

        if (largest == index)
            break;

        swap(&heap->data[index], &heap->data[largest]);
        index = largest;
    }
}

void insert(Heap *heap, int value) {
    resize_heap(heap);

    heap->data[heap->size] = value;
    heapify_up(heap, heap->size);
    heap->size++;
}

int peek(const Heap *heap) {
    if (heap->size == 0) {
        fprintf(stderr, "Heap is empty\n");
        exit(EXIT_FAILURE);
    }

    return heap->data[0];
}

int extract_max(Heap *heap) {
    if (heap->size == 0) {
        fprintf(stderr, "Heap is empty\n");
        exit(EXIT_FAILURE);
    }

    int max = heap->data[0];

    heap->size--;

    if (heap->size > 0) {
        heap->data[0] = heap->data[heap->size];
        heapify_down(heap, 0);
    }

    return max;
}

void build_heap(Heap *heap, const int *data, size_t size) {
    if (size > heap->capacity) {
        int *new_data = realloc(heap->data, size * sizeof(*new_data));

        if (new_data == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        heap->data = new_data;
        heap->capacity = size;
    }

    for (size_t i = 0; i < size; i++)
        heap->data[i] = data[i];

    heap->size = size;

    if (size == 0)
        return;

    for (size_t i = size / 2; i > 0; i--)
        heapify_down(heap, i - 1);
}

size_t size(const Heap *heap) {
    return heap->size;
}

int is_empty(const Heap *heap) {
    return heap->size == 0;
}

void display(const Heap *heap) {
    for (size_t i = 0; i < heap->size; i++)
        printf("%d ", heap->data[i]);

    printf("\n");
}

void heap_sort(int *data, size_t size) {
    if (size < 2)
        return;

    Heap *heap = create_heap(size);
    build_heap(heap, data, size);

    for (size_t i = size; i > 1; i--) {
        swap(&heap->data[0], &heap->data[i - 1]);
        heap->size--;
        heapify_down(heap, 0);
    }

    for (size_t i = 0; i < size; i++)
        data[i] = heap->data[i];

    destroy_heap(&heap);
}

int main(void) {
    Heap *heap = create_heap(8);

    insert(heap, 40);
    insert(heap, 20);
    insert(heap, 60);
    insert(heap, 10);
    insert(heap, 80);
    insert(heap, 30);
    insert(heap, 50);

    printf("Heap: ");
    display(heap);

    printf("Maximum: %d\n", peek(heap));

    printf("Extracted: %d\n", extract_max(heap));

    printf("Heap after extraction: ");
    display(heap);

    printf("Size: %zu\n", size(heap));

    printf("Is empty: %s\n", is_empty(heap) ? "Yes" : "No");

    int values[] = {35, 15, 55, 25, 75, 45, 65};

    build_heap(heap, values, sizeof(values) / sizeof(values[0]));

    printf("Built heap: ");
    display(heap);

    int sorted[] = {40, 10, 70, 20, 60, 30, 50};

    heap_sort(sorted, sizeof(sorted) / sizeof(sorted[0]));

    printf("Heap sort: ");

    for (size_t i = 0; i < sizeof(sorted) / sizeof(sorted[0]); i++)
        printf("%d ", sorted[i]);

    printf("\n");

    destroy_heap(&heap);

    return 0;
}
