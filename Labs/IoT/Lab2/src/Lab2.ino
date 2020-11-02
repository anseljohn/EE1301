/*
 * Project IoT Lab 2
 * Description:
 * Author: ansel054
 * Date:
 */

int ButtonPIN = D2;
int PotPIN = A2;

int PotOut = 0;
bool ButtonOut = FALSE;
bool ButtonLast = FALSE;
int ButtonCount = 0;

void setup() {
    pinMode(ButtonPIN, INPUT_PULLDOWN);
    pinMode(PotPIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    PotOut = analogRead(PotPIN);
    if(digitalRead(ButtonPIN) == HIGH && ButtonLast == LOW) {
        ButtonCount = ButtonCount + 1;
        Serial.print("Button Count = ");
        Serial.print(ButtonCount);
        Serial.print(" , Level = ");
        Serial.println(PotOut);
        ButtonLast = HIGH;
    } else if (digitalRead(ButtonPIN) == LOW) {
        ButtonLast = LOW;
    }

}
