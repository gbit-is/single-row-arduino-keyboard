#include "Keyboard.h"


//-----------------+
//  Set Variables  |
//-----------------+


//--------+
// Pinout |
//--------+

// Define which arduino pins are used as input
int myPins[] = {2, 3, 7, 9};

//-------+
// Keys  |
//-------+

// Define what the each key does
// You can either use ascii int values or string values
// strings are easier to read as code, ascii int's are more flexible

int myChars[] = { KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW, KEY_DOWN_ARROW };

//  could also be written as int myChars[] = { 218, 215, 216, 217 };
//  special characters: https://www.arduino.cc/en/Reference/KeyboardModifiers
//  Ascii table: http://www.asciitable.com/


String myCharsS[] = { "a", "b", "c", "foo" };

// can be single letters or full strings

//-------+
// delay |
//-------+

int repress = 100; // time it takes from a keystroke being sent until the next one can start



int pinCount = sizeof(myPins) / sizeof(myPins[0]);


void setup() {

  Serial.begin(9600); // used for debug
  Keyboard.begin();

  // initialise each input pin with an internal pullup
  for (byte i = 0; i < pinCount; i = i + 1) {
    pinMode(myPins[i], INPUT_PULLUP);
  }


}



void loop() {


  // For each key pressed
  for (byte i = 0; i < pinCount; i = i + 1) {


    bool buttonState = digitalRead(myPins[i]);    // Read pinState
    int schar = myChars[i];                       // Get value of Ascii char
    String scharS = myCharsS[i];                  // Get value of string Char

    if (!buttonState) {       // if button is pressed (else check next key)
      //Serial.println(scharS);   // print string char to console
      //Keyboard.print(scharS);   // output string char as keyboard

      //Serial.println(schar);    // print ascii char to console
      Keyboard.write(schar);    // output ascii char as keyboard
    }


  }

  delay(repress);
}

