#ifndef HERO_PRINT_FUNC_H
#define HERO_PRINT_FUNC_H
#include <stdio.h>

void printHero();
void heroExpression(char *hero[], char *newFace);
void clearConsole();


char *hero[] = {
    " (\\(\\    ",
    " ( O_O )   ",
    "o_(\")(\") ", 
    NULL

};


char *happy = " ( ^.^ )   ";
char *surprised = " ( O_O )   ";
char *mad = " ( >.< )   ";
char *annoyed = " ( -.- )   ";
char *sad = " ( ;_; )   ";


#endif /* HERO_PRINT_FUNC_H */