#include <stdio.h>
#include "headers.h"
void printSomeContent(FILE* contentFile) // this function reads a file and prints its content
{
    char artLine[MAX_INPUT_LENGTH] = "";
    while (fgets(artLine, MAX_INPUT_LENGTH, contentFile) != NULL){
        printf("%s", artLine);}
    fclose(contentFile);
}
