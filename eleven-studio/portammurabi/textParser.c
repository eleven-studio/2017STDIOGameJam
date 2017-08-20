//every function listed here does something regarding user input
#include <stdio.h> 
#include "headers.h"
void cleanInput(char *userInput, int inputLength){ //gets user input as a string
    char *nCharacterPosition = NULL;
    if (fgets(userInput, inputLength, stdin) != NULL){ //gets user input as a string (when user presses return, \n is added to the string)
        nCharacterPosition = strchr(userInput, '\n'); //searching for \n
        if (nCharacterPosition != NULL){
            *nCharacterPosition = '\0';} //replacing \n with \0 (expressing the end of the string)
        else {
            cleanBuffer();}
    }
    else {
        cleanBuffer();}
}
void cleanBuffer(){ //removing what's left from user input in memory to prevent future errors
    int i = 0;
    while (i != '\n' && i != EOF){
        i = getchar();}
}
void inputToLowerCase(char *userInput, int inputLength){ //converting user input to lower case
    int i = 0;
    for(i = 0 ; i < inputLength ; i++){
        if(userInput[i] >= 65 && userInput[i] <= 90){ //see ASCII table for character values
            userInput[i] = userInput[i] + 32;}
    }
}
void askInput(char *userInput, int inputLength){ //calls all of the above
    cleanInput(userInput, MAX_INPUT_LENGTH);
    inputToLowerCase(userInput, MAX_INPUT_LENGTH);
}
