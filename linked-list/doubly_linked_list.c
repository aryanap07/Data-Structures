#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void insert_at_beginning(Node **head, int data) {
    Node *node = create_node(data);

    node->next = *head;

    if (*head != NULL)
        (*head)->prev = node;

    *head = node;
}

void insert_at_end(Node **head, int data) {
    Node *node = create_node(data);

    if (*head == NULL) {
        *head = node;
        return;
    }

    Node *current = *head;

    while (current->next != NULL)
        current = current->next;

    current->next = node;
    node->prev = current;
}

void insert_at_position(Node **head, int data, size_t position) {
    if (position == 0) {
        insert_at_beginning(head, data);
        return;
    }

    Node *current = *head;

    for (size_t i = 0; current != NULL && i < position - 1; i++)
        current = current->next;

    if (current == NULL)
        return;

    Node *node = create_node(data);

    node->next = current->next;
    node->prev = current;

    if (current->next != NULL)
        current->next->prev = node;

    current->next = node;
}

void delete_from_beginning(Node **head) {
    if (*head == NULL)
        return;

    Node *temp = *head;
    *head = temp->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

void delete_from_end(Node **head) {
    if (*head == NULL)
        return;

    Node *current = *head;

    while (current->next != NULL)
        current = current->next;

    if (current->prev != NULL)
        current->prev->next = NULL;
    else
        *head = NULL;

    free(current);
}

void delete_at_position(Node **head, size_t position) {
    if (*head == NULL)
        return;

    if (position == 0) {
        delete_from_beginning(head);
        return;
    }

    Node *current = *head;

    for (size_t i = 0; current != NULL && i < position; i++)
        current = current->next;

    if (current == NULL)
        return;

    if (current->prev != NULL)
        current->prev->next = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
}

Node *search(Node *head, int data) {
    for (Node *current = head; current != NULL; current = current->next) {
        if (current->data == data)
            return current;
    }

    return NULL;
}

size_t length(Node *head) {
    size_t count = 0;

    for (Node *current = head; current != NULL; current = current->next)
        count++;

    return count;
}

void reverse(Node **head) {
    Node *current = *head;
    Node *new_head = NULL;

    while (current != NULL) {
        Node *next = current->next;

        current->next = current->prev;
        current->prev = next;

        new_head = current;
        current = next;
    }

    *head = new_head;
}

void display_forward(Node *head) {
    for (Node *current = head; current != NULL; current = current->next)
        printf("%d <-> ", current->data);

    printf("NULL\n");
}

void display_backward(Node *head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    Node *current = head;

    while (current->next != NULL)
        current = current->next;

    for (; current != NULL; current = current->prev)
        printf("%d <-> ", current->data);

    printf("NULL\n");
}

void destroy(Node **head) {
    while (*head != NULL) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main(void) {
    Node *head = NULL;

    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);

    insert_at_beginning(&head, 5);
    insert_at_position(&head, 15, 2);

    display_forward(head);
    display_backward(head);

    delete_from_beginning(&head);
    delete_from_end(&head);
    delete_at_position(&head, 1);

    display_forward(head);

    printf("Length: %zu\n", length(head));

    if (search(head, 20) != NULL)
        printf("20 found\n");

    reverse(&head);

    display_forward(head);
    display_backward(head);

    destroy(&head);

    return 0;
}
