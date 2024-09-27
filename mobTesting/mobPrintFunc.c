#include <stdio.h>
#include <unistd.h>
#include "mobPrintFunc.h"

int main()
{
    int choice = 0;
    printf("[1] : Static Mobs\t");
    printf("[2] : Mob \"animation\"");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        staticMobs();
        break;
    case 2:
        mobAnimation();
        break;
    default:
        break;
    }

    return 0;
}

void staticMobs()
{
    
    for (int i = 0; archerResting[i] != NULL && archerResting[i] != NULL; i++)
    {
        printf("%s \t %s\n", archerAttacking[i], archerResting[i]);
    }

    for (int i = 0; mageResting[i] != NULL && mageResting[i] != NULL; i++)
    {
        printf("%s \t %s\n", mageAttacking[i], mageResting[i]);
    }
    for (int i = 0; warriorResting[i] != NULL && warriorResting[i] != NULL; i++)
    {
        printf("%s \t %s\n", warriorAttacking[i], warriorResting[i]);
    }
}

void mobAnimation()
{
    // number of times animation happens
    for (int i = 0; i < 5; i++)
    {
        clearConsole();
        //toggle animation back and forth
        if (i % 2 == 0)
        {
            // looping through mob arrays
            for (int i = 0; archerResting[i] != NULL && mageResting[i] != NULL && warriorResting[i] != NULL; i++)
            {
                printf("%s \t %s \t %s\n", archerResting[i], mageResting[i], warriorResting[i]);
            }
        }
        else
        {
            for (int i = 0; archerAttacking[i] != NULL && mageAttacking[i] != NULL && warriorAttacking[i] != NULL; i++)
            {
                printf("%s \t %s \t %s\n", archerAttacking[i], mageAttacking[i], warriorAttacking[i]);
            }
        }
        sleep(1);
    }

    for (int i = 0; archerResting[i] != NULL && mageResting[i] != NULL && warriorResting[i] != NULL; i++)
    {
        printf("%s \t %s \t %s\n", archerResting[i], mageResting[i], warriorResting[i]);
    }
}

void clearConsole()
{
    // ANSI escape code to clear the screen
    printf("\033[2J");
    // Move the cursor to the top-left corner
    printf("\033[H");
}