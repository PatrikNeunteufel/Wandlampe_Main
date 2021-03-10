/*
 * RGB_Stripe.h Library for the use with RGB-Stripes
 * Created by Patrik Neunteufel 2021
*/
#ifndef RGB_STRIPE_H
#define RGB_STRIPE_H

#include "Arduino.h"
#include "FastLED.h"

#define DATA_PIN 6 //yellow
#define CLOCK_PIN 5 //green
#define STRIPE_TYPE APA102
#define COLOR_ORDER BGR


template <int NUM>
class RGB_Stripe{
  public:
    RGB_Stripe();
    RGB_Stripe(uint8_t brightness);
    void init();
    void test();
    void clear();
    void brighten(uint8_t increment = 5);
    void darken(uint8_t decrement = 5);
    void setBrightness(uint8_t brightness, bool apply=true);// if apply is true (default) the new Brightness will be set to the ledStripe
    uint8_t getBrightness();
    void setMinBrightness(uint8_t brightness);
    uint8_t getMinBrightness();
    void setMaxBrightness(uint8_t brightness);
    uint8_t getMaxBrightness();
    void setColor(CRGB color);
    void setColor(CHSV color);
    void callProgram(uint8_t number);


  private:
    CRGB _leds[NUM];
    int _num=NUM;
    uint8_t _brightness = 120;
    uint8_t _min_brightness = 0;
    uint8_t _max_brightness = 200;
    CRGB _rgbColor = CRGB::Red;
    CHSV _hsvColor = CHSV(125,255,255);

};

#include "RGB_Stripe.cpp.h"
#endif
