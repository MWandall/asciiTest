#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "printFunc.h"
#include "menuMain.h"
#include "stats.h"






int main()
{
    clearConsole();
    launch();


    return 0;
}


void launch()
{
    char choice;

    printSplashLogo();

    while (1)
    {
        printf("\t\t\t\t\tStart game? y/n\n");
        scanf(" %c", &choice);
        choice = tolower(choice);

        if (choice == 'y')
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



// prints menu and user choice for menu nav
void startMenu()
{
    clearConsole();
    int choice = 0;
    printStartMenu();

    scanf("%d", &choice);

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
        while (getchar() != '\n')
            ;
        startMenu();
        break;
    }
}

//TODO: file handling
void newGame()
{
   // void handleNewGame(const char *saveFilePath);
    // heroInit will be added here
    mainMenu();
}


// //TODO: once file handling is in place, populate heroInit from CSV
void continueGame()
{
    underConstruction();
}

// prints main menu and user choice for menu nav
void mainMenu()
{
    clearConsole();
    int choice = 0;

    printHomeSceneInline();
    printGround();
    printMainMenu();

    scanf("%d", &choice);

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
        while (getchar() != '\n')
            ;

        mainMenu();
        break;
    }
}



//TODO: in progress for visuals
void enterDungeon()
{
    underConstruction();
}

//TODO: if we add mini games
void miniGameMenu()
{
    underConstruction();
}

//TODO: file handling 
void saveAndQuit()
{
    underConstruction();
}


// //TODO: make a secret menu to add levels/gold to show more of the games intended progression for presentation
void cheatMenu()
{
    underConstruction();
}


// // Function to save hero stats to a CSV file
// void saveHeroToFile(const Hero *hero, const char *filename) {
//     FILE *file = fopen(filename, "w");
//     if (!file) {
//         perror("Error opening file for writing");
//         return;
//     }

//     fprintf(file, "%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
//             hero->name, hero->level, hero->exp, hero->exp_to_next_level,
//             hero->hp, hero->max_hp, hero->attack, hero->magic,
//             hero->consecutiveFights, hero->inventory.arrows,
//             hero->inventory.potions, hero->inventory.gold);

//     fclose(file);
// }

// // Function to load hero stats from a CSV file
// int loadHeroFromFile(Hero *hero, const char *filename) {
//     FILE *file = fopen(filename, "r");
//     if (!file) {
//         perror("Error opening file for reading");
//         return 0; // File not found
//     }

//     if (fscanf(file, "%49[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
//                hero->name, &hero->level, &hero->exp, &hero->exp_to_next_level,
//                &hero->hp, &hero->max_hp, &hero->attack, &hero->magic,
//                &hero->consecutiveFights, &hero->inventory.arrows,
//                &hero->inventory.potions, &hero->inventory.gold) != 12) {
//         fclose(file);
//         fprintf(stderr, "Error parsing save file\n");
//         return 0;
//     }

//     fclose(file);
//     return 1; // Success
// }


int exitGame()
{
    printf("\nThanks for playing!");
    exit(0);
}