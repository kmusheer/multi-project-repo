#include "./lib.h"

void take_books(Node *head) // borrow a book from library
{
    Node *temp = head, *authorCount = head;
    int authCount = 0;
    char *name = NULL, *authorName = NULL;

    printf("Enter book name to borrow: ");
    name = getString();

    if (name == NULL)
    {
        printf("Error reading book name!\n");
        return;
    }

    while (authorCount != NULL)
    {
        if (strcmp(authorCount->data.nameOfBooks, name) == 0)
        {
            authCount++;
            printf("%s is author of %s \n", authorCount->data.nameOfAuthor, name);
        }
        authorCount = authorCount->next;
    }
    if (authCount > 1)
    {
        printf("Enter Author name to borrow a book: ");
        authorName = getString();
        if (authorName == NULL)
        {
            printf("Error reading author name!\n");
            free(name);
            return;
        }
        while (temp != NULL)
        {
            if ((strcmp(temp->data.nameOfBooks, name) == 0) && (strcmp(temp->data.nameOfAuthor, authorName) == 0))
            {
                if (temp->data.numOfBooks > 0)
                {
                    temp->data.numOfBooks--;
                    printf("You have borrowed '%s which author is : %s'.\n", name, authorName);
                    free(name);
                    free(authorName);
                    return;
                }
                else
                {
                    printf("Sorry, no copies available of '%s' by %s.\n", name, authorName);
                    free(name);
                    free(authorName);
                    return;
                }
            }
            temp = temp->next;
        }
        printf("Book by %s not found!\n", authorName);
    }
    else
    {
        while (temp != NULL)
        {
            if (strcmp(temp->data.nameOfBooks, name) == 0)
            {

                if (temp->data.numOfBooks > 0)
                {
                    temp->data.numOfBooks--;
                    printf("You have borrowed '%s'.\n", name);
                    free(name);
                    return;
                }
                else
                {
                    printf("Sorry, no copies available of '%s'.\n", name);
                    free(name);
                    return;
                }
            }
            temp = temp->next;
        }
        printf("Book not found!\n");
    }
    free(name);
}