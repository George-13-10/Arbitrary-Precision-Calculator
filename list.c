#include "header.h"

void insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = (Dlist *)malloc(sizeof(Dlist));

    if (new == NULL)
        return;

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
    }
}

void insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = (Dlist *)malloc(sizeof(Dlist));

    if (new == NULL)
        return;

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
}

int create_list(char *str, Dlist **head, Dlist **tail)
{
    int i = 0;

    while (str[i] != '\0')
    {
        int digit = str[i] - '0';
        insert_at_last(head, tail, digit);
        i++;
    }

    return SUCCESS;
}

void print_list(Dlist *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n"); 
}