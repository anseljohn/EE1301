/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "c:/Users/Administrator/Documents/dev/ee1301-master/EE1301/Final/src/Final.ino"
/*
 * Project Final
 * Description: Final project
 * Author: anseljohn
 * Date: 11/29/20
 */

#include "Particle.h"
#include "neopixel.h"


// Pixel Variables
void setup();
void loop();
#line 13 "c:/Users/Administrator/Documents/dev/ee1301-master/EE1301/Final/src/Final.ino"
const int PIXEL_PIN = D0;
const int PIXEL_COUNT = 1;
const int PIXEL_TYPE = WS2811;
Adafruit_NeoPixel mSystemStatusLED = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Colors
const int COLOR_ARMED = mSystemStatusLED.Color(255, 0, 0);
const int COLOR_DISARMED = mSystemStatusLED.Color(0, 255, 0);

void setup() {
    mSystemStatusLED.begin();
}

void loop() {
    mSystemStatusLED.setPixelColor(0, COLOR_ARMED);

}