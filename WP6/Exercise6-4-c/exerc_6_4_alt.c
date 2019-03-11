/* ====================================
File name: exerc6_4_alt.c
Date: 2019-03-09
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Demonstration code: <code here>
====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <pthread.h>
double get_time_ms();
void *time_count();
void *read_inport();

int program_time = 0; //global time variable
int main()
{
    //start up thre thread time_count
    //start up the thread read_inport
    pthread_t time_counter, inport_reader;
    printf("Thread 1 created\n");
    pthread_create(&time_counter, NULL, time_count, NULL);
    printf("Thread 2 created\n");
    pthread_create(&inport_reader, NULL, read_inport, NULL);
    printf("Thread 1 joined\n");
    pthread_join(time_counter, NULL);
    //printf("Thread 2 joined\n");
    //pthread_join(inport_reader, NULL);
}
//--end of main thread--

//--thread functions--
void *time_count()
{
    printf("Time count thread started\n");
    double t, target;
    while(program_time<10)
    {
        printf("Program time: %d\n", program_time);
        //check system time(get_time_ms())
        t = get_time_ms();
        target = t + 1000.0;
        while(t < target)
        {
            t = get_time_ms();
        }
        //increase program_time by one every second
        program_time++;
    }
    //exit thread
}

void *read_inport()
{
    bool has_read_port = false;
    while(program_time<10)
    {
        //read inport every 5 sec
        if(program_time % 5 == 0)
        {
            if(!has_read_port)
            {
                //simulate by printing out "Reading Inport now"
                printf("Reading Inport now\n");
                has_read_port = true;
            }
        }
        else
        {
            has_read_port = false;
        }
    }
    //exit thread
}

//--- function to get time--
double get_time_ms()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return(t.tv_sec + (t.tv_usec / 1000000.0))* 1000.0;
}//--end--