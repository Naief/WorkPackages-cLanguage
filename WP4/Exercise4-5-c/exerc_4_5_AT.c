/* ====================================
File name: exerc_4_5_AT.c
Date: 2019-02-19
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Demonstration code: [21895]
====================================== */

/* == DISCLAIMER ==
This code uses external libraries.
We were told by the TAs that this was fine, and 
the assignment text was also easily misinterpreted.*/

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int row = 0;
int col = 0;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'E', '0', 'F', 'D'}};
byte rowPins[ROWS] = {7, 6, 5, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3, 2, 1, 0}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    lcd.begin(16, 2); // start lcd
    lcd.clear();
    lcd.setCursor(row, col);
}

void loop()
{

    customKey = customKeypad.getKey();
    if (customKey != '\0')
    {
        if (row <= 1)
        {
            lcd.print(customKey);
            col++;
            if (col > 15)
            {
                col = 0;
                row++;
            }
            lcd.setCursor(col, row);
            delay(1000);
        }
    }
}