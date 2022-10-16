#include <Arduino.h>

#ifndef PINS
    #define PINS
    //#include "hashmap.h"
    namespace Pins
    {
        class Active
        {
            public:
                //static HashMap::HMap<int>* pins;
                static float* voltages;
                void setInputPins(int total_pins, int * pins);
                void setOutputPins(int total_pins, int * pins);
                void setPins(int total_pins, int * pins, int type);
        };
    }
#endif