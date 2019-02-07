/* ====================================
File name: exerc2_4.c
Date: 2019-01-26
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [7715]
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void isPalindrome(char str[]);

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Not enough arguments\n");
    }
    else if (argc == 2)
    {
        char s1[strlen(argv[1]) + 1];
        strncpy(s1, argv[1], sizeof s1);
        isPalindrome(s1);
    }
    else
    {
        printf("Too many arguments\n");
    }
}

// A function to check if a string str is palindrome
void isPalindrome(char str[])
{
    int l = 0;
    int h = strlen(str) - 1;

    // Keep comparing characters while they are same
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s is Not Palindrome \n", str);
            return;
        }
    }
    printf("%s is palindrome \n", str);
}
