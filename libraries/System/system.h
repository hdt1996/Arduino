#include <Arduino.h>

namespace System
{
    void getInfo();
    class SystemProperties
    {
        public:
            static unsigned long int baud_bit;
            static unsigned long int baud_byte;
            static double baud_period;
            static double debug_period;
            static unsigned long int adc_conv_cycles;
            static unsigned long int adc_frequency;
            static double adc_sampling_period;
            static double adc_sampling_rate;
            static unsigned long int cpu_frequency;
            static double timer;
    };
}