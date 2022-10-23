
#include "led.h"
#include "electrical.h"
#include "system.h"
#include "MemoryFree.h"
#include "logger.h"
#include "prompt.h"
#include "pins.h"
#include "hashmap.h"
#include <stdarg.h>
#include "templates.h"
#include "container.h"

int pins[] = {8};
int rgb_pins[] = {5,6,9};
int read_pins[] = {A2};
int buzz_pins[]={10};
float rgb_intensities[]={.15f,.85f,.85f};
unsigned int timer = 0;

void test(double (*test)[4][1][2])
{
  Serial.println((*test)[0][0][0]);
};

void test(double (*test)[1][2])
{
  Serial.println(test[0][0][0]);
};


void setup(){
  Serial.begin(115200);
  while(!Serial);
  delay(1000);

  System::getInfo();
  int test_1[5] = {555,2,3,4,5};
  int test_2 = 5;
  int test_3[2][2] = {{1,2},{3,4}};

  //Template::Checks::ArrayDims* array_data = Template::getArrayData(test_data);
  //double x= test_container2.value()[0][0];
  //Serial.println(x);
  //Serial.println(test_container2.type());
  //Serial.println(test_container2.valueToString());
  //Serial.println(test_container2.value()[0]);

  Serial.println(getFreeMemory());
  //Template::Structs::ArrayData* data = Template::Arrays::getArrayData(&test_data);
  //Serial.println(data->num_dimensions);
  //data->printDimensions();
  //data->prune(data);
  //test(&test_data);

  double test_data3[3][3][3][3]={{{{1.0,2.0,3.0},{1.0,2.0,3.0},{1.0,2.0,3.0}},{4.0,5.0,6.0},{7.0,8.0,9.0}},{{11.0,11.0,11.0},{11.0,11.0,11.0},{11.0,11.0,11.0}},{{13.0,14.0,15.0},{11.0,11.0,11.0},{16.0,17.0,18.0}}};
  int test_data4[3][3][3]={{{1,2,3},{4,5,6},{7,8,9}},{{},{},{}},{{},{},{}}};
  Container::MULTI<int,int(*)[3][3][3],3> test_container2(&test_data4, "double", true); //1 + 3^1 + 3^2 + 3^3... and so on for each additional dimension
  test_container2.printValues(4);
}

int freq = 2000;
int original = getFreeMemory();
void loop()
{

  delay(1500);
  /*
  Serial.print("Original Memory: ");
  Serial.print(original);
  Serial.println();
  Structures::Dictionary<const char*, char> dict;
  dict.prune();
  Serial.print("Remaining Memory after Prune: ");
  Serial.print(getFreeMemory());
  Serial.println();
  delay(2000);*/
}