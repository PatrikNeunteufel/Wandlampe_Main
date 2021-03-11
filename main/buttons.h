#ifndef BUTTONS_H
#define BUTTONS_H

#include "Arduino.h"

#define BUTTON_A 2 // ON resp. increase //green cable
#define BUTTON_B 4 // OFF resp. decrease //yellow cable
#define BUTTON_C 7 // high bit //orange cable
#define BUTTON_D 8 // low bit //yellow cable
/*
 * button c and d
 * HB, LB
 *  0, 0: Button A means On, Button B means off
 *  0, 1: red
 *  1, 0: green
 *  1, 1: blue
 */
#define BUTTON_MODESELECT 9  // green cable // switch display mode or switch to settings (more than 2s down)

class Buttons{
  public:
    Buttons();
    void init();
    void readInput();
    bool getStatus(int index);
    bool getOffOn(int index);
    bool getOnOff(int index);
    unsigned long getButtonDown(int index);
  private:
    const int _numberOfButtons =5;
    int _buttons[5];
    bool _aktStatus[5]={false,false,false,false,false};
    bool _lastStatus[5]={false,false,false,false,false};
    bool _is_off_on[5]={false,false,false,false,false};
    bool _is_on_off[5]={false,false,false,false,false};
    unsigned long _buttonDown[5]={0,0,0,0,0};
};
#endif
