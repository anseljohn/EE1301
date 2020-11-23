/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/owner/Documents/School/ee1301Main/EE1301/Labs/IoT/Lab4/src/Lab4.ino"
/*
 * Project Lab4
 * Description:
 * Author:
 * Date:
 */

void setup();
void loop();
void updateButtonState(int pCurrentState);
void ledOn();
void ledOff();
void blinkLED(int pDelayMS);
void updateBlinkState(int pBlinkStateCounter);
#line 8 "/Users/owner/Documents/School/ee1301Main/EE1301/Labs/IoT/Lab4/src/Lab4.ino"
enum BUTTON_STATE {
  PRESSED,
  NOT_PRESSED
};

// defined by ms delay
enum BLINK_STATE {
  ONE_PER_SEC, 
  HALF_PER_SEC,
  QUARTER_PER_SEC
};

int mButtonPIN = D2;
BUTTON_STATE mButtonState;
BUTTON_STATE mPrevButtonState;
bool mJustPressed;

int mLedPIN = D7;
BLINK_STATE mBlinkState;
int mBlinkStateCounter = 0;
int mBlinkDelay = 0;


// setup() runs once, when the device is first turned on.
void setup() {
  pinMode(mButtonPIN, INPUT_PULLDOWN);
  pinMode(mLedPIN, OUTPUT);
  Serial.begin(9600);

  mButtonState = NOT_PRESSED;
  mPrevButtonState = mButtonState;
  mJustPressed = false;
  mBlinkState = ONE_PER_SEC;
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  updateButtonState(digitalRead(mButtonPIN));
  updateBlinkState(mBlinkStateCounter);

}

void updateButtonState(int pCurrentState) {
  if (pCurrentState == HIGH) {
    mButtonState = PRESSED;
  } else {
    mButtonState = NOT_PRESSED;
  }

  if (mButtonState == PRESSED && mPrevButtonState == NOT_PRESSED) {
    mJustPressed = true;
  } else {
    mJustPressed = false;
  }

  mPrevButtonState = mButtonState;
}

void ledOn() {
  digitalWrite(mLedPIN, HIGH);
}

void ledOff() {
  digitalWrite(mLedPIN, LOW);
}

void blinkLED(int pDelayMS) {
  ledOn();
  delay(pDelayMS);
  ledOff();
  delay(pDelayMS);
}

void updateBlinkState(int pBlinkStateCounter) {
  if (mJustPressed) {
    mBlinkStateCounter++;
    if (mBlinkStateCounter > 2) { // The highest blink state value
      mBlinkStateCounter = 0;
    }
  }
  mBlinkState = BLINK_STATE(pBlinkStateCounter);

  switch (mBlinkState) {
    case ONE_PER_SEC:
      mBlinkDelay = 500;
    
    case HALF_PER_SEC:
      mBlinkDelay = 1000;

    case QUARTER_PER_SEC:
      mBlinkDelay = 2000;
  }

  blinkLED(mBlinkDelay);
}