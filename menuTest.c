#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menuTest.h"

int main()
{
    launch();

    return 0;
}

//this is to refresh the console so the previous print statements dont stack up visually.
void clearConsole()
{
    // ANSI escape code to clear the screen
    printf("\033[2J");
    // Move the cursor to the top-left corner
    printf("\033[H");
}


//calls splash screen and user choice for start game
void launch()
{
    char choice;

    splashLogo();

    while (1)
    {
        printf("Start game? y/n");
        scanf(" %c", &choice);
        choice = tolower(choice);


        if ( choice == 'y')
        {
            startMenu();
            break;
        }
        else if (choice == 'n')
        {
            exitGame();
            break;
        }
        else
        {
            printf("Invalid input. Please enter y or n for yes or no.");
        }
    }
}

//prints splash screen logo
void splashLogo()
{
    for (int i = 0; splashLogoArr[i] != NULL; i++)
    {
        printf("%s\n", splashLogoArr[i]);
    }
}

void startMenu()
{
    int choice = 0;

    for (int i = 0; startMenuArr[i] != NULL; i++)
    {
        printf("%s\n", startMenuArr[i]);
    }

    switch (choice)
    {
    case 1:
        newGame();
        break;
    case 2:
        continueGame();
        break;
    case 3:
        exitGame();
        break;
    case 4:
        credits();
        break;

    default:
        printf("OOPS! That's not an option!");
        startMenu();
        break;
    }
}

void mainMenu()
{
    int choice = 0;

    for (int i = 0; mainMenuArr[i] != NULL; i++)
    {
        printf("%s\n", mainMenuArr[i]);
    }

    switch (choice)
    {
    case 1:
        shopMenu();
        break;
    case 2:
        enterDungeon();
        break;
    case 3:
        miniGameMenu();
        break;
    case 4:
        saveAndQuit();
        break;
    case 9:
        cheatMenu();
        break;
    default:
        printf("OOPS! Thats not an option!");
        mainMenu();
        break;
    }
}

void shopMenu()
{
    underConstruction();
}

void enterDungeon()
{
    underConstruction();
}

void miniGameMenu()
{
    underConstruction();
}

void saveAndQuit()
{
    underConstruction();
}

void cheatMenu()
{
    underConstruction();
}

void newGame()
{
    underConstruction();
}

void continueGame()
{
    underConstruction();
}

int exitGame()
{
    printf("Thanks for playing!");
    exit(0);
}

void credits()
{
    underConstruction();
}

void underConstruction()
{
    int choice = 0;
    printf("This feature is under construction :( Check back soon!\n");
    printf("[1]Back to Start Menu \t [2] Back to Main Menu \t [3] Exit");

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