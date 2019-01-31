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
Demonstration code: [<Ass code 1-4> <abc>]
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
    int result = 0;
    printf("%d\n", size1);
    printf("%d\n", size2);
    int i = 0;

    while (*string1 != '\0')
    {
        printf("%d\n", i);
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
