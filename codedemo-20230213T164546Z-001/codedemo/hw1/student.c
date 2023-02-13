#include "student.h"
#include "util.h"

void init_students(student_list *students)
{
    students->number = 0;
}

void add_student(student_list *students)
{
    if (students->number == MAX_STUDENTS)
    {
        printf("Cannot add more students!\n");
        return;
    }

    printf("Enter student information ...\n");
    input_string("Full name", students->list[students->number].name);
    input_int("Year of birth", &students->list[students->number].birth_year);
    input_float("Grade", &students->list[students->number].grade);

    students->number++;
}

void print_students(student_list *students)
{
    printf("Student list:\n");
    for (int i = 0; i < students->number; i++)
    {
        printf("%20s, %5d, %5.2f\n", students->list[i].name, 
                             students->list[i].birth_year, 
                             students->list[i].grade);
    }
}

student* search_student(student_list *students, char *name)
{
    for (int i = 0; i < students->number; i++)
    {
        if (strcmp(students->list[i].name, name) == 0)
        {
            return students->list + i;
        }
    }
    return NULL;
}

void edit_student(student_list *students)
{
    char name[MAX_NAME];
    int year;
    float grade;

    input_string("Enter student name to search", name);

    student *s = search_student(students, name);
    if (s == NULL)
    {
        printf("Student not found!\n");
        return;
    }
    printf("Edit student information...\n");

    input_string("Full name", name);
    if (strcmp(name, "") != 0) strcpy(s->name, name);
    
    input_int("Year of birth", &year);
    if (year != 0) s->birth_year = year;

    input_float("Grade", &grade);
    if (grade != 0) s->grade = grade;
}

void delete_student(student_list *students)
{
    char name[MAX_NAME];
    input_string("Enter student name to search", name);

    student *s = search_student(students, name);
    if (s == NULL)
    {
        printf("Student not found!\n");
        return;
    }

    for (int i = s - students->list; i < students->number - 1; i++)
    {
        students->list[i] = students->list[i + 1];
    }
    students->number--;
}