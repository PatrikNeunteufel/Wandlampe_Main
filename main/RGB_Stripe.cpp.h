
template <int NUM>
RGB_Stripe<NUM>::RGB_Stripe(){
}
template <int NUM>
RGB_Stripe<NUM>::RGB_Stripe(uint8_t brightness){
  _brightness= brightness;
}
template <int NUM>
void RGB_Stripe<NUM>::init(){
  FastLED.addLeds<STRIPE_TYPE, DATA_PIN,CLOCK_PIN,COLOR_ORDER>(_leds, _num);
  FastLED.setBrightness(_brightness);
}
template <int NUM>
void RGB_Stripe<NUM>::test(){
  _leds[0]=CRGB::Red;
  _leds[1]=CRGB::Green;
  _leds[2]=CRGB::Blue;
  FastLED.show();
}
template <int NUM>
void RGB_Stripe<NUM>::clear(){
  fill_solid(_leds, _num, CRGB::Black);
  FastLED.show();
}
template <int NUM>
void RGB_Stripe<NUM>::brighten(uint8_t increment){
  if(_brightness + increment >= _max_brightness ){
   _brightness = _max_brightness;
  }else{
    _brightness += increment;
    }
   FastLED.setBrightness(_brightness);
  }
template <int NUM>
void RGB_Stripe<NUM>::darken(uint8_t decrement){
  if(_brightness - decrement <= _min_brightness){
    _brightness=_min_brightness;
  }else{
    _brightness -= decrement;
  }
  FastLED.setBrightness(_brightness);
}
template <int NUM>
uint8_t  RGB_Stripe<NUM>::getBrightness(){
  return _brightness;
}
template <int NUM>
uint8_t  RGB_Stripe<NUM>::getMinBrightness(){
  return _min_brightness;
}
template <int NUM>
uint8_t  RGB_Stripe<NUM>::getMaxBrightness(){
  return _max_brightness;
}
template <int NUM>
void RGB_Stripe<NUM>::setBrightness(uint8_t brightness, bool apply){
  _brightness=brightness;
  if(apply){
    FastLED.setBrightness(_brightness);
  }
}
template <int NUM>
void RGB_Stripe<NUM>::setMinBrightness(uint8_t brightness){
  _min_brightness=brightness;
}
template <int NUM>
void RGB_Stripe<NUM>::setMaxBrightness(uint8_t brightness){
  _max_brightness=brightness;
}
template <int NUM>
void RGB_Stripe<NUM>::setColor(CRGB color){
  _rgbColor=color;
}
template <int NUM>
void RGB_Stripe<NUM>::setColor(CHSV color){
  _hsvColor=color;
}
template <int NUM>
void RGB_Stripe<NUM>::callProgram(uint8_t number){
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
