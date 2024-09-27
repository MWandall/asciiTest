#ifndef MOB_PRINT_FUNC_H
#define MOB_PRINT_FUNC_H
#include <stdio.h>

void clearConsole();
void mobAnimation();
void staticMobs();

char *archerResting[] = {
    "             /\\           ",
    "            /  \\    (   / ",
    "           /    \\  (0.0) ",
    "          <\\-----__ \\_// ",
    "            \\  /     / \\ ",
    "             \\/     /   \\",
    NULL
};

char *archerAttacking[] = {
    "               /|           ",
    "              / |     (   / ",
    "             /  |     (0.0) ",
    "<------      \\  |  __ \\_//",
    "              \\ |     / \\ ",
    "               \\|    /   \\",
    NULL
};

char *mageResting[] = {
    "                            ",
    "                            ",
    "                    ,/,     ",
    "                   (o_o )   ",
    "             o.*~~ <(~ <)   ",
    "                    /\\  \\ ",
    NULL
};

char *mageAttacking[] = {
    "                            ",
    "                            ",
    "                   ,/,      ",
    "                 (o_o )     ",
    "o.*~~             <(~ <)    ",
    "                    /\\  \\ ",
    NULL
};

char *warriorResting[] = {
    "                           ",
    "                           ",
    "                   /@_@\\   ",
    "              \\    (-.- ) ", //one less space needed
    "               \\_/  | | \\ ",
    "                \\  /   \\  ",
    NULL
};

char *warriorAttacking[] = {
    "                          ",
    "                          ",
    "               /@_@\\      ",
    "              (-.- )      ", //one less space needed
    "      ______/  | | \\     ",
    "              /   \\      ",
    NULL
};


#endif /* MOB_PRINT_FUNC_H */