#include <stdio.h>
#include <string.h>

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
    Inventory inventory;
} Hero;

// Function prototypes
void displayShop();
void buyItem(Hero *hero, int choice);

int main()
{
    // Initialize hero
    Hero hero = {
        "Archer",
        1,
        0,
        100,
        100,
        100,
        10,
        5,
        {10, 2, 1050} // 10 arrows, 2 potions, 1050 gold
    };

    int choice;

    // Shop menu loop
    while (1)
    {
        printf("\nWelcome to the shop, %s!\n", hero.name);
        printf("Your gold: %d\n", hero.inventory.gold);
        printf("Your inventory: %d arrows, %d potions\n\n", hero.inventory.arrows, hero.inventory.potions);

        displayShop();
        printf("Choose an item to buy (1-4): ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            printf("Thank you for visiting the shop!\n");
            break;
        }

        buyItem(&hero, choice);
    }

    return 0;
}

// Display shop items
void displayShop()
{
    printf("1. Arrows x5 (10 gold)\n");
    printf("2. Potion (30 gold)\n");
    printf("3. Experience Potion (1000 gold)\n");
    printf("4. Exit shop\n");
}

// Handle buying items
void buyItem(Hero *hero, int choice)
{
    switch (choice)
    {
    case 1: // Buy arrows
        if (hero->inventory.gold >= 10)
        {
            hero->inventory.arrows += 5;
            hero->inventory.gold -= 10;
            printf("You bought 5 arrows!\n");
        }
        else
        {
            printf("Not enough gold to buy arrows.\n");
        }
        break;
    case 2: // Buy potion
        if (hero->inventory.gold >= 30)
        {
            hero->inventory.potions += 1;
            hero->inventory.gold -= 30;
            printf("You bought a potion!\n");
        }
        else
        {
            printf("Not enough gold to buy a potion.\n");
        }
        break;
    case 3: // Buy experience potion
        if (hero->inventory.gold >= 1000)
        {
            hero->exp += 100; // Add 100 exp for this example
            hero->inventory.gold -= 1000;
            printf("You bought an experience potion and gained 100 EXP!\n");
            // Check for level up
            while (hero->exp >= hero->exp_to_next_level)
            {
                hero->exp -= hero->exp_to_next_level;
                hero->level++;
                hero->exp_to_next_level += 100; // Increment EXP needed for next level
                hero->max_hp += 10;
                hero->hp = hero->max_hp;
                hero->attack += 2;
                hero->magic += 1;
                printf("Level up! You are now level %d.\n", hero->level);
            }
        }
        else
        {
            printf("Not enough gold to buy an experience potion.\n");
        }
        break;
    default:
        while (getchar() != '\n')
            ;
        printf("Invalid choice. Please choose a valid item.\n");
        break;
    }
}
