#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "printFunc.h"


// prints splash screen logo
void printSplashLogo()
{
    for (int i = 0; splashLogoArr[i] != NULL; i++)
    {
        printf("%s\n", splashLogoArr[i]);
    }
}

// prints menu and user choice for menu nav
void printStartMenu()
{
    for (int i = 0; startMenuArr[i] != NULL; i++)
    {
        printf("%s\n", startMenuArr[i]);
    }
}

// prints main menu and user choice for menu nav
void printMainMenu()
{
    for (int i = 0; mainMenuArr[i] != NULL; i++)
    {
        printf("%s\n", mainMenuArr[i]);
    }
}

// prints home scene
void printHomeSceneInline()
{
    for (int i = 0; mediumHouseArr[i] != NULL && hero[i] != NULL && heroStatDisplay[i] != NULL; i++)
    {
        printf("%s \t %s \t %s\n", mediumHouseArr[i], hero[i], heroStatDisplay[i]);
    }
}

//ground tiles
void printGround()
{
    for (int i = 0; groundArr[i] != NULL; i++)
    {
        printf("%s\n", groundArr[i]);
    }
}

//menu for shop
void printShopMenu()
{

    for (int i = 0; shopMenuArr[i] != NULL; i++)
    {
        printf("%s\n", shopMenuArr[i]);
    }
    
}


void printHero()
{
    for (int i = 0; hero[i] != NULL; i++)
    {
        printf("%s\n", hero[i]);
    }
    printf("\n");
}

// we can update hero's facial expression from new face array
void heroExpression(char *hero[], char *newFace)
{
 hero[1] = newFace;
 printHero();
}

// these are printouts of the mobs. we will use them like in the home scene
//TODO: these are still tests
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

// when the mobs attack, they will do one round of animation
//TODO: these are still tests
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

// if you hit a menu that is incomplete
void underConstruction()
{
    int choice = 0;
    printf("This feature is under construction :( Check back soon!\n\n");
    printf("[1]Back to Start Menu \t [2] Back to Main Menu \t [3] Exit\n");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        startMenu();
        break;
    case 2:
        mainMenu();
        break;
    case 3:
        exitGame();
        break;

    default:
        break;
    }
}

void clearConsole()
{
    // ANSI escape code to clear the screen
    printf("\033[2J");
    // Move the cursor to the top-left corner
    printf("\033[H");
}