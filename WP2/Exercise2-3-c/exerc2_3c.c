/* ====================================
File name: exerc2_3.c
Date: 2019-01-26
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [7099]
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        printf("Not enough arguments\n");
    }
    else if (argc == 3)
    {
        char *str1 = argv[1];
        char *str2 = argv[2];
        //debug statements for checking string input is correct
        //puts(str1);
        //puts(str2);

        //strcmp is string compare
        printf("Checking if strings are equal using strcmp: \n");
        if (strcmp(str1, str2) == 0)
        {
            printf("Strings are equal\n");
        }
        else
        {
            printf("Strings are not equal\n");
        }
        printf("Checking if strings are equal with created function: \n");
        if (comparison(argv[1], argv[2]) == 0)
        {
            printf("Strings are equal\n");
        }
        else
        {
            printf("Strings are not equal\n");
        }
    }
    else
    {
        printf("Too many arguments\n");
    }
}

int comparison(char *string1, char *string2)
{
    /*declare variables*/
    int result = 0;
    int i = 0;

    /*loop that checks if the pointer is not pointing at NULL*/
    while (*string1 != '\0')
    {
        /*checks if character at i is not equal to the other character in the string, otherwise, increment*/
        if (*string1 != *string2)
        {
            result = 1;
            break;
        }
        *string1++;
        *string2++;
        i++;
    }

    if (!(*string1 == '\0' && *string2 == '\0'))
    {
        result = 1;
    }

    return result;
}
