#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME 20

typedef struct str_student {
    char    name[20];
    int     birth_year;
    float   grade;
} student;

typedef struct str_student_list {
    student list[MAX_STUDENTS];
    int     number;
} student_list;

void init_students(student_list *students);
void add_student(student_list *students);
void print_students(student_list *students);
void edit_student(student_list *students);
void delete_student(student_list *students);
student* search_student(student_list *students, char *name);


#endif