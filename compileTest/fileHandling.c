#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"


// Function to save hero stats to a CSV file
void saveHeroToFile(const Hero *hero, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
            hero->name, hero->level, hero->exp, hero->exp_to_next_level,
            hero->hp, hero->max_hp, hero->attack, hero->magic,
            hero->consecutiveFights, hero->inventory.arrows,
            hero->inventory.potions, hero->inventory.gold);

    fclose(file);
}


// Function to load hero stats from a CSV file
int loadHeroFromFile(Hero *hero, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Error opening file for reading");
        return 0; // File not found
    }

    if (fscanf(file, "%49[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
               hero->name, &hero->level, &hero->exp, &hero->exp_to_next_level,
               &hero->hp, &hero->max_hp, &hero->attack, &hero->magic,
               &hero->consecutiveFights, &hero->inventory.arrows,
               &hero->inventory.potions, &hero->inventory.gold) != 12)
    {
        fclose(file);
        fprintf(stderr, "Error parsing save file\n");
        return 0;
    }

    fclose(file);
    return 1; // Success
}

// Function to validate the hero's name
int isValidName(const char *name)
{
    return strchr(name, ',') == NULL; // Returns 1 if no comma is found, 0 otherwise
}

// Function to get a valid hero name
void getValidHeroName(char *name, size_t maxLength)
{
    int valid = 0;
    do
    {
        printf("Enter hero name (no commas allowed): ");
        fgets(name, maxLength, stdin);

        // Remove newline character if present
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n')
        {
            name[len - 1] = '\0';
        }

        if (isValidName(name))
        {
            valid = 1;
        }
        else
        {
            printf("Error: Name cannot contain commas. Please try again.\n");
        }
    } while (!valid);
}

// Main function to handle new or continued game
void handleGameOptions()
{
    Hero hero;
    const char *filename = "savefile.csv";

    printf("Select an option:\n1. New Game\n2. Continue Game\n");
    int choice;
    scanf("%d", &choice);

    getchar(); // Consume leftover newline
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
            getchar(); // Consume leftover newline
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
