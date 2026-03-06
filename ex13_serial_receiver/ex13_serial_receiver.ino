#include <SoftwareSerial.h>
#include "Config.h"

SoftwareSerial mySerial(mySerial_RX, mySerial_TX); // RX, TX

void setup() {
  
  Serial.begin(BAUD); // Serial interface between Arduino and your pc
  mySerial.begin(BAUD); // Serial interface between the two Arduinos

  lcd.begin(16, 2);
  lcd.print("Hello"); // Just some startup msg
}

void loop() {
  if (mySerial.available()) {
    String msg = mySerial.readStringUntil('\n');
    msg.trim(); // Remove this and you get some weird char at the end - probably the \r

    Serial.print("Received: ");
    Serial.println(msg);
    
    // If you want a fixed lcd layout, e.g. "Score: " <String score>, then you have to set the cursor; lcd.cursor( col[1-2],  row[1-16] ).  
    lcd.clear();
    lcd.print(msg);
  }
}








