#include "./lib.h"

void add_books(Node **head) // add book,author,total page and number of copy of books using singly linked list
{
    Node *new_book = (Node *)malloc(sizeof(Node));
    Node *temp = *head;

    if (new_book == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter book name: ");
    new_book->data.nameOfBooks = getString();

    printf("Enter author name: ");
    new_book->data.nameOfAuthor = getString();

    printf("Enter number of pages: ");
    scanf("%d", &new_book->data.numOfPages);

    printf("Enter number of copies available: ");
    scanf("%d", &new_book->data.numOfBooks);

    while (getchar() != '\n')
        ; // clean the input buffer

    while (temp != NULL)
    {
        if ((strcmp(temp->data.nameOfBooks, new_book->data.nameOfBooks) == 0) && (strcmp(temp->data.nameOfAuthor, new_book->data.nameOfAuthor) == 0))
        {
            printf("This book is already added. \n");
            free(new_book->data.nameOfBooks);
            free(new_book->data.nameOfAuthor);
            free(new_book);
            return;
        }
        temp = temp->next;
    }
    if (*head == NULL)
        *head = new_book;
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_book;
    }
    printf("Book added successfully!\n");
}