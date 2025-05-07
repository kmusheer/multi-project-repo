#include "../mylib/mylib.h"
#include "../input/input.h"
#include "../print/print.h"
#include "../main.h"

void Find(Node *head)
{
    if (head == NULL)
    {
        printf("No records to display.\n");
        return;
    }
    int flag = 0;
    char *student = NULL, ch;
    // OPTION:
    do
    {
        printf("Enter 'a' if you want to search by name or 'b' for studentId : ");
        ch = getchar();
        clearBuffer();
        if (ch != 'a' && ch != 'b')
        {
            printf("Invalid input! Please enter 'a' or 'b'.\n");
        }
    } while (ch != 'a' && ch != 'b');

    printf("Enter your %s : ", (ch == 'a') ? "name" : "vector student ID");
    student = getString();
    if (student == NULL)
    {
        printf("Memory allocation failed. Search aborted.\n");
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (((ch == 'a') && strcmp(temp->data.name, student) == 0) || ((ch == 'b') && strcmp(temp->data.studentId, student) == 0))
        {
            if (!flag)
            {
                printf("\n--- Search Results ---\n");
                printHeader(); // Print table header
                flag = 1;
            }
            printBody(temp);
        }
        temp = temp->next;
    }
    if (!flag)
    {
        printf("No records found with the %s : %s\n", (ch == 'a') ? "name" : "student ID", student);
    }
    free(student);
}