#include <XInput.h>

const int buttonPin1 = 0;
const int buttonPin2 = 1;
const int buttonPin3 = 2;
const int buttonPin4 = 3;
const int buttonPin5 = 9;
const int buttonPin6 = 10;


void setup() {
  Serial.begin(9600);

  // set buttons as inputs
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);

	XInput.begin();
}

void loop() {
  // read the state of the pushbutton value:
  bool buttonState1 = !digitalRead(buttonPin1);
  bool buttonState2 = !digitalRead(buttonPin2);
  bool buttonState3 = !digitalRead(buttonPin3);
  bool buttonState4 = !digitalRead(buttonPin4);
  bool buttonState5 = !digitalRead(buttonPin5);
  bool buttonState6 = !digitalRead(buttonPin6);

  if (buttonState1) {
    XInput.press(BUTTON_A);
    Serial.write('1');
  } else if (buttonState2) {
    XInput.press(BUTTON_B);
    Serial.write('2');
  } else if (buttonState3) {
    XInput.press(BUTTON_X);
    Serial.write('3');
  } else if (buttonState4) {
    XInput.press(BUTTON_Y);
    Serial.write('4');
  } else if (buttonState5) {
    XInput.press(BUTTON_LB);
    Serial.write('5');
  } else if (buttonState6) {
    XInput.press(BUTTON_RB);
    Serial.write('6');
  }

  delay(100);
}