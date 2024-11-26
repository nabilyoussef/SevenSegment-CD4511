// Nabil Youssef
// Define the pins for all the segments

#ifndef SEGMENT_H
#define SEGMENT_H

/*------- Analog Pins -------*/
#define AMP_SNS PA0
#define V5_SNS PA1
#define V12_SNS PA2

/*------- AMP Segment Pins -------*/
#define AMP_B PB0
#define AMP_C PB1
#define AMP_D PB10
#define AMP_A PB11
#define AMP_D1 PA4
#define AMP_D2 PA5
#define AMP_D3 PA6
#define AMP_DP PA7
/*------- V5 Segment Pins -------*/
#define V5_B PB9
#define V5_C PB8
#define V5_D PB7
#define V5_A PB6
#define V5_D1 PB5
#define V5_D2 PB4
#define V5_D3 PB3
#define V5_DP PA15
/*------- V12 Segment Pins -------*/
#define V12_B PA12
#define V12_C PA11
#define V12_D PA10
#define V12_A PA9
#define V12_D1 PA8
#define V12_D2 PB15
#define V12_D3 PB14
#define V12_DP PB13 

/*------- Prototypes -------*/
class SevenSegmentDisplay {
private:
  int segmentPins[5]; // A, B, C, D, DP
  int digitPins[3];   // digit1, digit2, digit3
  void displayNumberOnDigit(int number, int digitPin, bool showDP);
public:
  SevenSegmentDisplay(int segPins[], int digPins[]);
  void begin();
  void displayNumber(int number, bool showFirstDP = false, bool showSecondDP = false, bool showThirdDP = false);
};



#endif // SEGMENT_H