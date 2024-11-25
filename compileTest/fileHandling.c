#include <stdio.h>
#include "stats.h"

// checks if file exists, if so, ask if overwrite then initialize
// if not, begin initialize
void handleNewGame()
{
    
    const char *filename = "savefile.csv";

    // Check if save file exists
    FILE *file = fopen(filename, "r");
    if (file)
    {
        fclose(file);
        printf("A save file already exists. Overwrite? (y/n): ");
        char overwrite;
        scanf(" %c", &overwrite);
        getchar(); // remove leftover newline
        if (overwrite != 'y' && overwrite != 'Y')
        {
            printf("New game canceled.\n");
            return;
        }
    }

    char name[50];
    getValidHeroName(name, sizeof(name)); // Get valid hero name

    initializeHero(&globalHero, name);
    saveHeroToFile(&globalHero, filename);
    printf("New game initialized and saved.\n");
}

// pulls info from savefile.csv
void handleContinueGame()
{
    
    const char *filename = "savefile.csv";

    if (loadHeroFromFile(&globalHero, filename))
    {
        printf("Game loaded successfully! Welcome back, %s.\n", globalHero.name);
    }
    else
    {
        printf("No save file found or invalid data. Start a new game instead.\n");
    }
}

// void handleGameOptions()
// {
//     printf("\n1. New Game   2. Continue Game\n");
//     int choice = 0;
//     switch (choice)
//     {
//     case 1:
//         handleNewGame();
//         break;
//     case 2:
//         handleContinueGame();
//         break;

//     default:
//         break;
//     }
// }

// int main()
// {
//     handleGameOptions();
//     return 0;
// }
