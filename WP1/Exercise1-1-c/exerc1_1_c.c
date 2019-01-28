/*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°		
 File name: exerc_1_1.c		
 Date: 24 Jan, 2019		
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