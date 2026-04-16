#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Dlist;

// list
int create_list(char *str, Dlist **head, Dlist **tail);
void insert_at_last(Dlist **head, Dlist **tail, int data);
void insert_at_first(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);

// operations
Dlist* add_list(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);
Dlist* sub_list(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);
Dlist* multiply_list(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);
Dlist* divide_list(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);

#endif