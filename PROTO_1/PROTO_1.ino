
#include "led.h"
#include "electrical.h"
#include "system.h"
#include "MemoryFree.h"
#include "logger.h"
#include "prompt.h"
#include "pins.h"
#include "hashmap.h"

int pins[] = {8};
int rgb_pins[] = {5,6,9};
int read_pins[] = {A2};
int buzz_pins[]={10};
float rgb_intensities[]={.15f,.85f,.85f};
unsigned int timer = 0;


void setup(){
  Serial.begin(115200);
  while(!Serial);
  delay(1000);
  //System::getInfo();
  Datatypes::Container::Data<char*,const char*, char> test_container("HELLOOOOOO BOY");
  Structures::Dictionary<char*, const char*, char> dict;
  dict.setEntry("HELLO","WORLD");
  dict.printEntries();
  Serial.println(test_container.valueToString());
  Serial.println(test_container.getPointer());
  Datatypes::Container::Data<double*,double, double> test_container2(55555.00);
  Serial.println(test_container2.valueToString());
  Serial.println(test_container2.value());
}


int freq = 2000;
int original = getFreeMemory();
void loop()
{/*
  Serial.println(original);
  Serial.println(getFreeMemory());
  char test1[]="HUNG0";
  char test2[]="HUNG1";
  char test3[]="HUNG2";
  char test4[]="HUNG3";
  char test5[]="HUNG4";
  char test6[]="HUNG5";
  char test7[]="HUNG6";
  char test8[]="HUNG7";

  Structures::Dictionary<char*, const char*, char> dict;
  dict.setEntry(test1,"WORLD");
  dict.setEntry(test2,"WORLD");
  dict.setEntry(test3,"WORLD");
  dict.setEntry(test4,"WORLD");
  dict.setEntry(test5,"WORLD");
  dict.setEntry(test6,"WORLD");
  dict.setEntry(test7,"WORLD");
  dict.setEntry(test8,"WORLD");
  dict.removeEntry(test1);
  dict.removeEntry(test8);
  dict.prune();
  delay(1000);*/
}