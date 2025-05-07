#include "./mylib/myLib.h"
#include "./file_operations/file.h"
#include "./input/input.h"

int main()
{
    Node *DB = NULL; // Initialize the database as an empty list
    sync(&DB);       // Fetch data from database
    char choice;
    while (1)git
    {
        menu();
        sleep(1);
        printf("Enter your choice: ");
        // choice = getchar();
        // clearBuffer();
        if (scanf(" %c", &choice) != 1)
        {
            printf("Invalid input. Please try again.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice)
        {
        case 'a':
        case 'A':
            Input(&DB);
            break;

        case 'p':
        case 'P':
            Print(DB);
            break;

        case 's':
        case 'S':
            Save(DB);
            break;
        case 'f':
        case 'F':
            Find(DB);
            break;
        case 'd':
        case 'D':
            Delete(&DB);
            break;
        case 'e':
        case 'E':
            Edit(DB);
            break;
        case 'r':
        case 'R':
            Reverse(DB);
            break;

        case 'q':
        case 'Q':
            cleanup(&DB);
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
