/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/PCD/Desktop/IOTEngineering/Labs/lab13/src/lab13.ino"
void isr();
void setup();
void loop();
#line 1 "c:/Users/PCD/Desktop/IOTEngineering/Labs/lab13/src/lab13.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
volatile bool interruptOccured = false; 
uint16_t count = 0;                     
uint16_t count2 = 1;                    
#include "oled-wing-adafruit.h"
OledWingAdafruit display;

void isr()
{

  interruptOccured = true;
}
void setup()
{
  
  pinMode(D6, INPUT_PULLUP);         //  HIGH
  pinMode(D7, INPUT);         // HIGH
  attachInterrupt(D6, isr, FALLING); 
  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.display();
  Serial.begin(9600);
}
bool press = false; // if interrupt button is pressed

void loop()
{
 
  display.loop(); // this needs to be called each time loop is run
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  bool value = false;  
  bool value2 = false; 
  
  value2 = digitalRead(D7);
  value = digitalRead(D6); 
  
  if (interruptOccured)
  {
       count++;
       display.print(count);
       display.display();
       interruptOccured = false;
       delay(1000);  
    
  }
  
  if(value2 == 0){
    if(press==true){
      interrupts(); // enables interrupt handling
      press = false;
      Serial.println("in the true");
      delay(1000);
    }
    else{
      noInterrupts();
      press = true;
      Serial.println();
      Serial.println("in the false");
      delay(1000);
    }
    
  }

}