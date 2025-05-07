#include "./lib.h"

//--------------------------getstring function ------------------------------------------------------
char *getString() // getstring dynamically
{
    char *p = NULL;
    int i = 0;
    do
    {
        char *temp = realloc(p, (i + 1) * sizeof(char));
        if (!temp)
        {
            free(p); // free p allocated memory
            printf("Memory allocation failed!\n");
            return NULL;
        }
        p = temp;
        p[i] = getchar();
    } while (p[i++] != '\n');

    p[i - 1] = '\0';
    return p;
}

void free_books(Node *head) // free all dynamic memory allocated
{
    Node *temp = head;

    while (temp != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
