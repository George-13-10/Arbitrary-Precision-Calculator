#include "header.h"

Dlist* sub_list(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    Dlist *result_head = NULL;
    Dlist *result_tail = NULL;

    int borrow = 0;

    while (tail1 != NULL || tail2 != NULL)
    {
        int d1 = 0, d2 = 0;

        if (tail1 != NULL)
        {
            d1 = tail1->data;
            tail1 = tail1->prev;
        }

        if (tail2 != NULL)
        {
            d2 = tail2->data;
            tail2 = tail2->prev;
        }

        d1 = d1 - borrow;

        if (d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        insert_at_first(&result_head, &result_tail, d1 - d2);
    }

    //Remove leading zeros
    while (result_head != NULL && result_head->data == 0 && result_head->next != NULL)
    {
        result_head = result_head->next;
        result_head->prev = NULL;
    }

    return result_head;
}