#include <stdio.h>

    char *heroStatDisplay[] = {
        "+--------------+",
        "| HP:  100/150 |",
        "| Arrows:   52 |",
        "| Gold:   1052 |",
        "+--------------+",
        "                ",
        NULL
    };

    char *hero[] = {
        "           ",
        "           ",
        "           ",
        " (\\(\\    ",
        " ( O_O )   ",
        "o_(\")(\") ",
        NULL
    };

    char *mediumHouseArr[] = {
        "\t\t\t                      ",
        "\t\t\t        @ @ @         ",
        "\t\t\t       []___          ",
        "\t\t\t      /    /\\____    ",
        "\t\t\t(~)  /_/\\_//____/\\  ",
        "\t\t\t |   | || |||__|||    ",
        NULL
    };
    char *groundArr[] = {
        "\t\t\t:::[====][====][====][====][====][====][====]::::::::::::==^=*==",
        "\t\t[====][====][====][====][====][====][====]:::::::::::=^^==*=====",
        "\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::",
        NULL
    };
// Function to print multiple arrays inline
void printHomeSceneInline() {
        for (int i = 0; mediumHouseArr[i] != NULL && hero[i] != NULL && heroStatDisplay[i] != NULL; i++)
    {
        printf("%s \t %s \t %s\n", mediumHouseArr[i], hero[i], heroStatDisplay[i]);
    }
    
}

// Function to print the ground underneath everything else
void printGround() {
    for (int i = 0; groundArr[i] != NULL; i++) {
        printf("%s\n", groundArr[i]);
    }
}

int main() {




    
    printHomeSceneInline();

    // Print the ground separately underneath
    printGround();

    return 0;
}
