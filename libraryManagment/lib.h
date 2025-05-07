#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct library_managment
{
    char *nameOfBooks;
    char *nameOfAuthor;
    int numOfPages;
    int numOfBooks;
} lib;

typedef struct Node
{
    lib data;
    struct Node *next;
} Node;


char *getString();
void add_books(Node **);
void list_books(Node *);
void count_specific_book(Node *);
void take_books(Node *);
void find_books(Node *);
void edit_books(Node *);
void save_books(Node *);
void sync_file(Node **);
void delete_book(Node **);
void free_books(Node *);

 


