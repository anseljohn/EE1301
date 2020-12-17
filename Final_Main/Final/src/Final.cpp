/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "/Users/anseljohn/Documents/School/Freshman/Fall/ee1301Main/EE1301/Final_Main/Final/src/Final.ino"
/*
 * Project Final
 * Description: Final project
 * Author: anseljohn
 * Date: 11/29/20
 */

#include "Particle.h"
#include "neopixel.h"

// STATES ENUMS
void setup();
void loop();
#line 12 "/Users/anseljohn/Documents/School/Freshman/Fall/ee1301Main/EE1301/Final_Main/Final/src/Final.ino"
enum SYSTEM_STATUS {
    ARMED,
    DISARMED
};

enum BUTTON_STATE {
    PRESSED,
    NOT_PRESSED
};

// STATES
BUTTON_STATE mCurrentButtonState;
BUTTON_STATE mPreviousButtonState;
SYSTEM_STATUS mCurrentSystemStatus;


// Pins
const int BUTTON_PIN = D2;
const int PIXEL_PIN = D0;
const int TRIG_PIN = A0;
const int ECHO_PIN = D3;

// Pixel vars
const int PIXEL_COUNT = 1;
const int PIXEL_TYPE = WS2811;
Adafruit_NeoPixel mSystemStatusLED = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Colors
const int COLOR_ARMED = mSystemStatusLED.Color(40, 0, 0);
const int COLOR_DISARMED = mSystemStatusLED.Color(0, 40, 0);

bool mJustPressed;
int timesPressed = 0;

void updateButtonState(int pCurrent);
void updateSystemState(bool pButtonPressed, SYSTEM_STATUS pCurrentStatus);
void setStatusLED(int pColor);
unsigned long int mNextTime = 0;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLDOWN);

    mSystemStatusLED.begin();
    mCurrentButtonState = NOT_PRESSED;
    mPreviousButtonState = mCurrentButtonState;
    mCurrentSystemStatus = DISARMED;

    mJustPressed = false;
}

void loop() {
    updateButtonState(digitalRead(BUTTON_PIN));
    updateSystemState(mJustPressed, mCurrentSystemStatus);

    switch (mCurrentSystemStatus) {
        case ARMED:
            setStatusLED(COLOR_ARMED);
            break;

        case DISARMED:
            setStatusLED(COLOR_DISARMED);
            break;
    }


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
    
    if (mCurrentButtonState == PRESSED && mPreviousButtonState == NOT_PRESSED) {
        mJustPressed = true;
        timesPressed++;
    } else {
        mJustPressed = false;
    }

    mPreviousButtonState = mCurrentButtonState;
}

void updateSystemState(bool pButtonPressed, SYSTEM_STATUS pCurrentStatus) {
    if (pButtonPressed) {
        if (pCurrentStatus + 1 > 1) {
            mCurrentSystemStatus = (SYSTEM_STATUS) 0;
        } else {
            mCurrentSystemStatus = (SYSTEM_STATUS) 1;
        }
    }
}


// Setters
void setStatusLED(int pColor) {
    mSystemStatusLED.setPixelColor(0, pColor);
}