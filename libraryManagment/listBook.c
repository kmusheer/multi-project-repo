#include "./lib.h"

void list_books(Node *head) // display all books
{
    Node *temp = head;
    if (head == NULL)
    {
        printf("No books available.\n");
        return;
    }

    printf("Books available in library:\n");
    while (temp != NULL)
    {
        printf("Book Name: %s, Author Name: %s, Pages: %d, Copies: %d\n", temp->data.nameOfBooks, temp->data.nameOfAuthor, temp->data.numOfPages, temp->data.numOfBooks);

        temp = temp->next;
    }
}