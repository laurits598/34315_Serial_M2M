
#include <SoftwareSerial.h>

#define BAUD 9600
#define mySerial_RX 11
#define mySerial_TX 10

SoftwareSerial mySerial(mySerial_RX, mySerial_TX); // RX, TX

/* 
You type a message in the serial monitor: "hey"
1. "hey" is sent from your pc to the arduino via Serial
2. "hey" is processed by the arduinos embedded code (i.e. it does what you told it to do). Lets say you've written code which changes the message "hey" to uppercase.
3. The msg has been changed to "HEY", and is now sent to the other arduino via mySerial.

Serial:    PC         <=>   Arduino 1
mySerial:  Arduino 1  <=>   Arduino 2

mySerial is an instance of SoftwareSerial.

UART is used for serial communication

The Arduino UNO only has 1 Hardware UART port (TX/RX) (pin 0 and pin 1)

This hardware UART can also be used, but note that it is shared with USB. 

"Shared with USB": It's the same Serial interface as "Serial.begin()"

Sharing it with "Arduino‑to‑Arduino communication" can pollute the Serial Monitor output

*/

void setup() {
  // Serial communications between Arduino and your pc
  Serial.begin(BAUD);
  Serial.println("Start..");

  // Serial communications between the two Arduinos 
  mySerial.begin(BAUD);
  mySerial.println("Msg to mySerial");
}

void loop() {

  /* Debug code - it parses your input to the other arduino */
  if (Serial.available()) {
    String msg = Serial.readStringUntil('\n');

    Serial.print("Sending: ");
    Serial.println(msg);
    mySerial.println(msg);
  }
}

void updateLCD(String firstRow, String secondRow) {

  
  
}

/* Call this alone in the loop function */
void serialBidirectional() {

  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }

  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}








