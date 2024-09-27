#ifndef MOB_INIT_H
#define MOB_INIT_H

#include <stdio.h>

//*for now all mobs will have the same stats. if theres time, we can change damage type, dealing more or less damage based on where the hero distributed stats. (magic damage does more/less depending on heros magic stat)

typedef struct 
{
    char name[50];
    int level; 
    //level can be determined by either players level to start, or by adding "levels" to the dungeon 
    int exp;
    int hp;
    int attack;
//these are starting stats. level can determine by how much attack/hp goes up. level can also determine exp/gold drop amount
} Mob;

// !not in use
void initializeMob(Mob *MobPtr, const char *name);

#endif /* MOB_INIT_H */