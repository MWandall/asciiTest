#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H
#include "stats.h"



void saveHeroToFile(const Hero *hero, const char *filename);
int loadHeroFromFile(Hero *hero, const char *filename);
int isValidName(const char *name);
void getValidHeroName(char *name, size_t maxLength);
void handleGameOptions();
void HandleNewGame();
void handleContinueGame();



#endif /* FILE_HANDLING_H */