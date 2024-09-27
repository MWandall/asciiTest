#include "mobInit.h"
#include <string.h>
#include <stdlib.h>

// TODO: look into (*mobPtr).health = 100 vs mobPtr->health = 100

int main()
{
    //*looks like initializeMob() needs refactor. array works for now. just feed csv arr
    //*if i want this to work, may want structs for each mob
    // Mob archer;
    // Mob mage;
    // Mob warrior;
    // initializeMob(&archer, "archer"),
    // initializeMob(&mage, "Mage"),
    // initializeMob(&warrior, "Warrior"),

//initialize mobs for testing
Mob mobs[3] = {
    {"Archer", 1, 5, 25, 10},
    {"Mage", 1, 5, 30, 5},
    {"Warrior", 1, 5, 20, 15},
};


for (int i = 0; i < 3; i++)
{
    printf("\n");
    printf("Mob Name: %s\n", mobs[i].name);
    printf("Level: %d\n", mobs[i].level);
    printf("Exp: %d\n", mobs[i].exp);
    printf("HP: %d\n", mobs[i].hp);
    printf("Attack: %d\n", mobs[i].attack);
}

return 0;
}


//!  Not in use
void initializeMob(Mob *mobPtr, const char *name)
{
    // first name is a pointer to the mob struct
    // second name is what is passed into the function arg
    strcpy(mobPtr->name, name);
    mobPtr->level = 1;
    mobPtr->exp = 5; // idk if ill need this. might just have conditional after fight is won. (mob.level * 10 = exp given to hero)
    mobPtr->hp = 25;
    mobPtr->attack = 5;
}