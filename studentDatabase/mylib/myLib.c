#include "./mylib.h"

int dataCount = 1;

void menu()
{
    printf("\n*********MENU*********\n");
    printf("a/A : Add a new student record\n");
    printf("p/P : Print the record from database\n");
    printf("s/S : Save the database in a file \n");
    printf("d/D : Delete a record \n");
    printf("e/E : Edit record \n");
    printf("f/F : Find a student \n");
    printf("r/R : Reverse the record of current display\n");
    printf("q/Q : Quit from app \n");
}
void subMenu()
{
    printf("\n*********SUB-MENU*********\n");
    printf("a/A : Edit your name\n");
    printf("b/B : Edit your email\n");
    printf("c/C : Edit your contact number\n");
    printf("d/D : Edit your DOB\n");
    printf("e/E : Edit your percentage\n");
    printf("p/P : print your updated data\n");
    printf("q/Q : Quit \n\n");
}

void printHeader()
{
    printf("%-20s %-15s %-20s %-15s %-15s %-15s %-15s %-15s\n",
           "Name", "Vector_ID", "Email ID", "Contact No.", "DOB",
           "SSC %", "Pre-Degree %", "Degree %");
    printf("------------------------------------------------------------------------------------------------------------------------------------\n");
}
void printBody(Node *temp)
{
    printf("%-20.20s %-15s %-20.20s %-15lu %2.2u/%2.2u/%-9u %-15.2f ",
           temp->data.name,
           temp->data.studentId,
           temp->data.emailId,
           temp->data.contactNumber,
           temp->data.birth.date, temp->data.birth.month, temp->data.birth.year,
           temp->data.percentage.ssc);

    if (temp->data.percentage.preDegreeType == 'D')
    {
        printf("D-%-15.2f ", temp->data.percentage.preDegree.diploma);
    }
    else
    {
        printf("I-%-15.2f ", temp->data.percentage.preDegree.inter);
    }
    printf("%-15.2f\n", temp->data.percentage.degree);
}

char *getString()
{
    char *p = NULL, *temp = NULL;
    int i = 0;
    do
    {
        temp = realloc(p, (i + 1) * sizeof(char));
        if (temp == NULL)
        {
            free(p);
            printf("Memory allocation failed. Exiting!\n");
            exit(EXIT_FAILURE);
            // return 0;
        }
        p = temp;
        p[i] = getchar();
    } while (p[i++] != '\n');
    p[i - 1] = '\0';
    return p;
}
char *generateID(char *name, int *arr)
{
    dataCount++;
    // static int arr[26] = {0};
    char *p = NULL, ch;
    int count = 0;
    p = calloc(1, 10);
    if (p == NULL)
    {
        printf("Memory allocation failed for ID generation.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p, "V24HE2");
    ch = name[0];

    if (ch >= 97 && ch <= 122)
        ch = ch - 32;
    p[6] = ch;
    count = ++arr[ch - 65];

    if (count / 10 == 0)
    {
        p[7] = count + 48;
        p[8] = '\0';
        p = realloc(p, sizeof(p) + 1);
    }
    else
    {
        p[7] = count / 10 + 48;
        p[8] = count % 10 + 48;
        p[9] = '\0';
    }
    return p;
}

void clearBuffer()
{ // clear buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
void freeList(Node **head)
{
    // printf("IN freelist\n");
    Node *temp;
    while ((*head) != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp->data.name);
        free(temp->data.emailId);
        free(temp->data.studentId);
    }
    // printf("in freelist after loop\n");
    free(temp);
}
void cleanup(Node **head)
{
    freeList(head);
    *head = NULL;   // Set head to NULL to avoid dangling pointer
    printf("All resources cleaned up. Exiting program.\n");
}


int nameValidation(char *name)
{
    if (!isalpha(name[0]))
    {
        printf("Name must start with an alphabet. Please try again.\n");
        return 0;
    }
    if (strlen(name) < 3 || strlen(name) > 30)
    {
        printf("Name must be between 3 and 50 characters long. Please try again.\n");
        return 0;
    }
    for (unsigned int i = 0; i < strlen(name); i++)
    {
        if (!isalpha(name[i]) && !isspace(name[i]))
        {
            printf("Name can only contain alphabets and spaces. Please try again.\n");
            return 0;
        }
    }
    return 1;
}

int getOnlyInt(char *prompt)
{
    int num = 0, cnt = 0;
    char ch;
    printf("%s", prompt);

    while (1)
    {
        ch = getchar();
        if (ch == '\n')
        {
            break;
        }
        if (ch == '-')
        {
            printf("Enter only positive values. \n");
            clearBuffer();
            return getOnlyInt(prompt);
        }
        // if (ch >= 48 && ch <= 57)
        if (isdigit(ch))
        {
            cnt++;
            num = num * 10 + (ch - '0');
        }
        else
        {
            printf("Invalid input. Only numeric digits are allowed.\n");
            clearBuffer();
            return getOnlyInt(prompt);
        }
        if (cnt > 10)
        {
            printf("Invalid input! Please enter only 10 digits.\n");
            clearBuffer();
            return getOnlyInt(prompt);
        }
    }
    return num;
}

int getDOBInput(char *prompt, unsigned int minValue, unsigned int maxValue)
{
    unsigned int value;
    int flag;
    do
    {
        value = getOnlyInt(prompt);
        flag = 1;
        if (value > maxValue)
        {
            printf("Invalid input. Please enter a value less than %u.\n", maxValue);
            flag = 0;
        }
        else if (value < minValue)
        {
            printf("Invalid input. Please enter a percentage greater than %u\n", minValue);
            flag = 0;
        }
    } while (!flag);
    return value;
}

// float getFloatInput(char *prompt)
// // float getFloatInput(char *prompt, float minValue, float maxValue) {
// {
//     unsigned int value;
//     int flag;
//     do
//     {
//         value = getOnlyInt(prompt);
//         flag = 1;
//         if (value > MARKS_MAX)
//         {
//             printf("Invalid input. Please enter a value less than %u.\n", MARKS_MAX);
//             flag = 0;
//         }
//         else if (value < MARKS_MIN)
//         {
//             printf("Invalid input. Please enter a value more than %u.\n", MARKS_MIN);
//             flag = 0;
//         }
//     } while (!flag);
//     return (value / 100.0);
// }
float getFloatInput(char *prompt)
{
    float value;
    int flag;
    do
    {
        printf("%s", prompt);
        if (scanf("%f", &value) != 1)                   // Check if input is a valid float
        {
            printf("Invalid input. Please enter a numeric value.\n");
            clearBuffer();
            continue;
        }
        flag = 1;
        if (value > MARKS_MAX || value < MARKS_MIN)
        {
            printf("Invalid input. Please enter a value between %.2f and %.2f.\n", MARKS_MIN / 100.0, MARKS_MAX / 100.0);
            flag = 0;
        }
    } while (!flag);
    return value / 100.0; // Convert to percentage
}

void appendNode(Node **head, Node *newNode)
{   
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}