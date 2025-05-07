#include "./lib.h"

void delete_book(Node **head)
{
    if (*head == NULL)
    {
        printf("No books in the library.\n");
        return;
    }

    Node *temp = *head, *prev = NULL;
    char *name = NULL, *authorName = NULL;

    printf("Enter book/author name to delete: \n");
    printf("Enter book name: ");
    name = getString();
    printf("Enter author name: ");
    authorName = getString();

    while (temp != NULL)
    {
        // Check for the book to delete
        if ((strcmp(temp->data.nameOfBooks, name) == 0) &&
            (strcmp(temp->data.nameOfAuthor, authorName) == 0))
        {
            if (prev == NULL)
            {
                // Deleting the head node
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;        //                // delete the current node
            }

            // Free the memory associated with the current node
            free(temp->data.nameOfBooks);
            free(temp->data.nameOfAuthor);
            Node *to_delete = temp;
            temp = temp->next; // Move to the next node before freeing
            free(to_delete);

            printf("Book deleted successfully!\n");
            continue; // Skip updating `prev` since a node was deleted
        }

        prev = temp;
        temp = temp->next;
    }

    free(name);
    free(authorName);

    printf("Delete operation completed.\n");
}
