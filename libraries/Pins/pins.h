#include <Arduino.h>


namespace Pins
{
    class Active
    {
        public:
            static int* pins;
            static float* voltages;
    };

    void setPins(int total_pins, int * pins, int type);
    void powerPins();
}