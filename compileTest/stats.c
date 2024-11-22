#include "stats.h"
#include <string.h>
#include <stdlib.h>

void initializeHero(Hero *heroPtr, const char *name) {

    //TODO: add conditional for save data

    strcpy(heroPtr->name, name);
    //first name is a pointer to the hero struct
    //second name is what is passed into the function arg
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
Mob initializeMob(int consecutiveFights){
    Mob mob;
        static const char *monster_names[] = {
        "Goblin", "Orc", "Troll", "Skeleton", "Zombie"
    };
    strncpy(mob.name, monster_names[rand() % 5], 49);
    mob.level = 1 + consecutiveFights;
    mob.exp_value = 65 + (rand() % 20); //add expMod in consecutiveFights
    mob.hp = 80 + (consecutiveFights * 10);
    mob.max_hp = mob.hp;
    mob.attack = 12 + (consecutiveFights * 2);

    return mob;
}