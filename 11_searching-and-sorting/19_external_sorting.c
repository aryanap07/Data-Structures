#include <stdio.h>
#include <stdlib.h>

int next_value(FILE *file, int *value)
{
    return fscanf(file, "%d", value) == 1;
}

void merge_files(
    const char *first_name,
    const char *second_name,
    const char *output_name)
{
    FILE *first = fopen(first_name, "r");
    FILE *second = fopen(second_name, "r");
    FILE *output = fopen(output_name, "w");

    if (first == NULL || second == NULL || output == NULL)
    {
        if (first != NULL)
        {
            fclose(first);
        }

        if (second != NULL)
        {
            fclose(second);
        }

        if (output != NULL)
        {
            fclose(output);
        }

        return;
    }

    int first_value;
    int second_value;
    int has_first = next_value(first, &first_value);
    int has_second = next_value(second, &second_value);

    while (has_first && has_second)
    {
        if (first_value <= second_value)
        {
            fprintf(output, "%d ", first_value);
            has_first = next_value(first, &first_value);
        }
        else
        {
            fprintf(output, "%d ", second_value);
            has_second = next_value(second, &second_value);
        }
    }

    while (has_first)
    {
        fprintf(output, "%d ", first_value);
        has_first = next_value(first, &first_value);
    }

    while (has_second)
    {
        fprintf(output, "%d ", second_value);
        has_second = next_value(second, &second_value);
    }

    fclose(first);
    fclose(second);
    fclose(output);
}

void print_file(const char *name)
{
    FILE *file = fopen(name, "r");

    if (file == NULL)
    {
        return;
    }

    int value;

    while (fscanf(file, "%d", &value) == 1)
    {
        printf("%d ", value);
    }

    printf("\n");
    fclose(file);
}

int main(void)
{
    const char *first_name = "run1.txt";
    const char *second_name = "run2.txt";
    const char *output_name = "sorted.txt";

    FILE *first = fopen(first_name, "w");
    FILE *second = fopen(second_name, "w");

    if (first == NULL || second == NULL)
    {
        if (first != NULL)
        {
            fclose(first);
        }

        if (second != NULL)
        {
            fclose(second);
        }

        return 1;
    }

    fprintf(first, "2 8 15 21 ");
    fprintf(second, "1 5 11 30 ");

    fclose(first);
    fclose(second);

    merge_files(first_name, second_name, output_name);

    printf("Merged sorted data: ");
    print_file(output_name);

    remove(first_name);
    remove(second_name);
    remove(output_name);

    return 0;
}
