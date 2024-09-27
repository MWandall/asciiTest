#include <stdio.h>
#include "mobPrintFunc.h"

int main()
{
    for (int i = 0; archerResting[i] != NULL && archerResting[i] != NULL; i++)
    {
        printf("%s \t %s\n", archerAttacking[i], archerResting[i]);
    }

    for (int i = 0; mageResting[i] != NULL && mageResting[i] != NULL; i++)
    {
        printf("%s \t %s\n", mageAttacking[i], mageResting[i]);
    }
        for (int i = 0; warriorResting[i] != NULL && warriorResting[i] != NULL; i++)
    {
        printf("%s \t %s\n", warriorAttacking[i], warriorResting[i]);
    }
    
    return 0;
}
