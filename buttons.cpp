#include "buttons.h"

  Buttons::Buttons(){
   _buttons[0]= BUTTON_A;
   _buttons[1]= BUTTON_B;
   _buttons[2]= BUTTON_C;
   _buttons[3]= BUTTON_D;
   _buttons[4]= BUTTON_MODESELECT;
  }
  
  void Buttons::init(){ 
   for(int i=0;i<_numberOfButtons;i++){
    pinMode(_buttons[i], INPUT_PULLUP);
   }
  }
  void Buttons::readInput(){
    for(int i=0;i<_numberOfButtons;i++){
      _lastStatus[i] = _aktStatus[i];
      _aktStatus[i] = digitalRead(_buttons[i]) == LOW;
      _is_off_on[i] = _aktStatus[i] && !_lastStatus[i];
      _is_on_off[i] = !_aktStatus[i] && _lastStatus[i];
      _buttonDown[i] = (_is_off_on[i])?millis():((_is_on_off[i])?0:_buttonDown[i]);
    }
   // bool readbuttons[5]={digitalRead(BUTTON_A) == LOW,digitalRead(BUTTON_B) == LOW,digitalRead(BUTTON_C) == LOW,digitalRead(BUTTON_D) == LOW, digitalRead(BUTTON_MODESELECT)== LOW};
  }
  bool Buttons::getStatus(int index){
    return _aktStatus[index];
  }
  
  bool Buttons::getOffOn(int index){
    return _is_off_on[index];  
  }
  bool Buttons::getOnOff(int index){
    return _is_on_off[index];
  }
  unsigned long Buttons::getButtonDown(int index){
    return _buttonDown[index];
  }
