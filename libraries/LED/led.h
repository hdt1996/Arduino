#include <Arduino.h>
#ifndef LEDS
    #define LEDS
    namespace LEDs
    {
        namespace Lighting
        {
            void lightPin(int pin_num, float freq, int base, float intensity);
            void lightPin(int total_pins, int* pin_nums, float freq, int base, float* intensities);
            void lightPin(int pin_num, float freq, int base, int on);
        };

    };
#endif