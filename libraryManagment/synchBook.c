#include "./lib.h"


void sync_file(Node **head) // synch or load file data when you relaunch application
{
    FILE *fptr = fopen("library_data.txt", "r");
    if (fptr == NULL)
    {
        printf("Error opening file for loading.\n");
        return;
    }
    char buffer[256]; // use to stor fetch book details
    while (fgets(buffer, sizeof(buffer), fptr))
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(fptr);
            return;
        }

        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        temp->data.nameOfBooks = strdup(buffer);

        if (fgets(buffer, sizeof(buffer), fptr) == NULL)
        {
            printf("Error reading author name.\n");
            free(temp->data.nameOfBooks);
            fclose(fptr);
            return;
        }
        if (buffer[strlen(buffer) - 1] == '\n')
        {
            buffer[strlen(buffer) - 1] = '\0';
        }
        temp->data.nameOfAuthor = strdup(buffer);

        if (fscanf(fptr, "%d\n", &temp->data.numOfPages) != 1)
        {
            printf("Error reading number of page.\n");
            free(temp->data.nameOfBooks);
            free(temp->data.nameOfAuthor);
            fclose(fptr);
            return;
        }

        if (fscanf(fptr, "%d\n", &temp->data.numOfBooks) != 1)
        {
            printf("Error reading number of page.\n");
            free(temp->data.nameOfBooks);
            free(temp->data.nameOfAuthor);
            fclose(fptr);
            return;
        }

        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp; // temp = new book add which is load from file;
        }
        else
        {
            Node *temp1 = *head;
            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }
    }

    fclose(fptr);
    printf("Books loaded successfully!\n");
}