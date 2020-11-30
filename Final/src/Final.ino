/*
 * Project Final
 * Description: Final project
 * Author: anseljohn
 * Date: 11/29/20
 */

#include "Particle.h"
#include "neopixel.h"

// STATES
enum ALARM_STATUS {
    ARMED,
    DISARMED
};

enum BUTTON_STATE {
    PRESSED,
    NOT_PRESSED
};


// Pins
const int BUTTON_PIN = D2;
const int PIXEL_PIN = D0;

// Pixel vars
const int PIXEL_COUNT = 1;
const int PIXEL_TYPE = WS2811;
Adafruit_NeoPixel mSystemStatusLED = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Colors
const int COLOR_ARMED = mSystemStatusLED.Color(255, 0, 0);
const int COLOR_DISARMED = mSystemStatusLED.Color(0, 255, 0);

// Button vars
BUTTON_STATE mCurrentButtonState;
BUTTON_STATE mPreviousButtonState;
bool mJustPressed;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLDOWN);

    mSystemStatusLED.begin();
    mCurrentButtonState = NOT_PRESSED;
    mPreviousButtonState = mCurrentButtonState;
    mJustPressed = false;
}

void loop() {
    mSystemStatusLED.setPixelColor(0, COLOR_ARMED);
    mSystemStatusLED.show();
}

// State updating
/**
 * Updates the state of the button based on its current reading
 * Checks change in state to determine if it was just pressed
 * Updates previous state
 */
void updateButtonState(int pCurrent) {
    if (pCurrent == HIGH) {
        mCurrentButtonState = PRESSED;
    } else {
        mCurrentButtonState = NOT_PRESSED;
    }
    
    if (pCurrent == PRESSED && mPreviousButtonState == NOT_PRESSED) {
        mJustPressed = true;
    } else {
        mJustPressed = false;
    }

    mPreviousButtonState = mCurrentButtonState;
}

// Misc functions
