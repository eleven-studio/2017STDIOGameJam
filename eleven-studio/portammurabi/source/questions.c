#include <stdio.h>
#include "headers.h"
void questions(char *userInput, int *unknownCommand, FILE* contentFile)
{
    int questionAnswered = 0, ending = 0 , loop = 0, tarbooshIsOn = 0;
    while (ending != 11){
        if (questionAnswered == 0){ // this is the first question, the same process is repeated for the other questions
            if (tarbooshIsOn == 0){
                printf("How many test chambers do you wish to buy or sell ? (Use digits)\n>");}
            else {
                printf("|\n>");} //we 'rotate the text 90 degrees' if 'tarboosh' is used
            askInput(userInput, MAX_INPUT_LENGTH);
            if(strtol(userInput, NULL, 10) != 0) //we want to receive a number before going to the next question
                questionAnswered = 1;
            else if(strcmp("www", userInput) == 0){ //or 'www'
                if (tarbooshIsOn == 0) {
                    printf("All your test chambers went flying...\n>");}
                else {
                    printf("|\n>");}
                questionAnswered = 1;
                ending = 1;
            }
            else if(strcmp("tarboosh", userInput) == 0){
                if (tarbooshIsOn == 0){
                    tarbooshIsOn = 1;}
                else {
                    tarbooshIsOn = 0;}
                ending = 2;
            }
            else {
                error(unknownCommand);}
        }
        if (questionAnswered == 1)
        {
            if (tarbooshIsOn == 0) {
                printf("How many companion cubes do you wish to give your test subjects ? (Use digits)\n>");}
            else {
                printf("|\n>");}
            askInput(userInput, MAX_INPUT_LENGTH);
            if(strtol(userInput, NULL, 10) != 0){
                questionAnswered = 2;}
            else if(strcmp("www", userInput) == 0){
                if (tarbooshIsOn == 0) {
                    printf("All your companion cubes went in the air...\n>");}
                else {
                    printf("|\n>");}
                questionAnswered = 2;
                ending = 1;
            }
            else if(strcmp("tarboosh", userInput) == 0){
                if (tarbooshIsOn == 0){
                    tarbooshIsOn = 1;}
                else {
                    tarbooshIsOn = 0;}
                ending = 2;
            }
            else {
                error(unknownCommand);}
        }
        if (questionAnswered == 2)
        {
            if (tarbooshIsOn == 0) {
                printf("How many test chambers do you wish to test ? (Use digits)\n>");}
             else {
                    printf("|\n>");}
            askInput(userInput, MAX_INPUT_LENGTH);
            if(strtol(userInput, NULL, 10) != 0){
                questionAnswered = 3;
                loop++;
            }
            else if(strcmp("www", userInput) == 0){
                if (tarbooshIsOn == 0) {
                    printf("All your test subjects are in space...\n>");}
                else {
                    printf("|\n>");}
                questionAnswered = 3;
                loop++;
                ending = 1;
            }
            else if(strcmp("tarboosh", userInput) == 0){
                if (tarbooshIsOn == 0){
                    tarbooshIsOn = 1;}
                else {
                    tarbooshIsOn = 0;}
                ending = 2;
            }
            else{
                error(unknownCommand);}
        }
        if (questionAnswered  == 3){
            if (ending == 0){
                contentFile = fopen("art/ending0.txt", "r");
                printSomeContent(contentFile);
            }
            else if (ending == 1){
                contentFile = fopen("art/ending1.txt", "r");
                printSomeContent(contentFile);
            }
            else if (ending == 2 || loop == 2){// we use loop here cause ending wouldn't show if player uses another command (like 'www') after using tarboosh (that's 'hacky' but i'm running late...)
                contentFile = fopen("art/ending2.txt", "r");
                printSomeContent(contentFile);
                ending = 11;
            }
            if (ending != 11){ //if we haven't reached the 'real' end we ask the 3 questions
                questionAnswered = 0;
                contentFile = fopen("art/setup.txt", "r");
                printSomeContent(contentFile);
            }
        }
    }
}
