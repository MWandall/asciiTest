#ifndef HERO_INIT_H
#define HERO_INIT_H
#include <stdio.h>
void initializeHero(Hero *heroPtr, const char *name);
Mob initializeMob(int consecutiveFights);

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

typedef struct
{
    char name[50];
    int level;
    int exp_value;
    int hp;
    int max_hp;
    int attack;
} Mob;

#endif /* HERO_INIT_H */
