/* ====================================
File name: exerc_3_2.c
Date: 2019-02-12
Group nr 04
Members that contribute to the solutions
David Lindgren
Filip Fatic
Naief Jobsen
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [29110]
====================================== */

#include <stdio.h>

int search_number(int number, int tab[], int size);
void sort(int number, int tab[]);

void main(int argc, char **argv)
{

    int searchNum = 13; // The number which you are searching for.

    int test[] = {9, 2, 34, 5, 67, 3, 23, 12, 13, 10}; // The creation of the int array
    int index = search_number(searchNum, test, 10);    // Gets the index of the search number

    printf("The index %d\n", index);
    printf("the value %d\n", test[index]);

    sort(10, test); // Sorts with the smallest number at the beginning.
    index = search_number(searchNum, test, 10);
    printf("The index %d\n", index);
    printf("the value %d\n", test[index]);

    printf("The sorted array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", test[i]);
    }
    printf("\n");
}

int search_number(int number, int tab[], int size)
{ // Takes in a number to search for, an array and the size of the array
    for (int i = 0; i < size || tab[i] == '\0'; i++)
    {
        if (tab[i] == number)
        {             // If a number in the array is the same as the number parameter
            return i; // then its index in the array is returned
        }
    }
    return -1; // If no such number is found then -1 is returned
}

void sort(int number, int *tab)
{ // Number is the size of the array and tab is the actual array
    for (int i = 0; i < number; i++)
    {
        int smallestInt = tab[i]; // Stores the current number in the array as the smallest number in this run.
        for (int x = i; x < number; x++)
        {
            if (tab[x] < smallestInt)
            { // Checks if the number is larger than the smallest number and if so they switch places in the array
                int temp = tab[i];
                tab[i] = tab[x];
                tab[x] = temp;
                smallestInt = tab[i]; // The one which was smaller becomes the new smallest int.
            }
        }
    }
};