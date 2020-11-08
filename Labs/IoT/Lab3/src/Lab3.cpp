/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "/Users/owner/Documents/School/ee1301Main/EE1301/Labs/IoT/Lab3/src/Lab3.ino"
/*
 * Project Lab3
 * Description:
 * Author:
 * Date:
 */

#include "Particle.h"
#include "neopixel.h"

// Function headers
void setup();
void loop();
#line 12 "/Users/owner/Documents/School/ee1301Main/EE1301/Labs/IoT/Lab3/src/Lab3.ino"
int setMode(String modeStr);

// Global vars
double temp = 0;
int TEMP_PIN = D7;
int LED_PIN = D4;
Adafruit_NeoPixel led = Adafruit_NeoPixel(1, LED_PIN, WS2811);
enum thermode {COOLING, OFF, HEATING, REDALERT};
thermode mode = OFF;

int coolingColor = led.Color(0, 0, 100);
int heatingColor = led.Color(100, 0, 0);
int offColor = led.Color(100, 100, 100);

void setup() {
  Serial.begin(9600);
  pinMode(TEMP_PIN, OUTPUT);
  pinMode(A0, INPUT);

  Particle.variable("temperature", temp);
  Particle.function("setMode", setMode);

  led.begin();
}

void loop() {
  digitalWrite(TEMP_PIN, HIGH);
  delay(10);
  temp = (analogRead(A0) - 620) / 12.4;
  digitalWrite(TEMP_PIN, LOW);
  Serial.print(temp);
  Serial.println(";");

  switch (mode) {
    case COOLING: 
      led.setPixelColor(0, coolingColor);
      break;
    case OFF: 
      led.setPixelColor(0, offColor);
      break;
    case HEATING: 
      led.setPixelColor(0, heatingColor);
      break;
  }



  led.show();

  delay(500);
}

int setMode(String modeStr) {
  if (modeStr == "Cool") {
    mode = COOLING;
  } else if (modeStr == "Off") {
    mode = OFF;
  } else if (modeStr == "Heat") {
    mode = HEATING;
  } else if (modeStr == "REDALERT") {
    mode = REDALERT;
  } else {
    Serial.print("Invalid mode: ");
    Serial.println(modeStr);
    mode = OFF;
    return -1;
  }
  return 1;
}