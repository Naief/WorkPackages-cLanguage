/* ====================================
File name: exerc_4_1.c
Date: 2019-02-19
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Demonstration code: [25964]
====================================== */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char **argv) {
    if(argc != 6)
    {
        printf("Incorrect number of args\n");
    }

    else
    {
        unsigned char solution = 0;
        char engine_on = *argv[1];
        char gear_pos = *argv[2];
        char key_pos = *argv[3];
        char brake1 = *argv[4];
        char brake2 = *argv[5];

        if(engine_on != '1' && engine_on != '0')
        {
            printf("Incorrect value: engine_on\n");
            return(0);
        }
        else if(gear_pos < '0' || gear_pos > '4')
        {
            printf("Incorrect value: gear_pos\n");
            return(0);
        }
        else if(key_pos < '0' || key_pos > '2')
        {
            printf("Incorrect value: key_pos\n");
            return(0);
        }
        else if(brake1 != '1' && brake1!= '0')
        {
            printf("Incorrect value: brake1\n");
            return(0);
        }
        else if(brake2 != '1' && brake2 != '0')
        {
            printf("Incorrect value: brake2\n");
            return(0);
        }

        solution += engine_on - '0';

        solution = solution<<3;
        solution += gear_pos - '0';

        solution = solution<<2;
        solution += key_pos - '0';

        solution = solution<<1;
        solution += brake1 - '0';

        solution = solution<<1;
        solution += brake2 - '0';
        printf("Solution: %x\n", solution);
    }
}