#include "phone_management.h"
#include "util.h"

void print_menu()
{
    printf("1. Add phone\n");
    printf("2. Remove phone by product ID\n");
    printf("3. Edit phone remains by product ID\n");
    printf("4. Find products by price\n");
    printf("5. Print all products\n");
    printf("6. Exit\n");
}

int main() 
{
    int running = 1;
    node* phone_list = NULL;
    while (running)
    {
        print_menu();
        int choice;
        input_int("Enter your choice", &choice);

        switch (choice)
        {
            case 1: add_phone(&phone_list); break;
            case 2: remove_phone(phone_list); break;
            case 3: edit_phone_remain(phone_list); break;
            case 4: find_products_by_price(phone_list); break;
            case 5: print_phone(phone_list); break;
            case 6: running = 0; break;
            default: printf("Invalid choice!\n");
        }
    }

}
