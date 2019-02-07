/* ====================================
File name: exerc2_8.c
Date: 2019-02-07
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Member not present at demonstration time:
Yyyyyy yyyy
Demonstration code: [<Ass code 1-4> <abc>]
====================================== */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

int game();
/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in:
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
    int playAgain = 1;

    srand( time(0) );		/* Setup random */

    printf("V‰lkommen till NIM by ...");

    /*
     *  Program main loop
     */
    do
    {
        write_winner( game() );
        playAgain = play_again();
    }
    while (playAgain==1);
    /*
     * end main loop
     */


    printf("Avslutat\n");

    return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 *
 ******************************************************/

int game()
{

    int pile,			/* This is how many coins we have */
        player,			/* Who is playing? */
        n_coins;			/* Number of coins taken */

    pile = MAX_COINS;		/* Set start values (= init) */
    player = HUMAN;
    while(true)
    {
        printf("Det ligger %d  mynt i hˆgen\n", pile );

        if( player == HUMAN )
        {
            n_coins = human_choice(pile);
        }
        else
        {
            n_coins = computer_choice(pile);
            printf("- Jag tog %d\n", n_coins);
        }
        pile -= n_coins;
        player = toggle( player );

        if( pile < 1 )
        {
            break;
        }
    }
    return player;

}

//clears input buffer
void clear_stdin()
{
    while( getchar() != '\n' )
    {
        ;
    }
}

//function that takes user input and returns it to main game loop

int human_choice(int pile)
{
    bool valid = false;
    int choice;
    while(!valid)
    {
        scanf("%d", &choice);
        if(choice > 3)
        {
            printf("You can choose a max of 3 coins\n");
        }
        else if(choice < 1)
        {
            printf("You must choose at least one coin\n");
        }
        else if(choice > pile)
        {
            printf("Choice cannot be bigger than the pile. \n");
        }
        else
        {
            printf("You took %d coins\n", choice);
            valid = true;
        }
    }
    return choice;
}

//algorithm that makes the choice for the computer.
//choice is random between 1-3 unless the pile has less than 4 coins
//in that case, the computer will try and win
int computer_choice(int pile)
{
    if(pile < 4)
    {
        if(pile == 3)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return rand() % (3 + 1 - 1) + 1;
    }

}

//prints out who is the winner based on whose turn is it
void write_winner(int player )
{
    if(player == HUMAN)
    {
        printf("You win!\n");
    }
    else
    {
        printf("You lose!\n");
    }
}

//asks user if they want to play again and asks for input
//any input except q will restart the game
int play_again()
{
    char answer;
    clear_stdin();
    printf("Would you like to play again? Press q to quit\n");
    scanf("%c", &answer);
    if(answer == 'q' || answer == 'Q')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//switches current player
int toggle( int player )
{
    if(player == HUMAN)
    {
        return COMPUTER;
    }
    if(player == COMPUTER)
    {
        return HUMAN;
    }
}
