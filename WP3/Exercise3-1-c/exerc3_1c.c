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
Demonstration code: [29127]
====================================== */
#include <stdio.h>
#include <stdlib.h>

enum DIRECTION
{
    N,
    O,
    S,
    W
};
typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void turn(ROBOT *robot)
{
    if (robot->dir == W)
    {
        robot->dir = 0;
        robot->dir = N;
    }
    else
    {
        robot->dir++;
    }
}

void move(ROBOT *robot)
{
    switch (robot->dir)
    {
    // The cases involving y position
    case 0:
        if (robot->ypos != 99)
        {
            robot->ypos++;
        }
        break;
    case 2:
        if (robot->ypos != 0)
        {
            robot->ypos--;
        }
        break;
        // The cases involving x position
    case 1:
        if (robot->xpos != 0)
        {
            robot->xpos--;
        }
        break;
    case 3:
        if (robot->xpos != 99)
        {
            robot->xpos++;
        };
        break;

    default:
        break;
    }
}

int beginngnResponseToLocation(char *response)
{ // This is mainly so we can use the same code for xAxis and yAxis

    int number = atoi(response);
    if (number > 99 || 0 > number)
    {
        return -1;
    }
    else
    {
        return number;
    }
}
char getDirChar(ROBOT *robot)
{
    switch (robot->dir)
    {
    case 0:
        return 'N';
    case 1:
        return 'O';
    case 2:
        return 'S';
    case 3:
        return 'W';
    }
}

int main(int argc, char **argv)
{

    while (1 == 1)
    {
        char response[10] = "";

        int yLoc = 0;
        printf("\nHello please enter the starting Y position of the robot. It has to be between 0 and 99.\n");
        fgets(response, 10, stdin);
        int locationInt = beginngnResponseToLocation(response);
        if (locationInt != -1)
        {
            yLoc = locationInt;
        }

        int xLoc = 0; // The int used to store the location of the robot
        printf("Now do the same for the x axis\n");
        fgets(response, 10, stdin);
        locationInt = beginngnResponseToLocation(response);
        if (locationInt != -1)
        {
            xLoc = locationInt;
        }

        ROBOT *robotPointer; // The pointer which points to the robot

        ROBOT robotEntity = {xLoc, yLoc, N};
        robotPointer = &robotEntity;

        char instructions[100] = "";
        printf("Hello please enter m to turn your robot and t to turn it 90 degrees. It will only read a maximum of 100 characters.");
        fgets(instructions, 100, stdin);
        char dir = getDirChar(robotPointer);
        for (int i = 0; i < 100 || instructions[i] == '\0'; i++)
        {
            //printf("%c\n", instructions[i]); Testing purposes
            switch (instructions[i])
            {
            case 't':
                turn(robotPointer);
                dir = getDirChar(robotPointer);
                /*printf("The current direction of the robot: %c. the current location of the robot is X: %d  Y: %d \n",
                           dir, robotEntity.xpos, robotEntity.ypos);*/
                // TEsting
                break;

            case 'm':
                move(robotPointer);
                /*printf("The current direction of the robot: %c. the current location of the robot is X: %d  Y: %d \n",
                           dir, robotEntity.xpos, robotEntity.ypos); */
                // TEsting
                break;
            default:
                break;
            }
        }
        printf("The current direction of the robot: %c. the current location of the robot is X: %d  Y: %d \n",
               dir, robotEntity.xpos, robotEntity.ypos);

        printf("If you want to exit the program then enter q as the first character that you write in\n");
        char quit[3] = "";
        fgets(quit, 3, stdin);
        if (quit[0] == 'q')
        {
            break;
        }
        printf("%c\n", quit[0]);
    }
}