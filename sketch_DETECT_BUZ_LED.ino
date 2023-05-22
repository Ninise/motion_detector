int ledPin = 13;                // choose the pin for the LED
int inputPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
#include "pitches.h"

#define BLUE 3

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(BLUE, OUTPUT);
  digitalWrite(BLUE, HIGH);

  Serial.begin(9600);
}
 
void loop() {
  
  val = digitalRead(inputPin);  // read input value
  
  if (val == HIGH) {	// check if the input is HIGH          
    digitalWrite(ledPin, HIGH);  // turn LED ON
	
    if (pirState == LOW) {
      Serial.println("Motion detected!");	// print on output change
      pirState = HIGH;
      digitalWrite(BLUE, LOW);
      tone(4, NOTE_G5, 500);

    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
	
    if (pirState == HIGH) {
      digitalWrite(BLUE, HIGH);
      Serial.println("Motion ended!");	// print on output change
      pirState = LOW;
      tone(4, NOTE_C5, 200);
    }
  }
}