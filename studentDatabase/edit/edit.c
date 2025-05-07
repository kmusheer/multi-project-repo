#include "../mylib/mylib.h"
#include "../input/input.h"
#include "../main.h"
#include "./edit.h"

void Edit(Node *head)
{

    if (head == NULL)
    {
        printf("No existing records edit.\n");
        return;
    }
    char ch, *studentID = NULL;
    Node *student = NULL;

    while (1)
    {
        subMenu();
        printf("Enter your sub menu choice: ");
        // ch = getchar();
        if (scanf(" %c", &ch) != 1)
        {
            printf("Invalid input. Please try again.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        ch = tolower(ch); // converting to lowercse if uppercse

        if (ch == 'q')
        {
            printf("Exiting from sub-Menu.\n");
            break;
        }
        // if (ch == 'a' || ch == 'A' || ch == 'b' || ch == 'B' || ch == 'c' || ch == 'C' || ch == 'd' || ch == 'D' || ch == 'e' || ch == 'E')
        if (strchr("abcdep", ch)) // Valid submenu options
        {
            printf("Enter your student ID : ");
            studentID = getString();
            student = findStudent(head, studentID);
            free(studentID);
            studentID = NULL;

            if (!student)
            {
                printf("No record found for the given student ID.\n");
                continue;
            }
        }

        switch (ch)
        {
        case 'a':
            updateName(student);
            break;
        case 'b':
            updateEmail(student);
            break;
        case 'c':
            updateContact(student);
            break;
        case 'd':
            updateDOB(student);
            break;
        case 'e':
            updatePercentage(student);
            break;
        case 'p':
            updateDataPrint(student);
            break;
        default:
            printf("Invalid subMenu choice. Please try again.\n");
        }
    }
    student = NULL;
}