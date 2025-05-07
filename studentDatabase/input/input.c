#include "../mylib/mylib.h"
#include "./input.h"

int idCountArr[26] = {0};

void Input(Node **head)
{
    Node *add_stud = (Node *)malloc(sizeof(Node));
    if (add_stud == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    add_stud->next = NULL; // Initialize next pointer

    char ch, *name = NULL;
    do
    {
        printf("Enter your full name : ");
        name = getString();
        if (!nameValidation(name))
        {
            free(name);
            continue;
        }
        break;
    } while (1);
    // add_stud->data.name = name;
    add_stud->data.name = strdup(name);

    printf("student ID generating ... ( please wait )\n");
    add_stud->data.studentId = generateID(name, idCountArr);
    sleep(2);
    printf("your vector student Id is : %s\n", add_stud->data.studentId);

    printf("Enter your email ID : ");
    add_stud->data.emailId = getString();

    add_stud->data.contactNumber = getOnlyInt("Enter your 10-digit contact number (digits only) : ");

    add_stud->data.birth.date = getDOBInput("Enter your birth date (Day, between 1 and 31) : ", 1, DATE_MAX);
    add_stud->data.birth.month = getDOBInput("Enter your birth month (Month, between 1 and 12) : ", 1, MONTH_MAX);
    add_stud->data.birth.year = getDOBInput("Enter your birth year (e.g., 1999) : ", 1900, YEAR_MAX);

    printf("\nEnter your marks in percentage\n(e.g., enter 7545 for 75.45%%) \n");
    add_stud->data.percentage.ssc = getFloatInput("Enter your SSC percentage : ");
    clearBuffer();

    do
    {
        printf("Enter 'a' if you completed a diploma or 'b' for Intermediate (12th) : ");
        ch = getchar();
        // clearBuffer();

        if (ch == 'a')
        {
            add_stud->data.percentage.preDegree.diploma = getFloatInput("Enter your diploma percentage : ");
            add_stud->data.percentage.preDegreeType = 'D';
            break;
        }
        else if (ch == 'b')
        {
            add_stud->data.percentage.preDegree.inter = getFloatInput("Enter your Intermediate percentage : ");
            add_stud->data.percentage.preDegreeType = 'I';
            break;
        }
        else
        {
            printf("Invalid choice! Please choose 'a' or 'b'.\n");
        }
    } while (1);
    add_stud->data.percentage.degree = getFloatInput("Enter your degree percentage : ");

    appendNode(head, add_stud);

    free(name);
}
