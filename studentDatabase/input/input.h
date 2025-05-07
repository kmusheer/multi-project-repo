#ifndef INPUT_H
#define INPUT_H
#include "../mylib/mylib.h"

// Input functions
void clearBuffer();
char *getString();
int getOnlyInt(char *);
int getDOBInput(char *, unsigned int, unsigned int);
float getFloatInput(char *);
char *generateID(char *, int *);
int nameValidation(char *);
void appendNode(Node **, Node *);
void Input(Node **);
void cleanup(Node **);
void freeList(Node **);


#endif