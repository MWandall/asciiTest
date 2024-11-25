#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inventory struct
typedef struct
{
    int arrows;
    int potions;
    int gold;
} Inventory;

// Hero struct with nested inventory
typedef struct
{
    char name[50];
    int level;
    int exp;
    int exp_to_next_level;
    int hp;
    int max_hp;
    int attack;
    int magic;
    int consecutiveFights;
    Inventory inventory;
} Hero;

// Function to initialize a new hero
void initializeHero(Hero *heroPtr, const char *name)
{
    strcpy(heroPtr->name, name);
    heroPtr->level = 1;
    heroPtr->exp = 0;
    heroPtr->exp_to_next_level = 10 * heroPtr->level * heroPtr->level;
    heroPtr->hp = 100;
    heroPtr->max_hp = 100;
    heroPtr->attack = 20;
    heroPtr->magic = 15;
    heroPtr->consecutiveFights = 0;
    heroPtr->inventory.arrows = 20;
    heroPtr->inventory.gold = 50;
    heroPtr->inventory.potions = 3;
}

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

// Function to print hero stats
void printHeroStats(const Hero *hero)
{
    printf("\nHero Stats:\n");
    printf("Name: %s\n", hero->name);
    printf("Level: %d\n", hero->level);
    printf("Experience: %d\n", hero->exp);
    printf("Experience to Next Level: %d\n", hero->exp_to_next_level);
    printf("HP: %d/%d\n", hero->hp, hero->max_hp);
    printf("Attack: %d\n", hero->attack);
    printf("Magic: %d\n", hero->magic);
    printf("Consecutive Fights: %d\n", hero->consecutiveFights);
    printf("Inventory - Arrows: %d, Potions: %d, Gold: %d\n", 
           hero->inventory.arrows, hero->inventory.potions, hero->inventory.gold);
}

// Main function to handle new or continued game
void handleGameOptions(Hero *hero)
{
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

        initializeHero(hero, name);
        saveHeroToFile(hero, filename);
        printf("New game initialized and saved.\n");
    }
    else if (choice == 2)
    {
        if (loadHeroFromFile(hero, filename))
        {
            printf("Game loaded successfully! Welcome back, %s.\n", hero->name);
        }
        else
        {
            printf("No save file found or invalid data. Start a new game instead.\n");
            return; // Exit if loading fails
        }
    }
    else
    {
        printf("Invalid choice.\n");
        return; // Exit if invalid choice
    }

    // Print the hero's stats after loading or initializing
    // printHeroStats(hero);
}

int main()
{
    Hero hero;  // Declare the hero variable in main
    handleGameOptions(&hero);  // Pass the hero to the game handling function

    // The stats can now be accessed outside handleGameOptions by calling printHeroStats(hero);
    printHeroStats(&hero);  
    // Optionally, print stats again in main if needed

    return 0;
}
