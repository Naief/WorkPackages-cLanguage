/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
File name: exerc_2_2.c
Date: 29 Jan, 2019
Group number: 4
Memebers that contributed to the solution:
- Naief Jobsen
- Filip Fatic
- David Lindgren

*/

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>   // time()
#define MAX 20

int array[MAX];
int i;
int count;
int *pointer;

int main()
{
    srand(time(0)); //Based on a value it starts generating random ones

    for (i = 0; i < MAX; i++)
    {
        array[i] = rand() % (99 + 1);
    }

    printf("The value of the label array is: %pn \n ", &array);
    printf("First integer in the array is: %d \n ", array[0]);
    printf("The size of an integer (number of bytes) is: %lu \n", sizeof(array[1])); //WE CHOOSE THE SECOND POSITION
    printf("The size of the whole array elements is: %d \n", MAX); //Size in terms of the amount of the elements
    printf("The sizeof the whole array is: %lu \n", sizeof(array)); //Size in terms of the amount of bites

    pointer = array;
    for (i = 0; i < MAX; i++)
    {
        printf("Current position: %d. \n", i);
        printf("The integer value: %d and its double value: %d \n", *pointer, *pointer * 2);
        pointer++;
    }
    return 0;
}
