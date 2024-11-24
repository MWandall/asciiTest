#include <stdio.h>
#include "stats.h"



// Main function to handle new or continued game
void handleGameOptions()
{
    Hero hero;
    const char *filename = "savefile.csv";

    printf("Select an option:\n1. New Game\n2. Continue Game\n");
    int choice;
    scanf("%d", &choice);

    getchar(); // remove leftover newline
    if (choice == 1)
    {
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

        initializeHero(&hero, name);
        saveHeroToFile(&hero, filename);
        printf("New game initialized and saved.\n");
    }
    else if (choice == 2)
    {
        if (loadHeroFromFile(&hero, filename))
        {
            printf("Game loaded successfully! Welcome back, %s.\n", hero.name);
        }
        else
        {
            printf("No save file found or invalid data. Start a new game instead.\n");
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }
}

int main()
{
    handleGameOptions();
    return 0;
}
