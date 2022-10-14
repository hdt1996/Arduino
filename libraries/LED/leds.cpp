#include "led.h"
namespace LEDs
{
  void Lighting::lightPin(int pin_num, float freq, int period, float intensity)
  {
    int max_intensity=255;
    int rounded_intensity = (int)(intensity*max_intensity);
    //Serial.println(rounded_intensity);
    float initialDelay = ((float)period)*freq;
    float postDelay = ((float)period)*(1-freq);
    delay(initialDelay);
    analogWrite(pin_num, rounded_intensity);
    delay(postDelay);
    analogWrite(pin_num, 0);
  };
  void Lighting::lightPin(int total_pins, int* pin_nums, float freq, int period, float* intensities)
  {
    float initialDelay = ((float)period)*freq;
    float postDelay = ((float)period)*(1-freq);
    int max_intensity=255;
    int rounded_intensity;
    delay(initialDelay);
    for(int i = 0; i < total_pins; i++)
    {
      rounded_intensity = (int)(intensities[i]*max_intensity);
      analogWrite(pin_nums[i], rounded_intensity);
    }
    
    delay(postDelay);
    for(int i = 0; i < total_pins; i++)
    {
      analogWrite(pin_nums[i], 0);
    }
    
  };
  void Lighting::lightPin(int pin_num, float freq, int period, int on)
  {
    float initialDelay = ((float)period)*freq;
    float postDelay = ((float)period)*(1-freq);
    delay(initialDelay);
    digitalWrite(pin_num, on);
    delay(postDelay);
    digitalWrite(pin_num, LOW);
  };
};
