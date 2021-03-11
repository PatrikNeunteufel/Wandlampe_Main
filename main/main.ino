//#include "FastLED.h"

#include "RGB_Stripe.h"
#include "data.h"
#include "buttons.h"
#include "storage.h"

#define NUM_LEDS_SIDE 3 //  @ side length of 151mm 9 or 7 LED 
#define NUM_SIDES 6
#define NUM_LEDS NUM_SIDES * NUM_LEDS_SIDE

bool checkInput();

RGB_Stripe<NUM_LEDS> myStripe;

Buttons myButtons;

Storage <mainParameters> myStorage(0,sizeof(mainParameters));
mainParameters myData;

void setup() { 
  myStripe.init();
  myButtons.init();
  myStorage.getData(myData);
  }
void loop() {
  if(checkInput()){
    //myStripe.clear();
  }
  myStripe.callProgram(myData.programNumber );
}

bool checkInput(){ 
  bool hasChanged = false;
 // EVERY_N_MILLISECONDS(15){
    myButtons.readInput();
    if(myButtons.getOnOff(4)){
     hasChanged = true;
     if(myData.programNumber<7){
        myData.programNumber++;
     }else{
        myData.programNumber=1;
     }
   }
    if(hasChanged){
      myStorage.setData(myData);
    }
 // }
  return hasChanged;
}
 
