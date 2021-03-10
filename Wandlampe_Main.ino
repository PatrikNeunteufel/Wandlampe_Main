#include "FastLED.h"
#include <EEPROM.h>

#include "RGB_Stripe.h"
#include "data.h"
#include "buttons.h"
#include "storage.h"

#define NUM_LEDS_SIDE 3 //  @ side length of 151mm 9 or 7 LED 
#define NUM_SIDES 6
#define NUM_LEDS NUM_SIDES * NUM_LEDS_SIDE

CRGB leds[NUM_LEDS];
RGB_Stripe myStripe(leds, NUM_LEDS);

Buttons myButtons;

mainParameters lamp;

Storage <mainParameters> myStorage(0,sizeof(mainParameters));


mainParameters myData;
 uint8_t programNumber=7;

void setup() { 
  myStripe.initStripe();
  myStripe.clear();

  myButtons.init();
  myStorage.getData(myData);
 
  }
void loop() {
  //EVERY_N_MILLISECONDS(5){
    myButtons.readInput();
    if(myButtons.getOnOff(4)){
      myStripe.clear();
      if(myData.programNumber<7){
        myData.programNumber++;
      }else{
        myData.programNumber=1;
      }
    }
   // myStorage.setData(myData);
  //}
  myStripe.callProgram(myData.programNumber );
  //EEPROM.put(0,myData);
  myStorage.setData(myData);
}

 
