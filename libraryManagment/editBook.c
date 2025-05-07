#include "./lib.h"

void edit_books(Node *head) // edit book details
{
    Node *temp = head;
    char *name = NULL, *authorName = NULL;
    printf("Enter book/author name to access edit: \n");
    printf("Enter book name : ");
    name = getString();
    printf("Enter author name : ");
    authorName = getString();

    while (temp != NULL)
    {

        if ((strcmp(temp->data.nameOfBooks, name) == 0) && (strcmp(temp->data.nameOfAuthor, authorName) == 0))
        {
            printf("Enter new book name: ");
            temp->data.nameOfBooks = getString();

            printf("Enter new author name: ");
            temp->data.nameOfAuthor = getString();

            printf("Enter number of pages: ");
            scanf("%d", &temp->data.numOfPages);

            printf("Enter number of copies available: ");
            scanf("%d", &temp->data.numOfBooks);

            while (getchar() != '\n')
                ;
            free(name);
            free(authorName);
            return;
        }
        temp = temp->next;
    }
    printf("Book not found!\n");
    free(name);
    free(authorName);
    return;
}