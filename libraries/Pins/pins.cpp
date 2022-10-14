#include "pins.h"

namespace Pins
{
    int* Active::pins=new int[54];
    float* Active::voltages=new float[54];
    void setPins(int total_pins, int * pins, int type) //same as int pins [] due to decay
    {
        for(int i = 0; i < total_pins; i++)
        {
            pinMode(pins[i], type);
            //Active::pins
        };
    };
    void powerPins()
    {
        
    };

};
