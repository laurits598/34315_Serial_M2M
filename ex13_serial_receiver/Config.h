#pragma once
#include <LiquidCrystal.h>

/* Software Serial - A virtual serial port (ish) */
#define BAUD 9600
#define mySerial_RX 11
#define mySerial_TX 10

/*   Or assign your own pins below
LCD Pin   ->   Arduino
-----------------------
RS        ->   GPIO 12
E         ->   GPIO 13
D4        ->   GPIO 5
D5        ->   GPIO 4
D6        ->   GPIO 3
D7        ->   GPIO 2

Other connections
-----------------------
VSS       ->   GND
VDD       ->   5V
VO        ->   GND (or potentiometer for contrast)
RW        ->   GND
A (LED+)  ->   5V (preferably through 220Ω)
K (LED-)  ->   GND

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
*/

#define RS_PIN 12
#define E_PIN 13
#define D4_PIN 5
#define D5_PIN 4
#define D6_PIN 3
#define D7_PIN 2

LiquidCrystal lcd(RS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);




