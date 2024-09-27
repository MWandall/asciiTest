#include "heroInit.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    //TODO: handle Hero name from save file or created in new game
    //*make sure to not let users have comma in name if stored in csv. might blow up
    Hero hero1;
    initializeHero(&hero1, "CoolHeroName"); 
    //args (pointer to hero struct, const char *name to assign name to hero)
    Inventory inventory1;
    initializeInventory(&inventory1);

    printf("\t    Hero Name: %s\n", hero1.name);
    printf("\tLevel: %d \t Exp: %d\n\n", hero1.level, hero1.exp);
    printf("   -----Hero stats-----Hero Inventory-----\n\n");
    printf("\tHP: %d \t Arrows: %d\n", hero1.hp, hero1.arrows);
    printf("\tAttack: %d \t Gold: %d\n", hero1.attack, inventory1.gold);
    printf("\tMagic: %d \t Potions: %d\n", hero1.magic, inventory1.potions);



    return 0;
}

void initializeHero(Hero *heroPtr, const char *name) {

//TODO: look into (*heroPtr).health = 100 vs heroPtr->health = 100

//*starting stats.  add conditional if user has save file and populate with those stats

    strcpy(heroPtr->name, name);
    //first name is a pointer to the hero struct
    //second name is what is passed into the function arg
    heroPtr->level = 1;
    heroPtr->exp = 0;
    heroPtr->hp = 100;
    heroPtr->attack = 10;
    heroPtr->magic = 1;
    heroPtr->arrows = 10;
    heroPtr->house_level = 1;

}

void initializeInventory(Inventory *inventoryPtr){
    inventoryPtr->potions = 5;
    inventoryPtr->gold = 10;

}