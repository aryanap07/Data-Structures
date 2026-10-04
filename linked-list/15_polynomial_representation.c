#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
} Term;

Term *create_term(int coefficient, int exponent)
{
    Term *term = malloc(sizeof(Term));

    if (term != NULL)
    {
        term->coefficient = coefficient;
        term->exponent = exponent;
        term->next = NULL;
    }

    return term;
}

void print_polynomial(Term *head)
{
    while (head != NULL)
    {
        printf("%dx^%d", head->coefficient, head->exponent);

        if (head->next != NULL)
        {
            printf(" + ");
        }

        head = head->next;
    }

    printf("\n");
}

void free_polynomial(Term *head)
{
    while (head != NULL)
    {
        Term *next = head->next;
        free(head);
        head = next;
    }
}

int main(void)
{
    Term *first = create_term(5, 3);
    Term *second = create_term(4, 2);
    Term *third = create_term(3, 0);

    if (first == NULL || second == NULL || third == NULL)
    {
        free(first);
        free(second);
        free(third);
        return 1;
    }

    first->next = second;
    second->next = third;

    printf("Polynomial: ");
    print_polynomial(first);

    free_polynomial(first);
    return 0;
}
