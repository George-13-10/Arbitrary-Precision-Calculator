#include "header.h"

Dlist* multiply_list(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    Dlist *result_head = NULL, *result_tail = NULL;
    int pos = 0;

    while (tail2 != NULL)
    {
        Dlist *temp_head = NULL, *temp_tail = NULL;
        int carry = 0;

        Dlist *t1 = tail1;
        int d2 = tail2->data;

        while (t1 != NULL)
        {
            int res = t1->data * d2 + carry;

            insert_at_first(&temp_head, &temp_tail, res % 10);
            carry = res / 10;

            t1 = t1->prev;
        }

        if (carry)
            insert_at_first(&temp_head, &temp_tail, carry);

        // add zeros
        int i = 0;
        while (i < pos)
        {
            insert_at_last(&temp_head, &temp_tail, 0);
            i++;
        }

        if (result_head == NULL)
        {
            result_head = temp_head;
            result_tail = temp_tail;
        }
        else
        {
            result_head = add_list(result_head, result_tail, temp_head, temp_tail);

            // update tail
            result_tail = result_head;
            while (result_tail->next != NULL)
                result_tail = result_tail->next;
        }

        pos++;
        tail2 = tail2->prev;
    }

    return result_head;
}