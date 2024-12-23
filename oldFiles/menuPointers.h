// #ifndef MENU_POINTERS_H
// #define MENU_POINTERS_H

// #include <stdio.h>


// void clearConsole();
// void launch();
// void splashLogo();
// void startMenu();
// void mainMenu();
// void shopMenu();
// void enterDungeon();
// void miniGameMenu();
// void saveAndQuit();
// void cheatMenu();
// void newGame();
// void continueGame();
// void exitGame();
// void credits();
// void underConstruction();
// void heroExpression(char *hero[], char *newFace);


// typedef struct {
//     char **displayArr;   // Array to print the menu content
//     void (*options[10])(); // Array of function pointers for up to 10 options
//     int numOptions;      // Number of options in the menu
// } Menu;

// Menu STARTMenu = {
//     startMenuArr,    // Display content
//     { newGame, continueGame, exitGame, credits }, // Function pointers to menu actions
//     4   // Number of valid options
// };

// Menu mainMenu = {
//     mainMenuArr,    
//     { shopMenu, enterDungeon, miniGameMenu, saveAndQuit, cheatMenu },
//     5
// };




// char *splashLogoArr[] = {
//     " _____                                                                                                         _____ ",
//     "( ___ )                                                                                                       ( ___ )",
//     " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ",
//     " |   |                                .o.        .oooooo..o   .oooooo.   ooooo ooooo                           |   | ",
//     " |   |                               .888.      d8P'    `Y8  d8P'  `Y8b  `888' `888'                           |   | ",
//     " |   |                              .8\"888.     Y88bo.      888           888   888                            |   | ",
//     " |   |                             .8' `888.     `\"Y8888o.  888           888   888                            |   | ",
//     " |   |                            .88ooo8888.        `\"Y88b 888           888   888                            |   | ",
//     " |   |                           .8'     `888.  oo     .d8P `88b    ooo   888   888                            |   | ",
//     " |   |                          o88o     o8888o 888888P'   `Y8bood8P'    o888o o888o                           |   | ",
//     " |   |                                                                                                         |   | ",
//     " |   |       .o.             .o8                                        .                                  .o. |   | ",
//     " |   |      .888.           \"888                                      .o8                                  888 |   | ",
//     " |   |     .8\"888.      .oooo888  oooo    ooo  .ooooo.  ooo. .oo.   .o888oo oooo  oooo  oooo d8b  .ooooo.  888 |   | ",
//     " |   |    .8' `888.    d88' `888   `88.  .8'  d88' `88b `888P\"Y88b    888   `888  `888  `888\"\"8P d88' `88b Y8P |   | ",
//     " |   |   .88ooo8888.   888   888    `88..8'   888ooo888  888   888    888    888   888   888     888ooo888 `8' |   | ",
//     " |   |  .8'     `888.  888   888     `888'    888    .o  888   888    888 .  888   888   888     888    .o .o. |   | ",
//     " |   | o88o     o8888o `Y8bod88P\"     `8'     `Y8bod8P' o888o o888o   \"888\"  `V88V\"V8P' d888b    `Y8bod8P' Y8P |   | ",
//     " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ",
//     "(_____)                                                                                                       (_____)",

//     NULL};

// char *startMenuArr[] = {
//     "\t\t _____                                                             _____ ",
//     "\t\t( ___ )                                                           ( ___ )",
//     "\t\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ",
//     "\t\t |   |\t\t +------------------+-------------------+\t   |   |",
//     "\t\t |   |\t\t |             START MENU               |\t   |   |",
//     "\t\t |   |\t\t +------------------+-------------------+\t   |   |",
//     "\t\t |   |\t\t | [1] New Game     | [2] Continue      |\t   |   |",
//     "\t\t |   |\t\t +------------------+-------------------+\t   |   |",
//     "\t\t |   |\t\t | [3] Exit Game    | [4] Credits       |\t   |   |",
//     "\t\t |   |\t\t +------------------+-------------------+\t   |   |",
//     "\t\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ",
//     "\t\t(_____)                                                           (_____) ",

//     NULL};

// char *mainMenuArr[] = {
//     "\t\t _____                                                             _____ ",
//     "\t\t( ___ )                                                           ( ___ )",
//     "\t\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ",
//     "\t\t |   |\t\t +------------------+-------------------+\t   |   |",
//     "\t\t |   |\t\t |              Main Menu               |\t   |   |",
//     "\t\t |   |\t\t +------------------+-------------------+\t   |   |",
//     "\t\t |   |\t\t | [1] Shop         | [2] Dungeon       |\t   |   |",
//     "\t\t |   |\t\t +------------------+-------------------+\t   |   |",
//     "\t\t |   |\t\t | [3] Mini Games   | [4] Save & Quit   |\t   |   |",
//     "\t\t |   |\t\t +------------------+-------------------+\t   |   |",
//     "\t\t |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ",
//     "\t\t(_____)                                                           (_____) ",
//     NULL};

// char *smallhouseArr[] = {
//     "  []___	 ",
//     " /    /\\  ",
//     "/____/__\\ ",
//     "|[][]||||   ",
//     NULL};

// char *mediumhouseArr[] = {
//     "        @ @ @       ",
//     "       []___        ",
//     "      /    /\\____   ",
//     "(~)  /_/\\_//____/\\  ",
//     " |   | || |||__|||  ",
//     NULL};

// char *largeHouseArr[] = {
//     "     ':.                   ",
//     "         []_____           ",
//     "        /\\      \\          ",
//     "    ___/  \\__/\\__\\__       ",
//     "---/\\___\\ |''''''|__\\-- --- ",
//     "   ||'''| |''||''|''|       ",
//     "   ``\"\"\"`\"`\"\"))\"\"`\"\"`       ",
//     NULL};

// char *castleArr[] = {
//     " [][][] /"
//     "\\ [][][] ",
//     "  |::| /____\\ |::|  ",
//     "  |[]|_|::::|_|[]|  ",
//     "  |::::::__::::::|  ",
//     "  |:::::/||\\:::::|  ",
//     "  |:#:::||||::#::|  ",
//     NULL};

// char *largeCastleArr[] = {

//     "                   T~~  ",
//     "               |        ",
//     "              /\"\\       ",
//     "      T~~     |'| T~~   ",
//     "  T~~ |    T~ WWWW|     ",
//     "  |  /\"\\   |  |  |/\\T~~ ",
//     " /\"\\ WWW  /\"\\ |' |WW|   ",
//     "WWWWW/\\| /   \\|'/\\|/\"\\  ",
//     "|   /__\\/]WWW[\\/__\\WWWW ",
//     "|\"  WWWW'|I_I|'WWWW'  | ",
//     "|   |' |/  -  \\|' |'  | ",
//     "|'  |  |LI=H=LI|' |   | ",
//     "|   |' | |[_]| |  |'  | ",
//     "|   |  |_|###|_|  |   | ",
//     "'---'--'-/___\\-'--'---' ",
//     NULL

// };

// char *hero[] = {
//     " (\\(\\    ",
//     " ( O_O )   ",
//     "o_(\")(\") ",
//     NULL

// };
// char *happy = " ( ^.^ )   ";
// char *surprised = " ( O_O )   ";
// char *mad = " ( >.< )   ";
// char *annoyed = " ( -.- )   ";
// char *sad = " ( ;_; )   ";

// #endif /* MENU_POINTERS_H*/