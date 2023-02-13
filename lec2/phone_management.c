/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "phone_management.h"
#include "util.h"

phone enter_phone_menu() {
    phone data;
    printf("Enter phone information....\n");
    input_int("Add phone product ID ", &data.product_id);
    input_string("Add phone name ", data.product_name);
    input_int("Add phone price ", &data.price);
    input_int("Add phone remain ", &data.remain);
    return data;
}

void add_phone (node **head)
{
    phone data = enter_phone_menu();
    node *phone_node = create_node(data);
    if (is_empty(*head)) *head = phone_node;
    else 
    {
        node *cur_node = *head;
        //find node that have price equal or higher than new phone price
        while (cur_node->next != NULL && cur_node->data.price < data.price)
        {
            cur_node = cur_node->next;
        }
        if (cur_node->next == NULL)
        {
            //reach last node
            cur_node->next = phone_node;
            phone_node->previous = cur_node;
        }
        else
        {
            //add new phone node to current node previous
            add_node(cur_node->previous, cur_node, phone_node);
        }
    }
}

void print_phone (node* const head)
{
    int choice;
    input_int("Enter your choice: 1. Ascending order, 2. Descending order", &choice);
    switch (choice)
    {
    case 1:
        //Ascending order of price
        print_list_from_head(head);
        break;
    case 2:
        //Descending order of price
        print_list_from_tail(find_last_node(head));
        break;
    default:
        break;
    }
    return;
}

void remove_phone (node* const head)
{
    int phone_id;
    input_int("Enter phone ID: ", &phone_id);
    remove_node(find_node_by_ID(head, phone_id));
}

void edit_phone_remain(node* const head)
{
    int phone_id;
    input_int("Enter phone ID: ", &phone_id);
    int new_remain;
    input_int("Enter phone remains: ", &new_remain);

    node* found_phone = find_node_by_ID(head, phone_id);
    found_phone->data.remain = new_remain;
}

void find_products_by_price(node* const head)
{
    int price;
    input_int("Enter phone price: ", &price);

    if (is_empty(head)) printf("Empty list!\n");
    else
    {
        node *p = head;
        while (p->next == NULL)
        {
            if (p->data.price <= price && p->next->data.price >= price) {
                //find the closer price
                node *found_item;
                if ((price - p->data.price) < (p->next->data.price - price)) found_item = p;
                else found_item = p->next;
                print_node(found_item);
                print_node(found_item->previous);
                print_node(found_item->next);
                return;
            }
            p = p->next;
        }
        printf("Reaches last node. Price is the highest price. Print last item\n");
        printf("");
    }
}

void print_node(node *p)
{
    if (p == NULL) return;
    phone data = p->data;
    printf("Phone info: 1. Product ID %d, 2. Product name %s, 3. Price %s, 4. Remaining %s\n", data.product_id, data.product_name, data.price, data.remain);
}

node* find_last_node (node* const head)
{
    if (is_empty(head)) return NULL;
    node *cur_node = head;
    while (cur_node->next != NULL)
    {
        cur_node = cur_node->next;
    }
    return cur_node;
}

node *create_node(const phone data)
{
    node *phone_node = (node *)malloc(sizeof(node));
    phone_node->data = data;
    phone_node->next = NULL;
    phone_node->previous = NULL;
    return phone_node;
}

void remove_node(node *remove_node)
{
    if (remove_node == NULL) return;
    else 
    {
        node *tmp = remove_node;
        if (remove_node->next != NULL) remove_node->next->previous = NULL;
        if (remove_node->previous != NULL) remove_node->previous->next = NULL;
        free(remove_node);
    }
}

void add_tail(node **head, const phone data)
{
    node *n = create_node(data);
    if (is_empty(*head))
        *head = n;
    else
    {
        node *cur_node = *head;
        while (cur_node->next != NULL)
        {
            cur_node = cur_node->next;
        }
        // end of while loop, cur_node = last node
        cur_node->next = n;
        n->previous = cur_node;
    }
}

void print_list_from_head(node* const head)
{
    if (is_empty(head)) printf("Empty list!\n");
    else
    {
        node *p = head;
        while (p != NULL)
        {
            printf("[%d]->", p->data);
            p = p->next;
        }
        printf("[]\n");
    }
}

void print_list_from_tail(node* const tail)
{
    if (is_empty(tail)) printf("Empty list!\n");
    else
    {
        node *p = tail;
        while (p != NULL)
        {
            printf("[%d]->", p->data);
            p = p->previous;
        }
        printf("[]\n");
    }
}

void add_node(node *previous_node, node *next_node, node *new_node)  
{
    previous_node->next = new_node;
    new_node->previous = previous_node;
    next_node->previous = new_node;
    new_node->next = next_node;
}

int is_empty(node *const head)
{
    return head == NULL;
}

node *find_node_by_ID (node * const head, const int id) 
{
    if (is_empty(head)) return NULL;
    else
    {
        node *p = head;
        while (p != NULL)
        {
            if ((p->data.product_id) == id) return p;
        }
        return NULL;
    }
}
