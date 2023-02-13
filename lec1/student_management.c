#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_STUDENTS_LIST_SIZE = 100;
const int MAX_STUDENT_NAME_LEN = 100;

typedef struct
{
    char name[100];
    int birth_year;
    float gpa;
} student_info;

int input_student(student_info students[], int cur_size);
void show_student(student_info students[], int cur_size);
int remove_student(student_info students[], int cur_size);
void edit_student(student_info students[], int cur_size);

int main(int argc, char* argv[]) {
    int cur_size = 0;
    student_info students[MAX_STUDENTS_LIST_SIZE];
    printf("===============  Welcome to Student Management  ===============\n");
    while (1)
    {
        int selected_function;
        fflush(stdin);
        fflush(stdout);
        printf("1. Input student\t2. Remove student\t3. Edit student\t4. Show all students\t5. Exit\n");
        printf("Select function: ");
        scanf("%d", &selected_function);
        switch (selected_function)
        {
        case 1:
            if (cur_size >= MAX_STUDENTS_LIST_SIZE) {
                printf("Students list reaches maximum size. Please select another function.\n");
                continue;
            }
            cur_size = input_student(students, cur_size);
            break;
        case 2:
            cur_size = remove_student(students, cur_size);
            break;
        case 3:
            edit_student(students, cur_size);
            break;
        case 4:
            show_student(students, cur_size);
            break;
        case 5:
            printf("\nGood bye.\n");
            return 0;
        default:
            break;
        }
    }
    return 0;
}

int input_student(student_info students[], int cur_size) {
    printf("current size: %d", cur_size);
    char *name = (char*) malloc(sizeof(char) * MAX_STUDENT_NAME_LEN);
    int birth_year;
    float gpa;

    int new_size;

    //student info input
    printf("Selected input student function. Please enter student info\n");
    printf("Student name: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%[^\n]s", name);
    printf("\nStudent year of birth: ");
    scanf("%d", &birth_year);
    printf("\nStudent GPA: ");
    scanf("%f", &gpa);
    printf("\n");

    //add to students list
    student_info new_student;
    strcpy(new_student.name, name);
    new_student.birth_year = birth_year;
    new_student.gpa = gpa;

    students[cur_size] = new_student;
    cur_size++;
    return cur_size;
}

int remove_student(student_info students[], int cur_size) {
    int student_id;
    int selected_method;
    int new_size;
    printf("\nSelected remove student function");
    printf("Enter student id: ");
    fflush(stdin);
    scanf("%d", &student_id);
    printf("Remove student id %d ...\n", student_id);
    for (int i = 0; i < cur_size; i++)
    {
        printf("i: %d\n", i);
        if (i == student_id - 1) {
            printf("i == student_id - 1 %d %d\n", i, student_id);
            for (int j = i; j < cur_size - 1; j++) {
                students[j] = students [j + 1];
            }
            new_size = cur_size - 1;
        }
    }
    printf("new size %d", new_size);
    for (int i = 0; i < new_size; i++) {
        printf("%s", students[i].name);
    }
    return new_size;
}

void edit_student(student_info students[], int cur_size) {
    int student_id;
    printf("Input student id: ");
    fflush(stdin);
    scanf("%d", &student_id);
    if (student_id > 0 && student_id < MAX_STUDENTS_LIST_SIZE) {
        char name[MAX_STUDENT_NAME_LEN];
        int birth_year;
        float gpa;

        printf("Student name: ");
        fflush(stdin);
        fflush(stdout);
        scanf("%[^\n]s", name);
        printf("\nStudent year of birth: ");
        scanf("%d", &birth_year);
        printf("\nStudent GPA: ");
        scanf("%f", &gpa);
        printf("\n");

        strcpy(students[student_id - 1].name, name);
        students[student_id - 1].birth_year = birth_year;
        students[student_id - 1].gpa = gpa;
    }
}

void show_student(student_info students[], int cur_size) {
    //student info show
    printf("\nSelected show student function.\n");
    printf("\n%-7s%-35s%-25s%-10s\n", "No", "Full name", "Year of birth", "GPA");
    for (int i = 0; i < cur_size; i++)
    {
        printf("%-7d%-35s%-25d%-10.2f\n", i + 1, students[i].name, students[i].birth_year, students[i].gpa);
    }
    printf("\n");
}

// student_info* concat_students_array(student_info students, int index) {
//     student_info students[MAX_STUDENTS_LIST_SIZE];
//     for(int i = 0; i < arr1_len; i++) {
//         students[i] = arr1[i];
//     }
//     for (int i = 0, j = arr1_len; i < arr2_len && j < arr1_len + arr2_len; i++, j++) {
//         students[j] = arr2[i];
//     }
//     return students
// }