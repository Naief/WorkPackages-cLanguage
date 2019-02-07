/* ====================================
File name: exerc_2_6.c
Date: 2019-02-07
Group nr 04
Members that contribute to the solutions
David Lindgren
Filip Fatic
Naief Jobsen
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [7527]
====================================== */
#include <stdio.h>
#include "time.h"
#include <stdlib.h>
#define MAX 5
#define empty -1 // Defines what a empty spot in the queue should look like

int input(int list[],int number, int max){ // Adds a new number to the queue if there is room otherwise returns 0 and does nothing to it.

        for (int i = 0; i < max ; ++i) {// Checks where the first empty spot is and inputs the new number there
            if(list[i]== empty){
                list[i] = number;
                return 1; // if it can add the number then it returns 1
            }
        }
        return 0; // Returns 0 in case there is no empty spot in the queue

}

void initque(int list[], int max){ // Initializes the queue.

    for(int i = 0; i<max; i++){ // This is the loop which adds the -1s to the array
        list[i] = empty;
        //printf("%d", list[i]); //Testing code. Sees if it is properly initialized
    }


}

int output(int list[], int max){
    int returnvalue = 0; // The value which will be returned.

    for(int i = 0; i<max;i++ ){// The loop which checks each value in the list if it is empty or not
        if(list[i] != empty){
            returnvalue = returnvalue +list[i];//The value of a non-empty queue entry is added to the returnvalue

            //removes the one to be outputed and puts all the other numbers one step closer to the first entry.
            for(int x = 0; x<max-1; x++){
                list[x] = list[x+1];
                //printf("%d ", list[x]); //Testing purposes
            }
            list[max] = empty;
            //printf("%d ", list[max]);//Testing purposes

            return returnvalue;
        }
    }
    return returnvalue;

}


int main(int argc, char **argv){

    int que[MAX+1];
    initque(que, MAX);
    input(que,3,MAX);
    input(que,5,MAX);
    input(que,4,MAX);
    printf("\n %d \n",output(que,MAX));
    input(que,5,MAX);

    for (int i = 0; i < MAX; ++i) {
        printf("%d ", que[i]);
    }


}