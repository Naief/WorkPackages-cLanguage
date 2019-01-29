/* ====================================
File name: exerc_2_1.c
Date: 2019-01-26
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [<Ass code 1-4> <abc>]
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 20

//void copyString(char* src, char* dest);

int main(int argc, char *argv[])
{
    char str[MAX_CHAR];
    char strCopy[MAX_CHAR];

    if(argc == 2)
    {
        printf("Reading string from file..\n");
        scanf("%s", &str);
    }
    else if (argc > 2)
    {
        printf("Too many args\n");
    }
    else
    {
        printf("Give me a string to copy(max 20 characters)\n");
        fgets(str, MAX_CHAR, stdin);
    }
    printf("String read from input: %s\n", str);
    strcpy(strCopy, str);
    printf("String copied using strcpy: %s\n", strCopy);
    copyString((str, strCopy));
    printf("String copied using our own method: %s\n", strCopy);
}

void copyString(char* src, char* dest)
{
    //memset(strCopied, '\0', sizeof(strCopied));

    for(int i = 0; i < sizeof(src); i++)
    {
        dest[i] = src[i];
    }
}