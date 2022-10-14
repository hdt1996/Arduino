
#include "led.h"
#include "electrical.h"
#include "system.h"
#include "MemoryFree.h"
#include "logger.h"
#include "prompt.h"
#include "pins.h"
int pins[] = {8};
int rgb_pins[] = {5,6,9};
int read_pins[] = {A2};
int buzz_pins[]={10};
float rgb_intensities[]={.15f,.85f,.85f};
unsigned int timer = 0;
void setup(){
  Serial.begin(115200);
  while(!Serial);
  delay(3000);
  Pins::setPins(sizeof(buzz_pins)/sizeof(buzz_pins[0]),buzz_pins, OUTPUT);
  //Pins::setPins((3,rgb_pins, OUTPUT);
  //Pins::setPins((1,read_pins, INPUT);
  //digitalWrite(10,HIGH);
  //digitalWrite(11,LOW);
  System::getInfo();
  //Serial.println(System::SystemProperties::debug_period);

}
int freq = 2000;
char msg[100];
void loop(){ 
  ///LEDs::Lighting::lightPin(10,.5,550,HIGH);
  /*
  digitalWrite(10,HIGH);
  delayMicroseconds(freq);
  digitalWrite(10,LOW);
  delayMicroseconds(freq);
  */
  //LEDs::Lighting::lightPin(11,.5,1000,HIGH);
  //LEDs::Lighting::lightPin(12,.5,250,HIGH);
  //LEDs::Lighting::lightPin(13,.5,250,HIGH);
  //LEDs::Lighting::lightPin(3,rgb_pins,.5,250,rgb_intensities);
  ///Electrical::logVoltage(1,read_pins);
  //Logger::safeLog("Testing.................................................................................\n");
}