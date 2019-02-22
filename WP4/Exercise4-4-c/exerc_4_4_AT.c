/* ====================================
File name: exerc4_4.c
Date: 2019-02-21
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Demonstration code: [26054]
====================================== */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void f_delay(int);
unsigned char random_inport(void);
void printport(int);

int main()
{
    int nr;
    unsigned char randomPort;
    srand(time(0));
    for (nr = 0; nr < 10; nr++)
    {
        randomPort = random_inport();

        printport(randomPort);

        if (randomPort >> 7 == 0)
        {
            unsigned char result = randomPort & 15;
            printf(" --------------------------------Result =  %X \n", result);
            f_delay(10);
        }
    }
    return (0);
}

void f_delay(int tenth_sec)
{

    clock_t start_t, end_t;
    long int i;
    start_t = clock();
    do
    {
        for (i = 0; i < 10000000; i++)
            ;
        end_t = clock();
    } while ((end_t - start_t) < (tenth_sec * CLOCKS_PER_SEC) / 10);
    return;
}

unsigned char random_inport(void)
{
    unsigned char inport = 0;
    inport = rand() % 256;
    return (inport);
}

void printport(int portvalue)
{
    int binchar[8], rest, j, i = 0;
    rest = portvalue;
    while (rest != 0)
    {
        binchar[i++] = rest % 2;
        rest = rest / 2;
    }
    // Fill to 8 bits
    while (i < 8)
    {
        binchar[i++] = 0;
    }
    // Print bits and at the end corresponding decimal value
    for (j = i - 1; j > -1; j--)
        printf("  %d", binchar[j]);
    printf(" --------Port decimal value = %d  \n", portvalue);
    return;
}

/*
//Another solution. 
 if ( port >> 7 == 0){
            unsigned char hexPrint = 0;
            hexPrint = port;
            for (int i = 7; i > 3; --i) {
                 hexPrint &= ~(1UL << i);
            }
            printf("%X \n", hexPrint);
        }
 */