#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include<windows.h>
#include<unistd.h>

#define DATE_MAX 31
#define MONTH_MAX 12
#define YEAR_MAX 2025
#define MARKS_MIN 100
#define MARKS_MAX 10000
#define ID_COUNT_SIZE 26

extern int dataCount;                 // Tracks the total number of student records
extern int idCountArr[ID_COUNT_SIZE]; // Tracks student IDs by alphabetical index

typedef struct
{
    unsigned int date : 5;  // Day of the month (1-31)  5bit=11111 = 31
    unsigned int month : 4; // Month of the year (1-12) 4bit=1111  = 15
    unsigned int year : 12;
} DOB;

typedef union
{
    float inter;
    float diploma;
} sscPlus;

typedef struct
{
    float ssc;
    sscPlus preDegree; // Pre-degree marks (either intermediate or diploma)
    float degree;
    char preDegreeType; // Flag for pre-degree type ('a' for diploma, 'b' for intermediate)
} marks;

typedef struct student_Record
{
    char *name;
    char *emailId;
    char *studentId;
    unsigned long int contactNumber;
    DOB birth;        // Date of Birth
    marks percentage; // Academic percentages
} stud;

typedef struct Node
{
    stud data;
    struct Node *next;
} Node;

// void menu();
// void subMenu();
// void clearBuffer();
// char *getString();
// int getOnlyInt(char *);
// int getDOBInput(char *, unsigned int, unsigned int);
// float getFloatInput(char *);
// char *generateID(char *);
// void appendNode(Node **, Node *);
// void printHeader();
// void printBody(Node *);
// int nameValidation(char *);

// void sync(Node **);
// void Input(Node **);
// void Print(Node *);
// void Find(Node *);
// void Save(Node *);
// void Edit(Node *);
// void Delete(Node **head);
// void Reverse(Node *head);

// // all about edit or update

// Node *findStudent(Node *, char *);
// void updateName(Node *);
// void updateEmail(Node *);
// void updateContact(Node *);
// void updateDOB(Node *);
// void updatePercentage(Node *);
// void updateDataPrint(Node *);

#endif
