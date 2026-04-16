#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Usage: ./apc num1 op num2\n");
        return FAILURE;
    }

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;

    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    Dlist *result = NULL;

    if (strcmp(argv[2], "+") == 0)
    {
        printf("\n===== ADDITION =====\n");
        result = add_list(head1, tail1, head2, tail2);
    }
    else if (strcmp(argv[2], "-") == 0)
    {
        printf("\n===== SUBTRACTION =====\n");
        result = sub_list(head1, tail1, head2, tail2);
    }
    else if (strcmp(argv[2], "*") == 0)
    {
        printf("\n===== MULTIPLICATION =====\n");
        result = multiply_list(head1, tail1, head2, tail2);
    }
    else if (strcmp(argv[2], "/") == 0)
    {
        printf("\n===== DIVISION =====\n");
        result = divide_list(head1, tail1, head2, tail2);
    }
    else
    {
        printf("ERROR: Invalid operator\n");
        return FAILURE;
    }

    printf("Number 1: ");
    print_list(head1);

    printf("Number 2: ");
    print_list(head2);

    printf("Result: ");
    if (result != NULL)
        print_list(result);
    else
        printf("0\n");

    printf("--------------------------\n");

    return SUCCESS;
}