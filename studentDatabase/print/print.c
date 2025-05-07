#include "../mylib/mylib.h"
#include "./print.h"

void Print(Node *head)
{
    if (head == NULL)
    {
        printf("No records to display.\n");
        return;
    }
    Node *temp = head;
    printf("\n--- All Student Records ---\n");
    
    printHeader();              // Print table header

    // Print table rows
    while (temp != NULL)
    {
        printBody(temp);
        temp = temp->next;
    }
    printf("----------------------------------------------------------------------------------------------------------------------------------------------\n\n");
}
