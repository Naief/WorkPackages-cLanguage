/* ====================================
File name: exerc2_7.c
Date: 2019-02-07
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
#include <stdbool.h>

//function declarations
bool readPersnr(char *person);
int controlDigit(const char *persnr);

int main()
{
    char persnr[12];
    //main program loop
    while (persnr[0] != 'q' && persnr[0] != 'Q')
    {
        printf("Enter a personnummer or press q to quit\n");
        scanf("%s", persnr);
        if (persnr[0] != 'q' && persnr[0] != 'Q')
        {
            //checks if personnummer has a basic
            bool nrIsCorrect = readPersnr(persnr);
            if (nrIsCorrect)
            {
                //prints computed personnummer with control digit
                printf("Personnumer with control digit is: \n");
                printf("%s", persnr);
                printf("%d\n", controlDigit(persnr));
            }
            else
            {
                printf("Please try again\n");
            }
        }
    }
    printf("Quitting..\n");
}
//karan said the return type is ok as long as it works
//checks the basic format of the personnummer
//also checks if the months and days are out of bounds, taking into account months
bool readPersnr(char *person)
{
    bool numberIsCorrect = true;

    char monthStr[3];
    char dayStr[3];

    int day;
    int month;
    int i;
    printf("%s\n", person);

    for (i = 0; i < strlen(person); i++)
    {
        if (!(person[i] >= '0' && person[i] <= '9'))
        {
            numberIsCorrect = false;
            break;
        }
    }
    if (!numberIsCorrect)
    {
        printf("Number format is incorrect");
        return numberIsCorrect;
    }

    for (i = 2; i < 4; i++)
    {
        monthStr[i - 2] = person[i];
    }

    month = atoi(monthStr);

    for (i = 4; i < 6; i++)
    {
        dayStr[i - 4] = person[i];
    }

    day = atoi(dayStr);

    if (day < 1)
    {
        printf("day is negative, just like mine\n");
    }
    if (month < 1 || month > 12)
    {
        printf("month out of range\n");
        numberIsCorrect = false;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31)
        {
            printf("day out of range\n");
            numberIsCorrect = false;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            printf("day out of range\n");
            numberIsCorrect = false;
        }
    }
    else
    {
        if (day > 29)
        {
            printf("day out of range\n");
            numberIsCorrect = false;
        }
    }
    return numberIsCorrect;
}

//algorithm for calculating control digit
int controlDigit(const char *persnr)
{
    int sum = 0;
    int digits = strlen(persnr);
    int parity = (digits - 1) % 2;
    char cDigit[2] = "\0";
    for (int i = digits; i > 0; i--)
    {
        cDigit[0] = persnr[i - 1];
        int nDigit = atoi(cDigit);
 m nbvc     
        if (parity == i % 2)
            nDigit = nDigit * 2;

        sum += nDigit / 10;
        sum += nDigit % 10;
    }

    return sum % 10;
}