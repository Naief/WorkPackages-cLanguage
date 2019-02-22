/* ====================================
File name: exerc_4.3_AT
Date: 2019-02-20
Group nr 13 (Collaborated with group 4 & 7)
Members that contribute to the solutions 
David Lindgren, Filip Fatic, Naief Jobsen, Araz Farkosh
Demonstration code: [25965]
====================================== */

// Program skeleton for the exercise 4.3 AT
// You can thisfile at course home page, Files/ Program example.../Course week #4
// -------Program skeleton for exerc 4.3 AT ----
// -------File name :   skeleton_4_3_AT.txt ----------------
//#include <avr/io.h> Not needed
#include <util/delay.h>
#define REG8(x) *((unsigned char *)(x))
// A macro to use for IO R/W
#define OUT_PORTD 0x2B
#define IN_PORTB 0x23
#define DDR_D 0x2A
#define DDR_B 0x24
#define BLINK_DELAY_MS 800
int main(void)
{
  unsigned char code;
  unsigned char incode;
  // If use of simple pointer and not macro REG8
  unsigned char *portd;
  portd = (unsigned char *)0x002B; // Must do as this
  *portd = 3;                      //If use of pointer for IO R/W

  unsigned char *portb;
  portb = (unsigned char *)IN_PORTB; // Must do as this
  *portb = 0;                        //If use of pointer for IO R/W

  //set  PORTD for output, set bit gives out
  REG8(DDR_D) = 0xFF;
  //setPORTB for input, clr bit gives inbit
  REG8(DDR_B) = 0x00;

  while (1)
  {
    //while the switch is on (port B, 0)
    if (*portb == 1)
    {

      //Checking cornercase 1 (when binary is 1100 0000, last two lamps are on)
      if (*portd == 129)
      {
        //make it to 1000 0001 (the next step, 1st and last lamp on)
        *portd = 192;
      }
      //cornercase 2 (binary is 1000 0001, 1st and last lamp on)
      else if (*portd == 192)
      {
        //the lamps reset to 3 (0000 0011)
        *portd = 3;
      }
      //otherwise keep bitshifting 1.
      else
      {
        *portd = *portd << 1;
      }
    }

    _delay_ms(BLINK_DELAY_MS); // In util/delay.h
  }
}