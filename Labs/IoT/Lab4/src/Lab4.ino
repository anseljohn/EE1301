/*
 * Project Lab4
 * Description:
 * Author:
 * Date:
 */

enum BUTTON_STATE {
  PRESSED,
  NOT_PRESSED
};

// defined by ms delay
enum BLINK_STATE {
  ONE_PER_SEC = 500, 
  HALF_PER_SEC = 1000,
  QUARTER_PER_SEC = 2000
};

int mButtonPIN = D2;
BUTTON_STATE mButtonState;
BUTTON_STATE mPrevButtonState;
bool mJustPressed;

int mLedPIN = D7;
BLINK_STATE mBlinkState;
int mBlinkStateCounter = 0;


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

void updateBlinkState(int pBlinkStateCounter) {
  if (mJustPressed) {
    mBlinkStateCounter++;
    if (mBlinkStateCounter > 2) { // The highest blink state value
      mBlinkStateCounter = 0;
    }
  }
  mBlinkState = BLINK_STATE(pBlinkStateCounter);
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

void blinkLedFromBlinkState(BLINK_STATE pCurrentState) {
  // blinkLED(pCurrentState);
  Serial.println(pCurrentState);
}