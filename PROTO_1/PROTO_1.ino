
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

void setup()
{
  Serial.begin(115200);
  while(!Serial);
  delay(1000);

  System::getInfo();
  int test_1[5] = {555,2,3,4,5};
  int test_2 = 5;
  int test_3[2][2] = {{1,2},{3,4}};

  Serial.println(getFreeMemory());

  double array_test[3][3][3]={{{1,2,3},{4,5,6},{7,8,9}},{{10,11,12},{13,14,1555},{16,17,18}},{{},{},{}}};


  
  double *** heap_test = new double**[3];
  double n = 0;
  for(int i = 0; i < 3; i++)
  {
    heap_test[i] = new double*[3];
    for(int x = 0; x < 3; x++)
    {
      heap_test[i][x] = new double [3];
      for(int z = 0; z < 3; z++)
      {
        heap_test[i][x][z] = n;
        n++;
      };
    };
  };
  
  Container::Multiple::MULT_UCM<double, double(*)[3][3][3],3> array_container(&array_test, "double", true); //1 + 3^1 + 3^2 + 3^3... and so on for each additional dimension
  array_container.printValues(20);

  Container::Multiple::MULT_UCM<double,double****,3> heap_container(&heap_test, "double",3,3,3);
  heap_container.printValues();
  
  Container::Multiple::MULT_CM<double, double(*)[3][3][3], double(*)[3][3][3]> cm_arr_container(&array_test, "double",true);
  cm_arr_container.printValues();

  Container::Multiple::MULT_CM<double, double****, double(*)[3][3][3]> heap_container2(&heap_test, "double",3,3,3);
  heap_container2.printValues();
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
    delay(2000);
  */
}