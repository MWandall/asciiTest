#include <stdio.h>
#include <unistd.h>

void mageResting();
void mageAttacking();
void archerResting();
void archerAttacking();
void warriorResting();
void warriorAttacking();

void clearConsole() {
    // ANSI escape code to clear the screen
    printf("\033[2J");
    // Move the cursor to the top-left corner
    printf("\033[H");
}



int mobChoice(){

    int choice = 0;
    
    printf("Pick attacker\n");
    printf("[1] mage  [2] archer  [3] warrior\n");
    scanf("%d", &choice);

if (choice != 0)
{
    switch (choice)
    {
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    
    default:
        break;
    }
}

    return 0;
}



int main() {
    int mob = mobChoice();


    for (int i = 0; i < 5; i++) {
        // Clear the console
        clearConsole();

        // Print ASCII art or game update
        if (i %2 == 0)
        {
            if (mob == 1)
            {
                mageResting();
            } else if (mob == 2)
            {
                archerResting();
            } else
            {
                warriorResting();
            }
                
        }
        else{
            if (mob == 1)
            {
                mageAttacking();
            } else if (mob == 2)
            {
                archerAttacking();
            } else
            {
                warriorAttacking();
            }
        }
        // Simulate a delay (sleep for 1 second)
        sleep(1);
    }

    return 0;
}

void mageResting() {

    printf("\t\t         ,/,\n");
    printf("\t\t        (o_o )\n");
    printf("\t\t  o.*~~ <(~ <) \n");
    printf("\t\t         /\\  \\ \n");
}

void mageAttacking(){

    printf("\t            ,/,\n");
    printf("\t         (o_o )\n");
    printf("\to.*~~     <(~ <)\n");
    printf("\t            /\\  \\\n");

}

void archerResting() {

    printf("\t\t   /\\          \n");
    printf("\t\t  /  \\    (   / \n");    
    printf("\t\t /    \\   (0.0)\n");
    printf("\t\t<\\-----__ \\_//\n");
    printf("\t\t  \\  /     / \\ \n");
    printf("\t\t   \\/     /   \\\n");
}

void archerAttacking(){

    printf("\t               /|          \n");
    printf("\t              / |     (   / \n");    
    printf("\t             /  |     (0.0)\n");
    printf("\t<------      \\  |  __ \\_//\n");
    printf("\t              \\ |     / \\ \n");
    printf("\t               \\|    /   \\\n");
}
void warriorResting() {

    printf("\t\t\t     /@_@\\\n");
    printf("\t\t\t\\    (-.- )\n");
    printf("\t\t\t \\_/  | | \\ \n");
    printf("\t\t\t  \\  /   \\  \n");
}

void warriorAttacking(){
    printf("\t\t        /@_@\\\n");
    printf("\t\t       (-.- )\n");
    printf("\t\t______/  | | \\\n");
    printf("\t\t        /   \\\n");

}

