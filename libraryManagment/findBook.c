#include "./lib.h"


void find_books(Node *head) // search book
{
    Node *temp = head;
    int choice, flag = 0;
    printf("Find book by:\n1. Name\n2. Author\nEnter choice (1/2): ");
    scanf("%d", &choice);
    while (getchar() != '\n')
        ;

    char *name = NULL;

    if (choice == 1)
    {
        printf("Enter book name to search: ");
        name = getString();

        while (temp != NULL)
        {
            if (strcmp(temp->data.nameOfBooks, name) == 0)
            {
                printf("Found book: %s, Author: %s, Pages: %d, Available: %d\n", temp->data.nameOfBooks, temp->data.nameOfAuthor, temp->data.numOfPages, temp->data.numOfBooks);
                // return;
                flag = 1;
            }
            temp = temp->next;
        }
        if (!flag)
        {
            printf("Book not found!\n");
        }
    }
    else if (choice == 2)
    {
        printf("Enter author name to search: ");
        name = getString();

        while (temp != NULL)
        {
            if (strcmp(temp->data.nameOfAuthor, name) == 0)
            {
                printf("Found book: %s, Author: %s, Pages: %d, Available: %d\n", temp->data.nameOfBooks, temp->data.nameOfAuthor, temp->data.numOfPages, temp->data.numOfBooks);
                // return;
                flag = 1;
            }
            temp = temp->next;
        }
        if (!flag)
        {
            printf("Book not found!\n");
        }
    }
    return;
}