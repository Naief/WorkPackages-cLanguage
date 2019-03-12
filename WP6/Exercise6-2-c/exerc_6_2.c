/* ====================================
File name: exerc_6_2.c
Date: 2019-03-11
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Demonstration code: [7118]
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define num_elems 200
int array[200];
int max_value;

void *runner(void *param);
void *sortArray(void *param);
void *search(void *param);

int main()
{
    time_t t;
    pthread_t tid, sort, find;
    pthread_attr_t attr, attr2, attr3;

    srand((unsigned)time(&t));
    pthread_attr_init(&attr);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);

    printf("Enter max value\n");
    scanf("%d", &max_value);

    pthread_create(&tid, &attr, runner, NULL); //create a new thread with tid as an id and attr as an attribute and starts at method runner.
    printf("Array is filled with numbers \n");
    pthread_join(tid, NULL);
    printf("SORTING ... \n");
    pthread_create(&sort, &attr3, sortArray, NULL);
    pthread_join(sort, NULL);
    printf("SE4ARCHING ... \n");
    pthread_create(&find, &attr2, search, NULL);
    pthread_join(find, NULL);
}

void *sortArray(void *param)
{
    int c, d, swap;

    //Sort the random array
    for (c = 0; c < num_elems; c++)
    {
        for (d = 0; d < num_elems - c - 1; d++)
        {
            if (array[d] > array[d + 1])
            {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    pthread_exit(0);
}

void *search(void *param)
{
    //Search for a value to find
    int search;
    printf("Enter value to find\n");
    scanf("%d", &search);

    int first = 0;
    int last = num_elems - 1;
    int middle = (first + last) / 2;
    int n;
    for (n = 0; n < num_elems; n++)
    {
        printf("\n %d \n", array[n]);
    }
    while (first <= last)
    {
        if (array[middle] < search)
            first = middle + 1;

        else if (array[middle] == search)
        {
            printf("%d \n found at location %d.\n", search, middle + 1);
            break;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first > last)
        printf("Not found! %d is not present in the list.\n", search);
    pthread_exit(0);
}

void *runner(void *param)
{
    int c = 0, n = 0;
    for (c = 0; c < num_elems; c++)
    {
        for (n = 0; n < 1000; n++)
            ; // To delay a bit
        array[c] = rand() % max_value;
    }
    pthread_exit(0);
}
