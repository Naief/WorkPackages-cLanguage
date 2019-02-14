/* ====================================
File name: exerc_3_1.c
Date: 2019-02-12
Group nr 04
Members that contribute to the solutions
David Lindgren
Filip Fatic
Naief Jobsen
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [28939]
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Konstanter ######
#define MAX 5

// ##### Typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

//create multiple struct and put them in a linked list

// ##### Funcion declarations  #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);

//###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *akt_post, *head = NULL;
    srand(time(0)); //Random seed
    head = random_list();
    akt_post = head;
    while (akt_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, akt_post->number);
        akt_post = akt_post->next;
    }
    nr = 0;
    akt_post = add_first(head, 3);
    while (akt_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, akt_post->number);
        akt_post = akt_post->next;
    }

    while ((akt_post = head) != NULL)
    {
        head = akt_post->next;
        free(akt_post);
    }
    //------------------
    return 0;
}
// ====  End of main  ======================================

REGTYPE *random_list(void)
{
    int nr, i = 0;
    REGTYPE *top, *old, *item;
    top = (REGTYPE *)malloc(sizeof(REGTYPE));
    nr = rand() % 100;
    top->number = nr;
    top->prev = NULL;
    top->next = NULL;
    item = top;
    i++;
    while (i < MAX)
    {
        old = item;
        item = (REGTYPE *)malloc(sizeof(REGTYPE));
        nr = rand() % 100;
        item->number = nr;
        item->prev = old;
        item->next = NULL;
        old->next = item;
        i++;
    }
    return (top);
}

//==========================================================

REGTYPE *add_first(REGTYPE *temp, int data)
{
    //listHead' is now a pointer to a linked list (with no nodes).
    //Here is a new node added at the head of the the list:
    REGTYPE *structList = malloc(sizeof(REGTYPE));
    temp->prev = structList;
    structList->number = data;
    structList->next = temp;

    return structList;
}

//test out this shit
void printList(REGTYPE *head)
{
    REGTYPE *current = head;
    while (current != NULL)
    {
        printf("%d \n", current->number);
        current = current->next;
    }
}
