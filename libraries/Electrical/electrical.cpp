#include "electrical.h"

namespace Electrical
{
    double getVoltage(double i, double r) //V=IR
    {
        return i*r;
    };
    double getCurrent(double v, double r) //V=IR
    {
        return v/r;
    }
    double getResistance(double v, double i) //V=IR
    {
        return v/i;
    }
    void logVoltage(int total_pins, int* read_pins)
    {

        int v;
        float v_converted;
        for(int t = 0; t < 10; t++)
        {
            for(int i = 0; i < total_pins; i++)
            {
                v=analogRead(read_pins[i]);
                v_converted=(float)v/1023.0*5.0;
                Serial.print("Voltage at ");
                Serial.print(read_pins[i]);
                Serial.print(": ");
                Serial.println(v_converted);
            };
            delay(50);
        }

    }
}