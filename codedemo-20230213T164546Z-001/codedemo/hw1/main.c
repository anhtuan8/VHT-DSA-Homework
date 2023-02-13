
#include "student.h"
#include "util.h"

void print_menu()
{
    printf("1. Add student\n");
    printf("2. Edit student\n");
    printf("3. Delete student\n");
    printf("4. Print student list\n");
    printf("5. Exit\n");
}

int main() 
{
    int running = 1;
    student_list students;
    while (running)
    {
        print_menu();
        int choice;
        input_int("Enter your choice", &choice);

        switch (choice)
        {
            case 1: add_student(&students); break;
            case 2: edit_student(&students); break;
            case 3: delete_student(&students); break;
            case 4: print_students(&students); break;
            case 5: running = 0; break;
            default: printf("Invalid choice!\n");
        }
    }

}