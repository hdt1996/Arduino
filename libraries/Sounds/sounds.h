#include <Arduino.h>
#ifndef SOUNDS
    #define SOUNDS
    namespace Sounds
    {
        class Controller
        {
            public:
                long unsigned int min_tone;
                long unsigned int max_tone;
                Controller(long unsigned int min_tone, long unsigned int max_tone);
                Controller(){};
                void toneByVolts(double tone_per_volt, int* analog_pins); //use variable resistor ideal example
                void toneByVolts(double tone_per_volt, double volts);
        };
    }
#endif