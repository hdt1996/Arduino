#include "pins.h"

namespace Pins
{
    //HashMap::HMap<int>* Active::pins=HashMap::init<int>();
    float* Active::voltages=new float[54];
    void Active::setInputPins(int total_pins, int * pins) //same as int pins [] due to decay
    {
        for(int i = 0; i < total_pins; i++)
        {
            pinMode(pins[i], INPUT);
        };
    };
    void Active::setOutputPins(int total_pins, int * pins) //same as int pins [] due to decay
    {
        for(int i = 0; i < total_pins; i++)
        {
            pinMode(pins[i], OUTPUT);
        };
    };
};
