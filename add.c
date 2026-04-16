#include "header.h"

Dlist* add_list(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    Dlist *result_head = NULL;
    Dlist *result_tail = NULL;

    int carry = 0;

    while (tail1 != NULL || tail2 != NULL)
    {
        int sum;

        if (tail1 != NULL && tail2 == NULL)
            sum = tail1->data + carry;

        else if (tail1 == NULL && tail2 != NULL)
            sum = tail2->data + carry;

        else
            sum = tail1->data + tail2->data + carry;

        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        // insert at first
        insert_at_first(&result_head, &result_tail, sum);

        if (tail1 != NULL)
            tail1 = tail1->prev;

        if (tail2 != NULL)
            tail2 = tail2->prev;
    }

    if (carry)
        insert_at_first(&result_head, &result_tail, carry);

    return result_head;
}