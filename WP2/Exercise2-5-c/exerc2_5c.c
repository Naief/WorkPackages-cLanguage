/* ====================================
File name: exerc_2_5.c
Date: 2019-02-07
Group nr 04
Members that contribute to the solutions
David Lindgren
Filip Fatic
Naief Jobsen
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [<Ass code 1-4> <abc>]
====================================== */

include <stdio.h>
#include "time.h"
#include <stdlib.h>

// The definitions of maximums and the three methods
#define MAX 20
#define MAXNUMBER 15

void create_random(int *tab);
void count_frequency(int *tab, int *counter);
void draw_histogram(int *counter);

// The main methods which creates the arrays and calls the three methods.
int main(int argc, char **argv)
{
    int freq[MAXNUMBER + 1];
    int table[MAX], n;

    create_random(table);         // Populates the table with random numbers
    count_frequency(table, freq); // Counts the frequency of the numbers and saves the resuts in the freq array
    draw_histogram(freq);         // Prints the histogram showing the frequency of the numbers
}

void create_random(int *tab)
{
    time_t t;
    srand((unsigned)time(&t)); // Initalizes the random so that it will actually be random
    for (int i = 0; i < MAX; i++)
    { // Creates a random number for each entry in the table
        *(tab + i) = rand() % (MAXNUMBER + 1);
    }
};

void count_frequency(int *tab, int *freq)
{

    for (int i = 0; i < MAXNUMBER + 1; i++)
    { // Initializes the frequency array. Prevents errors.
        freq[i] = 0;
    }

    for (int i = 0; i < MAX; i++)
    { // This is the loop which actually counts the numbers.
        freq[tab[i]]++;
    }
}

void draw_histogram(int *freq)
{ // The part that prints Xes for each occurance of a number
    //int count = 0;// Testing purposes
    for (int i = 0; i < MAXNUMBER + 1; i++)
    {
        if (freq[i] > 0)
        { // If the frequencecy is higher than zero then the number and its frequency is printed.
            printf("\n%i", i);
            for (int x = 0; x < freq[i]; x++)
            { // Prints a X for each occurance of the number
                //count++; // Testing purposes
                printf("x");
            }
        }
    }
    //printf("\ncount: %d", count);// Testing purposes
}