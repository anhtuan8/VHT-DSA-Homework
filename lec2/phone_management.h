#ifndef __PHONE_MANAGEMENT_H__
#define __PHONE_MANAGEMENT_H__
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
  int product_id;
  char product_name[50];
  int price;
  int remain;
} phone;

typedef struct str_node
{
  phone data;
  struct str_node *next;
  struct str_node *previous;
} node;

phone enter_phone_menu();
void add_phone (node **head);
void print_phone (const node *head);
void remove_phone (const node *head);
void edit_phone_remain(const node *head);
void find_products_by_price(const node *head);

node* find_last_node (const node *head);
node *create_node(const phone data);
void remove_node(node *remove_node);
void add_tail (node ** head, const phone data);
void print_list_from_head(node* const head);
void print_list_from_tail(node* const tail);
void add_node(node *previous_node, node *next_node, node *new_node);
int is_empty(node * const head);
node *find_node_by_ID (node * const head, const int id);
void print_node(node *p);

// void remove_tail(node **head);
// void print_list(node * const head);
// void clear_list(node **head);

#endif