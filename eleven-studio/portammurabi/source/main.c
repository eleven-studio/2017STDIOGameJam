#include <stdio.h>
#include "headers.h"
int main() //the main() function tells the computer to start executing our program from there.
{
    char userInput[MAX_INPUT_LENGTH]; //we'll store every user input in this variable
     FILE* contentFile = NULL; //we'll 'load' every content file we have in this pointer
    int unknownCommand = 0, startLoopIsOn = 0;
    printf("Enter 'start' to play :\n>"); //this first loop messes with the player to start the game
    while (strcmp("please start <3", userInput) != 0 && strcmp("<3 please start <3", userInput) != 0 && strcmp("<3 please start", userInput) != 0){
        askInput(userInput, MAX_INPUT_LENGTH);
        if (strcmp("please start <3", userInput) == 0 || strcmp("<3 please start <3", userInput) == 0 || strcmp("<3 please start", userInput) == 0){
            printf("\n\n\n\n\nI <3 you too. :)\n");}
        else if (strcmp("please start", userInput) == 0){
            printf("And a <3 ?\nI love <3 !\nEnter 'please start <3' to play :\n>");}
        else if (strcmp("please", userInput) == 0){
            printf("Ok, but I meant the whole sentence...\nEnter 'please start' to play :\n>");}
        else if (strcmp("start", userInput) == 0){
            startLoopIsOn = 1;
            printf("Are you sure ? (yes/no) :\n>");
        }
        else if (strcmp("y", userInput) == 0){
            if (startLoopIsOn == 1){
                printf("I'm a simple program\nbut that's no reason\nto use a single character instead of a word.\nYou hurt my feelings.\nAre you sure you want to play ? (yes/no) :\n>");}
            else {
                error(&unknownCommand);}
        }
        else if (strcmp("yes", userInput) == 0){
            if (startLoopIsOn == 1){
                startLoopIsOn = 0;
                printf("Can I have a 'please' then ?\nEnter 'please start' to play :\n>");
            }
            else {
                error(&unknownCommand);}
        }
        else if (strcmp("n", userInput) == 0 || strcmp("no", userInput) == 0){
            if (startLoopIsOn == 1){
                startLoopIsOn = 0;
                printf("No problem, I'll wait.\nEnter 'start' to play :\n>");
            }
            else {
                error(&unknownCommand);}
        }
        else {
            error(&unknownCommand);}
    }
    contentFile = fopen("art/title.txt", "r"); //from here, game goes to the 'portammurabi' part (questions.c)
    printSomeContent(contentFile);
    contentFile = fopen("art/setup.txt", "r");
    printSomeContent(contentFile);
    questions(userInput, &unknownCommand, contentFile);
    printf("I guess all you wanted from this was some 'cake'...\n>"); // and this is the 'ending'
    while (strcmp("cake", userInput) != 0){
        askInput(userInput, MAX_INPUT_LENGTH);
        if (strcmp("cake", userInput) == 0){
            contentFile = fopen("art/cake.txt", "r");
            printSomeContent(contentFile);
        }
    }
    return 0;
}

