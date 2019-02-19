/* ====================================
File name: exerc4_2.c
Date: 2019-02-12
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Demonstration code: [gib me code]

//Solution has been done in collaboration with group 13 (Araz and Matt)
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//initiate the methods
unsigned int hexadecimalToInteger(const char *p);
int decode(int number);

int str_len(char *pointer)
{
    int i;
    for (i = 0; pointer[i] != '\0'; i++)
    {
    }
    return i;
}
int main(int argc, char *argv[])
{
    //check if the arguments are exactly 1
    if (argc == 2)
    {
        const char *value = argv[1];
        int len = str_len(argv[1]);

        if (len > 2)
        {
            printf("There are more arguments than 1!\n");
            return 1;
        }
        int n = hexadecimalToInteger(value);

        // decode
        decode(n);
        return 0;
    }

    else
    {
        printf("Check the arguments and input the right amount\n");
        exit(1);
    }
}

unsigned int hexadecimalToInteger(const char *p)
{
    unsigned int val = 0;

    char c = *p;
    // skip spaces and tabs
    while (c == ' ' || c == '\t')
    {
        c = *(++p);
    }

    // run until done
    while (1)
    {
        // if number char
        // shift 4 bits, because each number is represented by 4 bits
        if (c >= '0' && c <= '9')
        {
            val = (val << 4) + (c - '0');
        }
        else if (c >= 'A' && c <= 'F')
        {
            val = (val << 4) + (c - 'A' + 10);
        }
        else if (c >= 'a' && c <= 'f')
        {
            val = (val << 4) + (c - 'a' + 10);
        }
        else
        {
            return val;
        }
        c = *(++p);
    }
}

/*decoding through assigning each 
of the values (found through bitwise 
operation) and then shifting*/
int decode(int n)
{
    unsigned bitMask;
    // 1 bit for engine
    bitMask = (1 << 1) - 1;
    int engine = n & bitMask;

    // 3 bits for gear 
    bitMask = (1 << 3) - 1;
    int gear = (n >> 2) & bitMask;

    //2 bits for key
    bitMask = (1 << 2) - 1;
    int key = (n >> 4) & bitMask;

    // 1 bit for brake 1
    bitMask = (1 << 1) - 1;
    int brake1 = (n >> 5) & bitMask;

    // 1 bit for brake 2
    bitMask = (1 << 1) - 1;
    int brake2 = (n >> 7) & bitMask;

    //statements to check if every term has the correct range
    if (engine > 1 || engine < 0)
    {
        printf("Engine value is out of range\n");
        return 1;
    }
    else if (gear > 4 || gear < 0)
    {
        printf("Gear value is out of range\n");
        return 1;
    }
    else if (key > 2 || key < 0)
    {
        printf("Key value is out of range\n");
        return 1;
    }
    else if (brake1 > 1 || brake1 < 0)
    {
        printf("Break1 value is out of range\n");
        return 1;
    }
    else if (brake2 > 1 || brake2 < 0)
    {
        printf("Break2 value is out of range\n");
        return 1;
    }
    else
    {
        printf("Engine: %d\n", engine);
        printf("Gear: %d\n", gear);
        printf("Key: %d\n", key);
        printf("Brake1: %d\n", brake1);
        printf("Brake2: %d\n", brake2);
    }
    return 0;
}

