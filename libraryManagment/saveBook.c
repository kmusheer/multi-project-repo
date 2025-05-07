#include "./lib.h"

void save_books(Node *head) // Save all library book details in library_data text file
{
    if (head == NULL)
    {
        printf("No books to save.\n");
        return;
    }

    FILE *fptr = fopen("library_data.txt", "w");
    if (fptr == NULL)
    {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.nameOfBooks == NULL || temp->data.nameOfAuthor == NULL)
        {
            printf("Error: Invalid data found in the list.\n");
            fclose(fptr);
            return;
        }

        if (fprintf(fptr, "%s\n%s\n%d\n%d\n\n",
                    temp->data.nameOfBooks,
                    temp->data.nameOfAuthor,
                    temp->data.numOfPages,
                    temp->data.numOfBooks) < 0)
        {
            printf("Error: Failed to write data to file.\n");
            fclose(fptr);
            return;
        }

        temp = temp->next;
    }

    if (fclose(fptr) != 0)
    {
        printf("Error: Failed to close the file.\n");
        return;
    }

    printf("Library data saved successfully!\n");
}
