// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// #include "menuPointers.h"

// int main()
// {
//     clearConsole();
//     launch();

//     return 0;
// }

// void launch() {
//     char choice;
//     splashLogo();

//     while (1) {
//         printf("\t\t\t\t\tStart game? y/n\n");
//         scanf(" %c", &choice);
//         choice = tolower(choice);

//         if (choice == 'y') {
//             handleMenu(STARTMenu);
//             break;
//         } else if (choice == 'n') {
//             exitGame();
//             break;
//         } else {
//             printf("Invalid input. Please enter y or n.\n");
//         }
//     }
// }

// void handleMenu(Menu menu) {
//     clearConsole();

//     // Print menu display
//     for (int i = 0; menu.displayArr[i] != NULL; i++) {
//         printf("%s\n", menu.displayArr[i]);
//     }
//     int choice = 0;
//     scanf("%d", &choice);

//     // Validate input and call the corresponding function
//     if (choice > 0 && choice <= menu.numOptions) {
//         menu.options[choice - 1]();  // Call the chosen function
//     } else {
//         printf("Invalid option! Please try again.\n");
//         handleMenu(menu);  // Retry the menu
//     }
// }

// void startMenu() {
//     handleMenu(STARTMenu);
// }

// void mainMenu() {
//     handleMenu(mainMenu);
// }





// void underConstruction() {
//     printf("This feature is under construction :( Check back soon!\n");
//     printf("[1] Back to Start Menu \t [2] Back to Main Menu \t [3] Exit\n");

//     int choice;
//     scanf("%d", &choice);

//     switch (choice) {
//         case 1: handleMenu(startMenu); break;
//         case 2: handleMenu(mainMenu); break;
//         case 3: exitGame(); break;
//         default: printf("Invalid input!"); underConstruction(); break;
//     }
// }
