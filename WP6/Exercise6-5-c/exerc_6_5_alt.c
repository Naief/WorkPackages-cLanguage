/* ====================================
File name: exerc6_5_alt.c
Date: 2019-03-11
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Demonstration code: <code here>
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;

//Global / Shared variables
#define MAX 10
char letter = 'a'; //the starting letter
unsigned short count = 0;
char buffer[MAX]; // circular buffer . Test for MAX 5 and 10.
int write_pos;    // index for next character to be put in buffer (put)
int read_pos;     // index for next character to be read(fetch)
int countNF;      // the number of characters in buffer not fetched

void *put();
void *fetch();
unsigned int rand_interval();
/*  pthread_mutex_init();
pthread_mutex_lock();
phtread_mutex_unlock();
pthread_cond_signal();
pthread_cond_wait.  */

int main()
{
    write_pos = 0;
    read_pos = 0;
    int i = 0;

    pthread_t producer, consumer;
    pthread_create(&producer, NULL, put, NULL);
    pthread_create(&consumer, NULL, fetch, NULL);

    while (1)
    {
        printf("\n main is executing"); // When the program has just started this printf will be printed more than the other ones but after a while that stops.
    }
}
void *put()
{
    pthread_mutex_lock(&count_mutex);

    // This int represents lowercase a
    int minChar = 97;
    // This int represents lowercase z
    int maxChar = 122;

    int currentChar = minChar;

    printf("Start");
    while (1)
    {
        if (currentChar == maxChar)
        {
            currentChar = minChar;
        }
        // This add the current letter into the buffer and increments it.
        buffer[write_pos] = (currentChar++);
        //printf(" Here is the added char in position %i : %c\n", write_pos, buffer[write_pos]); //This exists so that you can verify if the consumer is seeing the correct char.
        printf("\nBuffer store"); // If this is not here then the consumer will not print anything.
        write_pos++;
        // Here the producer signals the consumer saying that the buffer is not empty and that there is something to retrieve from it.
        pthread_cond_signal(&not_empty);
        // When the producer reaches the end of the array it waits untill the consumer does the same and then it starts addign new chars to the beginning of the array.
        if (write_pos == MAX)
        {
            pthread_cond_wait(&not_full, &count_mutex);
            write_pos = 0;
        }
    }
}

void *fetch()
{
    // This wait is here to
    pthread_cond_wait(&not_empty, &count_mutex);
    while (1)
    {
        // This checks if the consumer has caught up with the producer and if so then it waits until the producer has added a new
        if (read_pos == write_pos)
        {
            // Here it waits until producer says that a new char has been added to the buffer.
            pthread_cond_wait(&not_empty, &count_mutex);
        }
        // Here it prints the current value and increments itself.
        printf("\nBuffer Output : %c ", buffer[read_pos]);
        read_pos++;
        // If it reaches the last char in the buffer then it will signal the producer and then wait until it has produced a new char and then continue with its consuming.
        if (read_pos == MAX)
        {
            pthread_cond_signal(&not_full);
            pthread_cond_wait(&not_empty, &count_mutex);
            read_pos = 0;
        }
    }
}