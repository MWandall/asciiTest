#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "printFunc.h"
#include "menuMain.h"
#include "stats.h"
#include "fileHandling.h"

int main()
{
    clearConsole();
    launch();

    return 0;
}

// calls splash screen and user choice for starting game
void launch()
{
    char choice;

    printSplashLogo();

    while (1)
    {
        printf("\t\t\t\t\tStart game? y/n\n");
        scanf(" %c", &choice);
        choice = tolower(choice);

        if (choice == 'y')
        {
            startMenu();
            break;
        }
        else if (choice == 'n')
        {
            exitGame();
            break;
        }
        else
        {
            printf("Invalid input. Please enter y or n for yes or no.");
        }
    }
}

// prints menu and user choice for menu nav
void startMenu()
{
    clearConsole();
    int choice = 0;

    // start menu graphic
    printStartMenu();

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        newGame();
        break;
    case 2:
        continueGame();
        break;
    case 3:
        exitGame();
        break;
    case 4:
        credits();
        break;

    default:
        printf("OOPS! That's not an option!");
        while (getchar() != '\n')
            ;
        startMenu();
        break;
    }
}

// starts new game with check if save exists
void newGame()
{
    handleNewGame(); // file handling

    // heroInit will be added here
    mainMenu();
}

// pulls data from csv and starts
void continueGame()
{
    handleContinueGame();
    // underConstruction();
    mainMenu();
}

// prints main menu and user choice for menu nav
void mainMenu()
{
    clearConsole();
    int choice = 0;

    printHomeSceneInline();
    printGround();
    printMainMenu();

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        shopMenu();
        break;
    case 2:
        enterDungeon();
        break;
    case 3:
        rest();
        break;
    case 4:
        saveAndQuit();
        break;
    case 9:
        cheatMenu();
        break;
    default:
        printf("OOPS! Thats not an option!");
        while (getchar() != '\n')
            ;

        mainMenu();
        break;
    }
}

//************************************************************** */
// TODO: in progress for visuals
void enterDungeon()
{
    int choice = 0;
    clearConsole();
    while (globalHero.hp > 0 && globalMob.hp > 0)
    {
        clearConsole();
        printBattleSceneInline();
        printGround();
        printBattleMenu();
        displayFightStatus();

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            clearConsole();
            printBattleSceneInline();
            printGround();
            printFightMenu();
            displayFightStatus();

            int battleChoice = 0;
            scanf("%d", &battleChoice);
            if (battleChoice == 1 || battleChoice == 2 || battleChoice == 3)
            {
                globalMob.hp -= globalHero.attack;
                globalHero.hp -= globalMob.attack;
            }
            else if (choice == 4)
            {
                enterDungeon();
            }
            else
            {
                printf("Invalid choice! Clearing buffer...\n");
                while (getchar() != '\n')
                    ; // Clear the input buffer
            }

            break;
        case 2:
            globalHero.inventory.gold -= 15;
            printf("You ran away but dropped some gold in the confusion...\n");
            printf("Press Enter to continue...");
            while (getchar() != '\n')
                ; // waits for the Enter key
            mainMenu();
            break;
        case 3:
            if (globalHero.inventory.potions >= 1)
            {
                globalHero.inventory.potions -= 1;
                globalHero.hp = globalHero.max_hp;
                printf("You used a potion! HP restored\n");
                printf("Press Enter to continue...");
                while (getchar() != '\n')
                    ;      // Clear any leftover newline
                getchar(); // Wait for Enter
                enterDungeon();
            }
            else
            {
                printf("Oh no! You're out of potions!\n");
            }
            printf("Press Enter to continue...");
            while (getchar() != '\n')
                ;      // Clear any leftover newline
            getchar(); // Wait for Enter
            enterDungeon();

        default:
            printf("OOPS! Thats not an option!");
            printf("Press Enter to continue...");
            while (getchar() != '\n')
                ;      // Clear any leftover newline
            getchar(); // Wait for Enter
            enterDungeon();
            break;
        }
    }

    globalHero.inventory.gold += 100;
    globalMob.hp = globalMob.max_hp;
    printf("Victory! You found some gold.\n");
    printf("Press Enter to continue...");
    while (getchar() != '\n')
        ;      // Clear any leftover newline
    getchar(); // Wait for Enter
    mainMenu();
}
void fight()
{
    // int choice = 0;
    // printHeroDisplay();
    printBattleSceneInline();
    printGround();
    printFightMenu();
    displayFightStatus();
}
void displayFightStatus()
{
    printf("\n\t\t\t-- Status --\n");
    printf("\t\t\t%s: %d/%d HP | Skeleton: %d/%d HP\n", globalHero.name, globalHero.hp, globalHero.max_hp, globalMob.hp, globalMob.max_hp);
}
//************************************************************************** */
void buyItem(int choice)
{
    const char *filename = "savefile.csv"; //  for saving

    switch (choice)
    {
    case 1: // Buy arrows
        if (globalHero.inventory.gold >= 10)
        {
            globalHero.inventory.arrows += 5;
            globalHero.inventory.gold -= 10;
            printf("You bought 5 arrows!\n");
            saveHeroToFile(&globalHero, filename); // Save after purchase
        }
        else
        {
            printf("Not enough gold to buy arrows.\n");
        }
        break;
    case 2: // Buy potion
        if (globalHero.inventory.gold >= 30)
        {
            globalHero.inventory.potions += 1;
            globalHero.inventory.gold -= 30;
            printf("You bought a potion!\n");
            saveHeroToFile(&globalHero, filename); // Save after purchase
        }
        else
        {
            printf("Not enough gold to buy a potion.\n");
        }
        break;

    case 3: // experience potion
        printf("\nOut of stock :(\n");
        break;
    default:
        while (getchar() != '\n')
            ;
        printf("Invalid choice. Please choose a valid item.\n");
        break;
    }
}
void shopMenu()
{

    clearConsole();
    int choice = 0;
    while (1) // Keep showing menu until user exits
    {
        printShopMenu();

        printf("\nYour gold: %d\n", globalHero.inventory.gold);
        printf("\nEnter your choice (1-4): ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ; // Clear input buffer
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (choice == 4) // Back option
        {
            mainMenu();
            return;
        }

        buyItem(choice);

        printf("\nPress Enter to continue...");
        while (getchar() != '\n')
            ;      // Clear any leftover newline
        getchar(); // Wait for Enter
        clearConsole();
    }
}

void rest()
{

    globalHero.hp = globalHero.max_hp;
    mainMenu();
}

void saveAndQuit()
{
    const char *filename = "savefile.csv";
    saveHeroToFile(&globalHero, filename);
    exitGame();
}

// //TODO: make a secret menu to add levels/gold to show more of the games intended progression for presentation
void cheatMenu()
{
    underConstruction();
}

void credits()
{
    printf("\nMitchell Wandall\nMichael Addo\nColby Edwards\n");
    printf("Thanks for playing!\n");

    int choice = 0;
    while (1)
    {
        printf("To go back, press 1.\n");
        if (scanf("%d", &choice) != 1)
        {
            // Clear invalid input
            while (getchar() != '\n')
                ;
            printf("Invalid input. Please press 1.\n");
        }
        else if (choice == 1)
        {
            mainMenu();
            return;
        }
        else
        {
            printf("Invalid input. Please press 1.\n");
        }
    }
}

int exitGame()
{
    printf("\nThanks for playing!");
    exit(0);
}