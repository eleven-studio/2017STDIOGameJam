#ifndef HEADERS
#define HEADERS
#define MAX_INPUT_LENGTH 80
#define LEVEL_LENGTH 400
void cleanInput(char *userInput, int inputLength);
void cleanBuffer();
void inputToLowerCase(char *userInput, int inputLength);
void error(int *unknownCommand);
void printSomeContent(FILE* contentFile);
void questions(char *userInput, int *unknownCommand, FILE* contentFile);
#endif // HEADERS
