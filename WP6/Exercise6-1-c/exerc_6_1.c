/* ====================================
File name: exerc_6_1.c
Date: 2019-03-09
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Demonstration code: [7116]
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define num_elems 200
int array[200];
int max_value;

void *runner(void *param);

int main(){
    time_t t; 
    pthread_t tid;
    pthread_attr_t attr;

    srand((unsigned)time(&t));
    pthread_attr_init(&attr);

    printf("Enter max value\n");
    scanf("%d", &max_value);

    pthread_create(&tid, &attr, runner, NULL); //create a new thread with tid as an id and attr as an attribute and starts at method runner. 
    pthread_join(tid, NULL);

    int c, d, swap;

    //Sort the random array 
    for (c = 0; c < num_elems; c++){
        for (d = 0; d < num_elems - c - 1; d++){
            if (array[d] > array[d + 1]){
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
   
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
        printf("\n %d", array[n]);
    }
    while (first <= last)
    {
        if (array[middle] < search)
            first = middle + 1;

        else if (array[middle] == search)
        {
            printf("%d found at location %d.\n", search, middle + 1);
            break;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first > last)
        printf("Not found! %d is not present in the list.\n", search);
    return 0;
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


/********** Answers ****************
--> 1) 
2 Threads exist. main() AND pthread_create(&tid, &attr, runner, NULL)

--> 2) 
Line 16: The time_t datatype is a data type for storing system time values.
Line 17: pthread_t is a data type used to uniquely identify a thread. It works as the ID.
Line 18: pthread_attr_t allows changing attributes on the thread.
Line 20: pthread_attr_init(&attr) allows initilizing a thread attribute object. 
In this case, not a default attribute value, instead, it is attr. 
Line 25: pthread_create(&tid, &attr, runner, NULL) creates a new thread with an id (tid) and attribute attr. It specifies that the 
method runner is going to be run in this method. 
Line 26: pthread_join(tid, NULL) ensures that the calling thread waits on the termination of target thread. 

--> 3)
0 parameter. It however can take any parameter of any datatype or null 

--> 4)
Function runner will know because the global variable max_value is 
assigned to the array[c]. Therefore, all the values will be saved in the array. 

--> 5)
The 'main' thread does not wait for the 'tid' thread to finish. Therefore, main will 
be spitting numbers meanwhile the runner thread is sorting some of them. The behaviour 
is thus asyncronous.   
************************************************/