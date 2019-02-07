/*
Nim Game
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_COINS 13
const int HUMAN = 0;
const int COMPUTER = 1;
const int buffsize = 100;
char input[buffsize];
int result = 0;

int main()
{
    int pile, /* This is how many coins we have */ 
    player, /* Who is playing? */ 
    n_coins; /* Number of coins taken */
    srand(time(0));/* Setup random */
    printf("Välkommen till NIM by ...");
    pile = MAX_COINS; /* Set start values (= init) */
    player = HUMAN;   /**  Program main loop*/
    while (true)
    {
        printf("Det ligger %d  mynt i högen\n", pile);
        if (player == HUMAN)
        {
            n_coins = human_choice(pile);
        }
        else
        {
            n_coins = computer_choice(pile);
            printf("- Jag tog %d\n", n_coins);
        }
        pile -= n_coins;
        player = toggle(player);
        if (pile <= 1)
        {
            break;
        }
    } /**  end main loop*/
    write_winner(player);
    printf("Avslutat\n");
    return 0;
} 

/********************************************************  DEFINITIONS*******************************************************/
   
    void clear_stdin()
    {
        while (getchar() != '\n')
        {
            ;
        }
    }
    
    int human_choice(int pile) {
        while(input){
            fgets(input, buffsize, stdin);
            if (input >= 1 && input <=3 && input < pile){
                input = result;
            }
        }
        return result;
    }

    int computer_choice(int pile) {
    }

    void write_winner(int player)
    {
        if (HUMAN)
        {
            fprintf(stdout, "The winner is: Human! \n");
        }
        if (COMPUTER)
        {
            fprintf(stdout, "The winner is: Computer! \n");
        }
    }
    int play_again()
    {
    }
    int toggle(int player) {
        
    }