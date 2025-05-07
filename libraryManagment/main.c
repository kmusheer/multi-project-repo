#include "./lib.h"

void menu()
{
    printf("\n*********MENU*********\n");
    printf("a/A: Add a new book to library ( book name , author name and no.of pages )\n");
    printf("l/L: List available books in library with book name and author name \n");
    printf("c/C: Display count of specific book \n");
    printf("e/E: Edit book info ( author name / book name / pages info / no.of books info ) \n");
    printf("t/T: Take a book from library. \n");
    printf("d/D: Delete a book from library. \n");
    printf("f/F: Find book in library \n");
    printf("s/S: To save books info in file \n");
    printf("q/Q: Quit from app \n");
}

int main()
{
    Node *library = NULL;
    sync_file(&library);
    char ch;

    while (1)
    {
        menu();
        printf("Select a menu option \n");
        // fflush(stdout);
        // __fpurge(stdin);
        ch = getchar();
        while ((getchar()) != '\n');

        switch (ch)
        {
        case 'a':
        case 'A':
            add_books(&library);
            break;
        case 'l':
        case 'L':
            list_books(library);
            break;
        case 'c' :
        case 'C' :
            count_specific_book(library);
            break;
        case 't' :
        case 'T' :
            take_books(library);
            break;
        case 'f' :
        case 'F' :
            find_books(library);
            break;
        case 'e' :
        case 'E' :
            edit_books(library);
            break;
        case 'd' :
        case 'D' :
            delete_book(&library);
            break;
        case 's' :
        case 'S' :
            save_books(library);
            break;
        case 'q':
        case 'Q':
            save_books(library);
            free_books(library);
            printf("Exiting the application.\n");
            return 0;
        default:
            printf("Invalid option! Please try again.\n");
            break;
        }
    }
}