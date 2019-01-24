


#include <stdio.h>

int main()
{
    int number;
    printf("\n Select a number between 1 to 5: ");

    while (number >= 1 && number >= 5)
    {
        scanf("%d", &number);

        switch (number)
        {
        case 1:
            printf("\n doggo");
            break;
        case 2:
            printf("\n cat");
            break;
        case 3:
            printf("\n froggo");
            break;
        case 4:
            printf("\n dolphin");
            break;
        case 5:
            printf("\n snake");
            break;
        default:
            printf("\n Invalid number. Please enter a number between 1 to 5: ");
        }
    }

    return 0;
}