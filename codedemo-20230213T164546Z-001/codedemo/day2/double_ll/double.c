#include "double.h"

node *create_node(const int data)
{
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void add_tail(node **head, const int data)
{
    node *n = create_node(data);
    if (is_empty(*head)) *head = n;
    else
    {
        // find the last node
        // set next of last node to n
        // set prev of n to last node
    }
}

void remove_tail(node **head)
{
    // nothing to remove just return
    // only 1 node
        // free the node
        // set head to NULL
    // more than 1 node
        // find the last node
        // set next of last-1 node to NULL
        // free last node
}
node* find_node(node * const head, const int data)
{
    node *p = head;
    // search for node with data
    // if found return the node
    // else return NULL
    return NULL;

}
int is_empty(node * const head)
{
    return head == NULL;
}

void print_list(node * const head)
{
    node *p = head;
    while (p != NULL)
    {
        printf("%d <-> ", p->data);
        p = p->next;
    }
    printf("\n");
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