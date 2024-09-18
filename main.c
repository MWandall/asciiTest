#include <stdio.h>

void splashLogo();
void launch();
int tempPickMenu();
void startMenu();
void mainMenu();
void bunny();
// void house();
void clearConsole();

int main()
{

    splashLogo();
    launch();

    return 0;
}
void clearConsole() {
    // ANSI escape code to clear the screen
    printf("\033[2J");
    // Move the cursor to the top-left corner
    printf("\033[H");
}

void launch()
{
    int choice = tempPickMenu();

    switch (choice)
    {
    case 1:
        startMenu();
        break;
    case 2:
        mainMenu();
        break;
    default:
        printf("oops! thats not an option\n");
        launch();
        break;
    }
}

void startMenu()
{
    clearConsole();
    printf("\t\t _____                                                             _____ \n");
    printf("\t\t( ___ )                                                           ( ___ )\n");
    printf("\t\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n");
    printf("\t\t |   |\t\t +------------------+-------------------+\t   |   |\n");
    printf("\t\t |   |\t\t |              GAME MENU               |\t   |   |\n");
    printf("\t\t |   |\t\t +------------------+-------------------+\t   |   |\n");
    printf("\t\t |   |\t\t | [1] New Game     | [2] Continue      |\t   |   |\n");
    printf("\t\t |   |\t\t +------------------+-------------------+\t   |   |\n");
    printf("\t\t |   |\t\t | [3] Exit Game    | [3] Credits       |\t   |   |\n");
    printf("\t\t |   |\t\t +------------------+-------------------+\t   |   |\n");
    printf("\t\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n");
    printf("\t\t(_____)                                                           (_____) \n");
}

void mainMenu()
{
    clearConsole();
    // house();
    bunny();
    printf("\t       ___________________________________________________________________________\n");
    printf("\t       ___________________________________________________________________________\n");
    printf("\t\t _____                                                             _____ \n");
    printf("\t\t( ___ )                                                           ( ___ )\n");
    printf("\t\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n");
    printf("\t\t |   |\t\t +------------------+-------------------+\t   |   |\n");
    printf("\t\t |   |\t\t |              Main Menu               |\t   |   |\n");
    printf("\t\t |   |\t\t +------------------+-------------------+\t   |   |\n");
    printf("\t\t |   |\t\t | [1] Shop         | [2] Dungeon       |\t   |   |\n");
    printf("\t\t |   |\t\t +------------------+-------------------+\t   |   |\n");
    printf("\t\t |   |\t\t | [3] Mini Games   | [3] Save & Quit   |\t   |   |\n");
    printf("\t\t |   |\t\t +------------------+-------------------+\t   |   |\n");
    printf("\t\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n");
    printf("\t\t(_____)                                                           (_____) \n");
}

void splashLogo()
{
    printf(" _____                                                                                                         _____ \n");
    printf("( ___ )                                                                                                       ( ___ )\n");
    printf(" |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | \n");
    printf(" |   |                                .o.        .oooooo..o   .oooooo.   ooooo ooooo                           |   | \n");
    printf(" |   |                               .888.      d8P'    `Y8  d8P'  `Y8b  `888' `888'                           |   | \n");
    printf(" |   |                              .8\"888.     Y88bo.      888           888   888                            |   | \n");
    printf(" |   |                             .8' `888.     `\"Y8888o.  888           888   888                            |   | \n");
    printf(" |   |                            .88ooo8888.        `\"Y88b 888           888   888                            |   | \n");
    printf(" |   |                           .8'     `888.  oo     .d8P `88b    ooo   888   888                            |   | \n");
    printf(" |   |                          o88o     o8888o 888888P'   `Y8bood8P'    o888o o888o                           |   | \n");
    // printf(" |   |                                                                                                         |   | \n");
    // printf(" |   |                                                                                                         |   | \n");
    printf(" |   |                                                                                                         |   | \n");
    printf(" |   |       .o.             .o8                                        .                                  .o. |   | \n");
    printf(" |   |      .888.           \"888                                      .o8                                  888 |   | \n");
    printf(" |   |     .8\"888.      .oooo888  oooo    ooo  .ooooo.  ooo. .oo.   .o888oo oooo  oooo  oooo d8b  .ooooo.  888 |   | \n");
    printf(" |   |    .8' `888.    d88' `888   `88.  .8'  d88' `88b `888P\"Y88b    888   `888  `888  `888\"\"8P d88' `88b Y8P |   | \n");
    printf(" |   |   .88ooo8888.   888   888    `88..8'   888ooo888  888   888    888    888   888   888     888ooo888 `8' |   | \n");
    printf(" |   |  .8'     `888.  888   888     `888'    888    .o  888   888    888 .  888   888   888     888    .o .o. |   | \n");
    printf(" |   | o88o     o8888o `Y8bod88P\"     `8'     `Y8bod8P' o888o o888o   \"888\"  `V88V\"V8P' d888b    `Y8bod8P' Y8P |   | \n");
    printf(" |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| \n");
    printf("(_____)                                                                                                       (_____)\n");
}

int tempPickMenu()
{
    int choice = 0;

    printf("\t\t\t\t\t pick menu to view\n");
    printf("\t\t\t+------------------------------------------------+\n");
    printf("\t\t\t| [1] Start Menu \t| [2] Main Menu \t |\n");
    printf("\t\t\t+------------------------------------------------+\n");

    scanf("%d", &choice);
    return choice;
}

void bunny()
{
    printf("\t\t\t\t  @ @ @\n");
    printf("\t\t\t\t  []___	\n");
    printf("\t\t\t\t /    /\\ \t (\\(\\ \n");
    printf("\t\t\t\t/____/__\\ \t ( O_O ) \n");
    printf("\t\t\t\t|[][]|||| \t o_(\")(\") \n");
}

void house()
{
    // make switch statement for house upgrades
    printf("\t\t  []___	\n");
    printf("\t\t /    /\\ \n");
    printf("\t\t/____/__\\ \n");
    printf("\t\t|[][]||||\n");

    

}

// have a different expressions print statement
// printf("\t\t\t\t (\\(\\ \n");
// expression();
// printf("\t\t\t\t o_(\")(\") \n");
