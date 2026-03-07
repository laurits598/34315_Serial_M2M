

# Guide on Arduino-to-Arduino communication with SoftwareSerial
This setup allows **Arduino 1 (without an LCD)** to receive text input from the **Serial Monitor** on your PC. When you type a message and send it, Arduino 1 forwards the text to **Arduino 2** using serial communication. Arduino 2 then **displays the received message on the LCD screen**.

# Fritzing Schematic of the setup
![Fritzing Schematic of the setup](images/ex13_serial_pinout.png)

## Arduino-to-Arduino Communication with SoftwareSerial

This guide shows how to implement **Arduino-to-Arduino communication using the SoftwareSerial library**. The guide also includes how to connect a standard **16x2 LCD** to an **Arduino** using the `LiquidCrystal` library

---

## LCD Pin to Arduino Pin Mapping

| LCD Pin | Arduino GPIO |
|--------|--------------|
| RS     | GPIO 12 |
| E      | GPIO 13 |
| D4     | GPIO 5 |
| D5     | GPIO 4 |
| D6     | GPIO 3 |
| D7     | GPIO 2 |

---

## Other Required Connections

| LCD Pin | Connection |
|--------|------------|
| VSS | GND |
| VDD | 5V |
| VO  | GND *(or through a potentiometer for contrast control)* |
| RW  | GND |
| A (LED+) | 5V *(preferably through a 220Ω resistor)* |
| K (LED-) | GND |

---

## Change pins to your own
A `Config.h` file is used to store the **pin definitions and library includes** (such as the `LiquidCrystal` library). This keeps the main code cleaner and makes it easier to manage or change hardware configuration in one place.

![Locate Config.h](images/ex13_locate_config.png)

![Change Config.h](images/ex13_whenInConfig.png)



---

# Serial Communication Explanation

You type a message in the serial monitor: "hey"

1. "hey" is sent from your pc to the arduino via Serial  
2. "hey" is processed by the arduinos embedded code (i.e. it does what you told it to do). Lets say you've written code which changes the message "hey" to uppercase.  
3. The msg has been changed to "HEY", and is now sent to the other arduino via mySerial.

## Connections

Serial:  
PC <=> Arduino 1  

mySerial:  
Arduino 1 <=> Arduino 2  

## Notes

mySerial is an instance of SoftwareSerial.

UART is used for serial communication.

The Arduino UNO only has 1 Hardware UART port (TX/RX) (pin 0 and pin 1).

This hardware UART can also be used, but note that it is shared with USB.

"Shared with USB": It's the same Serial interface as "Serial.begin()".

Sharing it with "Arduino-to-Arduino communication" can pollute the Serial Monitor output.

---
