#include "segment.h"
#include <Arduino.h>


/*------- 7 Segement Class -------*/
SevenSegmentDisplay::SevenSegmentDisplay(int segPins[], int digPins[]) {
  for (int i = 0; i < 5; i++) segmentPins[i] = segPins[i];
  for (int i = 0; i < 3; i++) digitPins[i] = digPins[i];
}
void SevenSegmentDisplay::begin() {
  for (int i = 0; i < 5; i++) pinMode(segmentPins[i], OUTPUT);
  for (int i = 0; i < 3; i++) pinMode(digitPins[i], OUTPUT);
}
void SevenSegmentDisplay::displayNumberOnDigit(int number, int digitPin, bool showDP) {
  int bcd[10][4] = {
    {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0},
    {0, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {1, 1, 1, 0},
    {0, 0, 0, 1}, {1, 0, 0, 1}
  };
  // Set segment pins
  for (int i = 0; i < 4; i++) {
    digitalWrite(segmentPins[i], bcd[number][i]);
  }

  // Set DP pin
  digitalWrite(segmentPins[4], showDP ? HIGH : LOW);

  // Activate digit
  digitalWrite(digitPin, LOW);
  delay(5); // Multiplexing delay
  digitalWrite(digitPin, HIGH);
}

void SevenSegmentDisplay::displayNumber(int number, bool showFirstDP, bool showSecondDP, bool showThirdDP) {
  int digits[3] = {number / 100, (number / 10) % 10, number % 10};

  for (int i = 0; i < 50; i++) {
    displayNumberOnDigit(digits[0], digitPins[0], showFirstDP);
    displayNumberOnDigit(digits[1], digitPins[1], showSecondDP);
    displayNumberOnDigit(digits[2], digitPins[2], showThirdDP);
  }
}





