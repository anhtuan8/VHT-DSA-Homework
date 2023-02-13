#ifndef __DOUBLE_H__
#define __DOUBLE_H__
#include <stdlib.h>

typedef struct str_node {
    int data;
    struct str_node *next;
    struct str_node *prev;
} node;

node *create_node(const int data);
void add_tail(node **head, const int data);
void remove_tail(node **head);
int is_empty(node * const head);
void print_list(node * const head);
void clear_list(node **head);
node* find_node(node * const head, const int data);

#endif