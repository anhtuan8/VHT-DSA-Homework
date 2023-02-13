//
//  linked_list.c
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

node* create_node(const int data)
{
    node *n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}
int is_empty(node* const head)
{
    return head == NULL;
}

void add_head(node **head, const int data)
{
    node *n = create_node(data);
    if (is_empty(*head)) *head = n;
    else
    {
        n->next = *head;
        *head = n;
    }
    
}
void remove_head(node **head)
{
    if (is_empty(*head)) return;
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        node *p = *head;
        *head = p->next;
        free(p);
    }
}

void print_list(node* const head)
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

void clear_list(node **head)
{
    if (is_empty(*head)) return;
    while (*head != NULL)
    {
        node *p = *head;
        *head = p->next;
        free(p);
    }
}
