#include "./lib.h"

void count_specific_book(Node *head) // count number of specific book with all author
{
    Node *temp = head;
    int count = 0, flag = 0;
    char *name = NULL;
    printf("Enter book name to count: ");
    name = getString();

    while (temp != NULL)
    {
        if (strcmp(temp->data.nameOfBooks, name) == 0)
        {
            count += temp->data.numOfBooks;
            flag = 1;
        }
        temp = temp->next;
    }

    if (flag)
        printf("Total copies of '%s' available: %d\n", name, count);
    else
    {
        ("Book not found!\n");
    }
}