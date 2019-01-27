/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
File name: exerc_1_3.c
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

int main()
{
/*Variable declarations*/
const int buffsize = 100;
char message[buffsize];
char character;
int i;
int key = 13;

printf("Please enter a message to be encrypted: \n");
fgets(message, buffsize, stdin);

    //Loop inside the inputted array and assign character to the respective item 'i'.
    //This is for the small letters.

    for(i = 0; message[i] != '\0'; i++)
    {
    character = message[i];

    //Check if the letters are correct.
    //If so, use the key to perform the
    //encryption through counting 13 times.
    if (character >= 'a' && character <= 'z')
    {
        character = character + key;

        if (character > 'z')
        {
            character = character - 'z' + 'a' - 1;
        }
        message[i] = character;
    }

    //Perform the same operation as above for the capital letters.
    else if (character >= 'A' && character <= 'Z')
    {
        character = character + key;

        if (character > 'Z')
        {
            character = character - 'Z' + 'A' - 1;
        }
        message[i] = character;
    }
}
    printf("Encrypted message is: %s", message);
    return 0;
}
