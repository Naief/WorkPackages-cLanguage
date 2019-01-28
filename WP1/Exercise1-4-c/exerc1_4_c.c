/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
File name: exerc_1_4.c
Date: 27 Jan, 2019
Group number: 4
Memebers that contributed to the solution:
- Naief Jobsen
- Filip Fatic
- David Lindgren
Memebers not present at demo time:
none.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void)
{

    int random_num = 0;
    int guessed_num = 0;
    int counter = 0;
    int i = 0;

    srand(time(NULL));
    random_num = rand() % 100 + 1;

    printf("This is the guessing game. You have 10 tried to guess a number between 1 to 100. Good luck! \n");
    printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
    printf("Guess the number: ");

    while (counter < 10)
    {
        counter++;
        scanf("%d", &guessed_num);

        if (guessed_num == random_num)
        {
            printf("You guessed correctly in %d out of 10 tries! Good job!\n", counter);
            break;
        }

        if (guessed_num < random_num)
            printf("Your guess is too low. Guess again. ");

        if (guessed_num > random_num)
            printf("Your guess is too high. Guess again. ");
    }
    return 0;
}

/*
How can I fix the error with the letters? 
*/