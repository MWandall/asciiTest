#include "stats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Hero globalHero;//so hero can be accessed everywhere
Mob globalMob = {
    .name = "Skeleton",
    .level = 1,
    .exp_value = 75,
    .hp = 30,
    .max_hp = 30,        
    .attack = 5 

};


void initializeHero(Hero *heroPtr, const char *name)
{
    

    strcpy(heroPtr->name, name);
    // first name is a pointer to the hero struct
    // second name is what is passed into the function arg
    heroPtr->level = 1;
    heroPtr->exp = 0;
    heroPtr->exp_to_next_level = (int)(10 * heroPtr->level * heroPtr->level);
    //*exp gain difficulty might change
    heroPtr->hp = 100;
    heroPtr->max_hp = 100;
    heroPtr->attack = 20;
    heroPtr->magic = 15;
    heroPtr->consecutiveFights = 0;
    heroPtr->inventory.arrows = 20;
    heroPtr->inventory.gold = 50;
    heroPtr->inventory.potions = 3;
}

// save hero stats to a CSV file
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

// load hero stats from a CSV file
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

// validate the hero's name (no comma to break csv)
int isValidName(const char *name)
{
    return strchr(name, ',') == NULL; // Returns 1 if no comma is found, 0 otherwise
}

// get a valid hero name
void getValidHeroName(char *name, size_t maxLength)
{
    int valid = 0;
    do
    {
        printf("Enter hero name (no commas allowed): ");
        fgets(name, maxLength, stdin);

        // remove newline character if present
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
