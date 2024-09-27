#include <stdio.h>
#include <unistd.h>
#include "heroPrintFunc.h"


//TODO: maybe make print hero a switch with faces instead of print, change face, print.
//do it all in one function, not two
int main()
{ 
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        count = i + 1;
        clearConsole();
        switch (count)
        {
        case 1:
            heroExpression(hero, happy);
            
            break;
        case 2:
            heroExpression(hero, surprised);
            
            break;            
        case 3:
            heroExpression(hero, mad);
           
            break;
        case 4:
            heroExpression(hero, annoyed);
            
            break;
        case 5:
            heroExpression(hero, sad);
            
            break;

        default:
            break;
        }
        sleep(1);
        clearConsole();
    }
    
    heroExpression(hero, happy);
    // heroExpression(hero, sad);
    // heroExpression(hero, surprised);
    // heroExpression(hero, mad);
    // heroExpression(hero, annoyed);
    return 0;
}

void printHero()
{
    for (int i = 0; hero[i] != NULL; i++)
    {
        printf("%s\n", hero[i]);
    }
    printf("\n");
}

void heroExpression(char *hero[], char *newFace)
{
 hero[1] = newFace;
 printHero();
}

void clearConsole() {
    // ANSI escape code to clear the screen
    printf("\033[2J");
    // Move the cursor to the top-left corner
    printf("\033[H");
}