#include <stdio.h>

void printMeSomeArt(char myChar, int eighty, FILE* myFile, int fromLine, int toLine)
{
    int i = 0;
    for(i = fromLine ; i < toLine ; i++)
    {
        strcpy(myChar, "");
        fgets(myChar, 80, myFile);
        printf("%s", myChar);
    }
}
