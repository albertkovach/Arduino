#include <Bounce2.h>
#include "Keyboard.h"

unsigned long ZaderzhkaMultinazhatiya = 500;

const int PinKnopki1 = 4;
const int PinKnopki2 = 5;


int TekSost1;
int PredSost1 = HIGH;
bool Multinazh1 = false;
Bounce debouncer1 = Bounce(); 
unsigned long VremyaNazhatiya1;
unsigned long TekRaznicaVremeni1;

int TekSost2;
int PredSost2 = HIGH;
bool Multinazh2 = false;
Bounce debouncer2 = Bounce(); 
unsigned long VremyaNazhatiya2;
unsigned long TekRaznicaVremeni2;



void setup() {
  
  pinMode(PinKnopki1,INPUT);
  debouncer1.attach(PinKnopki1);
  debouncer1.interval(5);
  

  pinMode(PinKnopki2,INPUT);
  debouncer2.attach(PinKnopki2);
  debouncer2.interval(5);

  Keyboard.begin();
}



void loop() {
  debouncer1.update();
  debouncer2.update();
  
  int TekSost1 = debouncer1.read();
  int TekSost2 = debouncer2.read();
  
  if (TekSost1 == HIGH) {
      if (TekSost1 != PredSost1 && TekRaznicaVremeni1 < ZaderzhkaMultinazhatiya) {
        VremyaNazhatiya1 = millis();
        Keyboard.press('z');
        delay(5);
        Keyboard.release('z');
      }
  
      TekRaznicaVremeni1 = millis() - VremyaNazhatiya1;
  
      if (TekRaznicaVremeni1 > ZaderzhkaMultinazhatiya) {
        Keyboard.press('z');
      } else {
        Keyboard.release('z');
      }

      PredSost1 = TekSost1;
      
  } else {
     PredSost1 = LOW;
     VremyaNazhatiya1 = 0;
     Keyboard.release('z');
  }





  if (TekSost2 == HIGH) {
      if (TekSost2 != PredSost2 && TekRaznicaVremeni2 < ZaderzhkaMultinazhatiya) {
        VremyaNazhatiya2 = millis();
        Keyboard.press('x');
        delay(5);
        Keyboard.release('x');
      }
  
      TekRaznicaVremeni2 = millis() - VremyaNazhatiya2;
  
      if (TekRaznicaVremeni2 > ZaderzhkaMultinazhatiya) {
        Keyboard.press('x');
      } else {
        Keyboard.release('x');
      }
      
      PredSost2 = TekSost2;
      
  } else {
     PredSost2 = LOW;
     VremyaNazhatiya2 = 0;
     Keyboard.release('x');
  }
  
}
