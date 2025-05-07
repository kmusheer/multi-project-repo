// #include "../mylib.h"

#include "../mylib/mylib.h"
#include "../input/input.h"
#include "../print/print.h"
#include "./edit.h"

Node *findStudent(Node *head, char *studentId)
{
    while (head != NULL)
    {
        if (strcmp(head->data.studentId, studentId) == 0)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void updateName(Node *student)
{
    char *newName = NULL;
    do
    {
        printf("Enter your full (new) name : ");
        newName = getString();
        // if (newName[0] != student->data.name[0])
        if (newName[0] != '\0' && newName[0] != student->data.name[0])
        {
            printf("You cannot change the first character of your name.\n");
            free(newName);
            continue;
        }
        if (!nameValidation(newName))
        {
            printf("Invalid name. Try again.\n");
            free(newName);
            continue;
        }
        // free(student->data.name); // free previously allocated memory
        char *oldName = student->data.name;
        student->data.name = strdup(newName);
        if (!student->data.name)
        {
            printf("Memory allocation failed. Exiting.\n");
            exit(EXIT_FAILURE);
        }
        printf("Name updated from '%s' to '%s'.\n", oldName, student->data.name);
        free(oldName);
        free(newName);
        break;
    } while (1);
}

void updateEmail(Node *student)
{
    printf("Enter your (new) email ID : ");
    free(student->data.emailId); // free previously allocated memory
    student->data.emailId = getString();
}

void updateContact(Node *student)
{
    student->data.contactNumber = getOnlyInt("Enter your 10-digit (new) contact number: ");
}

void updateDOB(Node *student)
{
    printf("Enter your (new) DOB : \n");
    student->data.birth.date = getDOBInput("Enter your birth date (Day, between 1 and 31) : ", 1, 31);
    student->data.birth.month = getDOBInput("Enter your birth month (Month, between 1 and 12) : ", 1, 12);
    student->data.birth.year = getDOBInput("Enter your birth year (e.g., 1999): ", 1900, 2024);
}

void updatePercentage(Node *student)
{
    printf("Enter your (updated) percentage here : \n");
    printf("\nEnter your (updated) marks in percentage\n(e.g., enter 7545 for 75.45%%) \n");
    student->data.percentage.ssc = getFloatInput("Enter your (updated) SSC percentage : ");
    if (student->data.percentage.preDegreeType == 'D')
    {
        student->data.percentage.preDegree.diploma = getFloatInput("Enter your (updated) diploma percentage : ");
    }
    else if (student->data.percentage.preDegreeType == 'I')
    {
        student->data.percentage.preDegree.inter = getFloatInput("Enter your (updated) Intermediate percentage : ");
    }
    student->data.percentage.degree = getFloatInput("Enter your (updated) degree percentage : ");
}

void updateDataPrint(Node *student)
{
    if (student == NULL)
    {
        printf("No records to display.\n");
        return;
    }
    printHeader();
    printBody(student);
}
