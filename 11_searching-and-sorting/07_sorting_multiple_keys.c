#include <stdio.h>

typedef struct
{
    int marks;
    int age;
    char name[20];
} Student;

void sort_students(Student students[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            int swap = 0;

            if (students[j].marks < students[j + 1].marks)
            {
                swap = 1;
            }
            else if (students[j].marks == students[j + 1].marks &&
                     students[j].age > students[j + 1].age)
            {
                swap = 1;
            }

            if (swap)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    Student students[] = {
        {85, 20, "A"},
        {90, 21, "B"},
        {90, 19, "C"},
        {75, 22, "D"}
    };

    int length = sizeof(students) / sizeof(students[0]);

    sort_students(students, length);

    for (int i = 0; i < length; i++)
    {
        printf("%s %d %d\n",
               students[i].name,
               students[i].marks,
               students[i].age);
    }

    return 0;
}
