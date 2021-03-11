#ifndef DATA_H
#define DATA_H


#include "FastLED.h"
struct data{
  int a;
  int b;
};

struct stripeParameters{
    uint8_t _brightness = 120;
    uint8_t _min_brightness = 0;
    uint8_t _max_brightness = 200;
    CRGB _rgbColor = CRGB::Red;
    CHSV _hsvColor = CHSV(125,255,255);
};

struct mainParameters { // struct to write persistent data to eeprom (maybe use the same struct for that datas.... )
  
  bool mainStatus; // is Lamp on or off
  bool stripeStatus;
  bool powerLedStatus;

 uint8_t programNumber;

 stripeParameters stripeParameters;

  bool doStartupBuzzer;//activate the startup Buzzer? should be settable by the user
};



struct position {
  int bottom;
  int left;
  int top;
  int right;
};

#endif
