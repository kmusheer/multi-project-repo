#include "../mylib/mylib.h"
#include "./file.h"

void Save(Node *head)
{
    if (head == NULL)
    {
        printf("No records to save.\n");
        return;
    }
    // FILE *fptr = fopen("studentDB.txt", "w");
    FILE *fptr = fopen(FILE_NAME, "w");
    if (fptr == NULL)
    {
        printf("Error: Could not open file '%s' for writing.\n", FILE_NAME);
        return;
    }

    Node *temp = head;
    int recordCount = 0;

    while (temp != NULL)
    {
        // fprintf(fptr, "%s\n%s\n%lu\n %u%u%u \n %f%f%f \n\n", temp->data.name, temp->data.emailId, temp->data.contactNumber,
        // temp->data.birth.date, temp->data.birth.date, temp->data.birth.date, temp->data.percentage.ssc, temp->data.percentage.preDegree.diploma ,temp->data.percentage.degree);

        fprintf(fptr, "%s\n", temp->data.name);
        fprintf(fptr, "%s\n", temp->data.studentId);
        fprintf(fptr, "%s\n", temp->data.emailId);
        fprintf(fptr, "%lu\n", temp->data.contactNumber);
        fprintf(fptr, "%d\n", temp->data.birth.date);
        fprintf(fptr, "%d\n", temp->data.birth.month);
        fprintf(fptr, "%d\n", temp->data.birth.year);
        fprintf(fptr, "%.2f\n", temp->data.percentage.ssc);
        fprintf(fptr, "%c\n", temp->data.percentage.preDegreeType);
        if (temp->data.percentage.preDegreeType == 'D')
        {
            fprintf(fptr, "%.2f\n", temp->data.percentage.preDegree.diploma);
        }
        else
        {
            fprintf(fptr, "%.2f\n", temp->data.percentage.preDegree.inter);
        }
        fprintf(fptr, "%.2f\n\n", temp->data.percentage.degree);
        recordCount++;
        temp = temp->next;
    }

    if (fclose(fptr) != 0)                  //close file here
    {
        printf("Error: Could not close file '%s' properly.\n", FILE_NAME);
    }
    else
    {
        printf("Library data saved successfully! (%d records)\n", recordCount);
    }
}
