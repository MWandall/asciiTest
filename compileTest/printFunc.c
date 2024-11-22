#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "printFunc.h"

void printSplashLogo()
{
    for (int i = 0; splashLogoArr[i] != NULL; i++)
    {
        printf("%s\n", splashLogoArr[i]);
    }
}
void printStartMenu()
{
    for (int i = 0; startMenuArr[i] != NULL; i++)
    {
        printf("%s\n", startMenuArr[i]);
    }
}

void printMainMenu()
{
    for (int i = 0; mainMenuArr[i] != NULL; i++)
    {
        printf("%s\n", mainMenuArr[i]);
    }
}

void printHomeSceneInline()
{
    for (int i = 0; mediumHouseArr[i] != NULL && hero[i] != NULL && heroStatDisplay[i] != NULL; i++)
    {
        printf("%s \t %s \t %s\n", mediumHouseArr[i], hero[i], heroStatDisplay[i]);
    }
}

void printGround()
{
    for (int i = 0; groundArr[i] != NULL; i++)
    {
        printf("%s\n", groundArr[i]);
    }
}

void printShopMenu()
{

    for (int i = 0; shopMenuArr[i] != NULL; i++)
    {
        printf("%s\n", shopMenuArr[i]);
    }
    
}

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