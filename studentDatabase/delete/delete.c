#include "../mylib/mylib.h"
#include "../input/input.h"
#include "../file_operations/file.h"
#include "./delete.h"

void Delete(Node **head) // double pointer required because if head node is deleted then change head
{
    if (*head == NULL)
    {
        printf("No data to delete.\n");
        return;
    }
    char choice, ch;
    printf("Do you want to delete all records? (y/n): ");
    scanf(" %c", &choice);
    clearBuffer();

    if (choice == 'y' || choice == 'Y')
    {
        printf("Do you want to delete all records from DataBase also? (y/n): ");
        scanf(" %c", &ch);
        clearBuffer();
        if (ch == 'y' || ch == 'Y')
        {
            FILE *fptr = fopen(FILE_NAME, "w");
            if (fptr == NULL)
            {
                perror("Error opening file");
                return;
            }
            fclose(fptr);
        }
        freeList(head);
        head = NULL;
        printf("All records deleted successfully!\n");
        return;
    }

    char *studID = NULL;
    printf("Enter student ID to Delete : ");
    studID = getString();
    if (studID == NULL)
    {
        printf("Memory allocation failed. Deletion aborted.\n");
        return;
    }
    int found = 0;
    Node *temp = *head, *prev = NULL;
    while (temp != NULL)
    {
        if (strcmp(temp->data.studentId, studID) == 0)
        {
            found = 1;
            if (prev == NULL)
            { // delete head node
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next; // Update previous node's next
                if (temp->next == NULL)  // for last node
                {
                    prev->next = NULL;
                }
            }
            free(temp->data.name);
            free(temp->data.emailId);
            free(temp->data.studentId);
            free(temp);

            printf("Student record with ID '%s' deleted successfully!\n", studID);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found)
    {
        printf("No matching record found for the given student ID : %s.\n", studID);
    }
    free(studID);
}