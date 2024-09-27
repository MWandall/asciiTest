#ifndef HERO_INIT_H
#define HERO_INIT_H

#include <stdio.h>

typedef struct 
{
    char name[50];
    int level;
    int exp;
    int hp;
    int attack;
    int magic; //maybe string? spell name? or have spells associated with numbers
    int arrows;
    int house_level; //cosmetic
} Hero;

typedef struct
{
    int potions;
    int gold;
    //maybe add list of spells for buffs/debuffs in combat?

} Inventory;

void initializeHero(Hero *heroPtr, const char *name);
void initializeInventory(Inventory *inventoryPtr);


#endif /* HERO_INIT_H */