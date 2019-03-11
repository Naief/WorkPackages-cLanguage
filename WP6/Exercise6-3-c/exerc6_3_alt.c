/* ====================================
File name: exerc6_3_alt.c
Date: 2019-03-08
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
#define REG8(x) *((unsigned char *)(x))
#define WRITE 0xB00 // IN-port
#define READ 0xB01  // OUT-port
#define TIME 5

bool is_Sensor_Tripped(unsigned char input);
bool is_Door_Open(unsigned char input);
void main()
{
    int i;

    //closes door
    REG8(WRITE) = 1;
    //loop
    while (1)
    {
        // // if sensor tripped, open door
        if (is_Sensor_Tripped(REG8(READ)))
        {
            REG8(WRITE) = 2;
            // // do nothing until door is opened
            while (!is_Door_Open(REG8(READ)))
            {
            }
            // // delay(TIME)
            for (i = 0; i < TIME; i++)
            {
                // // if sensor is tripped, restart delay
                if (is_Sensor_Tripped(REG8(READ)))
                {
                    i = 0;
                }
            }
            // // start closing door
            REG8(WRITE) = 1;
        }
    }
}

//values for these methods are taken from XCCs help page
bool is_Sensor_Tripped(unsigned char input)
{
    //makes sure only values on bits at position 0 and 1 are checked
    input = input & 3;
    //Checks if any or both of the sensors are tripped
    if (input >= 1 || input < 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_Door_Open(unsigned char input)
{
    //checks only value on bit at position 3
    input = input & 8;

    //checks if door is open
    if (input == 8)
    {
        return true;
    }
    else
    {
        return false;
    }
}