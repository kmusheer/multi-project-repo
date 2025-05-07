#include "../mylib/mylib.h"
#include "../input/input.h"
#include "./file.h"

void sync(Node **head)
{
    FILE *fptr = fopen(FILE_NAME, "r");
    if (!fptr)
    {
        printf("Error: Could not open file 'studentDB.txt'.\n");
        return;
    }

    char name[20], studentID[15], email[20];
    unsigned long int contactNumber;
    unsigned int date, month, year;
    float ssc, preDegree, degree;
    char preDegreeType;

    // while (fscanf(fptr, "%s %s %s %lu %u %u %u %f %c %f %f", name, studentID, email, &contactNumber, &date, &month, &year, &ssc, &preDegreeType, &preDegree, &degree) != EOF)
    while (fscanf(fptr, "%s %s %s %lu %u %u %u %f %c %f %f", name, studentID, email, &contactNumber, &date, &month, &year, &ssc, &preDegreeType, &preDegree, &degree) == 11)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (!newNode)
        {
            printf("Error: Memory allocation for new node failed.\n");
            fclose(fptr);
            return;
        }
        // newNode->data.name = strdup(name);
        newNode->data.name = malloc(strlen(name) + 1); // assign dynamic memory
        strcpy(newNode->data.name, name);              // copy data

        newNode->data.studentId = strdup(studentID);
        newNode->data.emailId = strdup(email);
        if (!newNode->data.name || !newNode->data.studentId || !newNode->data.emailId)
        {
            printf("Error: Memory allocation for strings failed.\n");
            free(newNode->data.name);
            free(newNode->data.studentId);
            free(newNode->data.emailId);
            free(newNode);
            fclose(fptr);
            return;
        }

        newNode->data.contactNumber = contactNumber;
        newNode->data.birth.date = date;
        newNode->data.birth.month = month;
        newNode->data.birth.year = year;
        newNode->data.percentage.ssc = ssc;
        newNode->data.percentage.preDegreeType = preDegreeType;
        if (preDegreeType == 'D')
        {
            newNode->data.percentage.preDegree.diploma = preDegree;
        }
        else
            newNode->data.percentage.preDegree.inter = preDegree;
        newNode->data.percentage.degree = degree;

        appendNode(head, newNode);
        // generateID(name);

        char ch = studentID[6];
        if (ch >= 'A' && ch <= 'Z')
        {
            int index = ch - 'A'; // // Map 'A' to 0, 'B' to 1, ..., 'Z' to 25
            // int idNumber = atoi(&studentID[7]);                  // 5
            // if(studentID[8] != '\0'){
            //     idNumber = idNumber * 10 + atoi(&studentID[8]);  // foe greatere than 9
            // }
            // Automatically handles multi-digit 10 for decimal
            int idNumber = strtol(&studentID[7], NULL, 10);
            if (idNumber > idCountArr[index]) // 5 > idCountArr[0] // 5 > 4 update count if ID is higher
            {
                idCountArr[index] = idNumber; // idCountArr[0] = 5;
            }
        }
        dataCount++;
    }
    fclose(fptr);
}