#include "RGB_Stripe.h"

RGB_Stripe::RGB_Stripe(int n){
  _num = n;
}
RGB_Stripe::RGB_Stripe(CRGB *leds, int n){
  _leds=leds;
  _num = n;
}
RGB_Stripe::RGB_Stripe(CRGB *leds, int n, uint8_t brightness){
  _leds=leds;
  _num = n;
  _brightness= brightness;
}
void RGB_Stripe::initStripe(){
  FastLED.addLeds<STRIPE_TYPE, DATA_PIN,CLOCK_PIN,COLOR_ORDER>(_leds, _num);
  FastLED.setBrightness(_brightness);
}
void RGB_Stripe::test(){
  _leds[0]=CRGB::Red;
  _leds[1]=CRGB::Green;
  _leds[2]=CRGB::Blue;
  FastLED.show();
}
void RGB_Stripe::clear(){
  fill_solid(_leds, _num, CRGB::Black);
  FastLED.show();
}
void RGB_Stripe::brighten(uint8_t increment){
  if(_brightness + increment >= _max_brightness ){
   _brightness = _max_brightness;
  }else{
    _brightness += increment;
    }
   FastLED.setBrightness(_brightness);
  }
void RGB_Stripe::darken(uint8_t decrement){
  if(_brightness - decrement <= _min_brightness){
    _brightness=_min_brightness;
  }else{
    _brightness -= decrement;
  }
  FastLED.setBrightness(_brightness);
}
uint8_t  RGB_Stripe::getBrightness(){
  return _brightness;
}
uint8_t  RGB_Stripe::getMinBrightness(){
  return _min_brightness;
}
uint8_t  RGB_Stripe::getMaxBrightness(){
  return _max_brightness;
}
void RGB_Stripe::setBrightness(uint8_t brightness, bool apply){
  _brightness=brightness;
  if(apply){
    FastLED.setBrightness(_brightness);
  }
}
void RGB_Stripe::setMinBrightness(uint8_t brightness){
  _min_brightness=brightness;
}
void RGB_Stripe::setMaxBrightness(uint8_t brightness){
  _max_brightness=brightness;
}
void RGB_Stripe::setColor(CRGB color){
  _rgbColor=color;
}
void RGB_Stripe::setColor(CHSV color){
  _hsvColor=color;
}
void RGB_Stripe::callProgram(uint8_t number){
  switch(number){
    case 0:{
      test();
      break;
    }
    case 1:{
      fill_solid(_leds, _num, _rgbColor);
      FastLED.setBrightness(_brightness);
      FastLED.show();
      break;
    }
    case 2:{
      fill_solid(_leds, _num, _hsvColor);
      FastLED.show();
      break;
    }
    case 3:{
      fill_gradient_RGB(_leds, _num, CRGB::Green, CRGB::Yellow);
      FastLED.setBrightness(_brightness);
      FastLED.show();
      break;
    }
    case 4:{
      fill_rainbow(_leds, _num, 10, 255 / _num);
      FastLED.setBrightness(_brightness);
      FastLED.show();
      break;
    }
    case 5:{
      static uint8_t hue = 0;
      for(int i = 0; i < _num; i++){
        _leds[i] = CHSV(hue + (uint8_t)i*6, 255, 255);
      FastLED.show();
      }
      EVERY_N_MILLISECONDS(15){
        hue+=2;
      }
      break;
    }
    case 6:{
      EVERY_N_MILLISECONDS(15){
        _leds[0] = CHSV(160, random8(100,255), random8(100,125));
        for(int i=_num - 1; i>0;i--){
          _leds[i] = _leds[i-1];
        }
        FastLED.show();
      }
      break;
    }
    case 7:{
      static uint8_t sat = 200;
      EVERY_N_MILLISECONDS(45){
        sat = random8(160,255);
      }
      EVERY_N_MILLISECONDS(15){
        _leds[0] = CHSV(random8(10,30), sat, random8(100,125));
        for(int i=_num - 1; i>0 ; i--){
          _leds[i] = _leds[i-1];
        }
        FastLED.show();
      }
      break;
    }
    case 100:{
      static bool isDarkening =true;
      if(isDarkening){
        darken();
      }else{
        brighten();
      }
      if(_brightness>=_max_brightness){
        isDarkening=true;
      }else if(_brightness<=_min_brightness){
        isDarkening=false;
      }
      break;
    }
    default:{
      break;
    }
  }
}
