

#include <stdio.h>
/* 
logic: if the sentence has one space 
between every two words and if there 
are n spaces in the sentence, then there
are n+1 words. Very nice makes sense.
*/
//===========================================
/*
Edge case: If the words have more than one 
space between them lmao. Solution: count the 
words and not spaces lol. 
*/

int main()
{

    /*variables declarations*/
    const int bufsize = 4000;
    char string[bufsize];
    /* w is the words*/
    int count = 0;
    int i = 0;

    printf("This program will count the amount of words of a sentence you provide! \n");

    /*handle Input*/
    printf("Please enter the sentence:\n ");
    fgets(string, bufsize, stdin); //fgets() is a function that reads a the input and stores it into the argument chosen

    /*start the words counting*/
    // if not null proceed
    for (i = 0; string[i] != '\0'; i++)
    {
        //if there is no whitespace(either single or a tab size)
        //meaning that a word is encountered, proceed to the next word.
        if (string[i] != ' ' && string[i] != '\t')
        {
            count++;
            //As long there is no white spaces, go to the next word.
            while (string[i] != ' ' && string[i] != '\t')
                i++;
        }
    }

    /*Output*/
    printf("The maximum number of words in your sentnce is: %d\n", count);
    return 0;
}
