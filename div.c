#include "header.h"

// compare function
int compare(Dlist *h1, Dlist *h2)
{
    int len1 = 0, len2 = 0;

    Dlist *t1 = h1;
    Dlist *t2 = h2;

    while (t1 != NULL)
    {
        len1++;
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        len2++;
        t2 = t2->next;
    }

    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data > h2->data)
            return 1;
        if (h1->data < h2->data)
            return -1;

        h1 = h1->next;
        h2 = h2->next;
    }

    return 0;
}


// division using repeated subtraction
Dlist* divide_list(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    // division by zero
    if (head2->data == 0 && head2->next == NULL)
    {
        printf("ERROR: Division by zero\n");
        return NULL;
    }

    // if num1 < num2->result = 0
    if (compare(head1, head2) < 0)
    {
        Dlist *res = NULL, *tail = NULL;
        insert_at_last(&res, &tail, 0);
        return res;
    }

    Dlist *count = NULL, *count_tail = NULL;
    insert_at_last(&count, &count_tail, 0);

    Dlist *temp_head = head1;
    Dlist *temp_tail = tail1;

    while (compare(temp_head, head2) >= 0)
{
    Dlist *new_head = sub_list(temp_head, temp_tail, head2, tail2);

    if (new_head == NULL)
        break;

    if (compare(new_head, temp_head) == 0)
        break;

    temp_head = new_head;

    // update tail
    temp_tail = temp_head;
    while (temp_tail->next != NULL)
        temp_tail = temp_tail->next;

    // count++
    Dlist *one = NULL, *one_tail = NULL;
    insert_at_last(&one, &one_tail, 1);

    count = add_list(count, count_tail, one, one_tail);

    count_tail = count;
    while (count_tail->next != NULL)
        count_tail = count_tail->next;
}

    return count;
}