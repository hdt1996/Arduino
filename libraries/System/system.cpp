#include "system.h"
#include "logger.h"
#include "datatypes.h"
namespace System
{
    unsigned long int SystemProperties::cpu_frequency = NULL;
    unsigned long int SystemProperties::baud_bit = NULL;
    unsigned long int SystemProperties::baud_byte = NULL;
    double SystemProperties::baud_period = NULL;
    unsigned long int SystemProperties::adc_conv_cycles = NULL;
    unsigned long int SystemProperties::adc_frequency = NULL;
    double SystemProperties::adc_sampling_period = NULL;
    double SystemProperties::debug_period = NULL;
};

void System::getInfo()
{
    char msg_str[350];
    int max_buffer_size=256;
    unsigned long int baud = 115200; //bits per second
    unsigned long int baud_byte = baud/10; //bytes per second
    double baud_period = (double)(1/(double)baud_byte)*1000000; //microsends per byte

    unsigned long int clock_speed = F_CPU/1000000; //mHz per second m(cycles) per second
    unsigned int adc_cycles = 14; //cycles per conversion of sample
    unsigned long int adc_clock_speed = (unsigned long int)((double)clock_speed/128*1000); 
    double adc_sampling_period = (double)(1/(double)adc_clock_speed)*adc_cycles*1000;//time per conversion of sample in microseconds
                                //adc_clockspeed/adc_cycles is the max sampling rate (conversion rate)
    double debug_period = (double)(1/(double)baud_byte)*1000*max_buffer_size; //millisecond interval for logging
    System::SystemProperties::cpu_frequency = clock_speed;
    System::SystemProperties::baud_bit = baud;
    System::SystemProperties::baud_byte = baud_byte;
    System::SystemProperties::baud_period = baud_period;
    System::SystemProperties::adc_conv_cycles = adc_cycles;
    System::SystemProperties::adc_frequency = adc_clock_speed;
    System::SystemProperties::adc_sampling_period = adc_sampling_period;
    System::SystemProperties::debug_period = debug_period;

    char * adc_p_str = Datatypes::toCharArray(adc_sampling_period);
    char * br_str = Datatypes::toCharArray(baud_period);
    char * adc_r_str = Datatypes::toCharArray(1/(adc_sampling_period)*pow((double)10,6));
    char * debug_p_str = Datatypes::toCharArray(debug_period);
    sprintf(msg_str,"Baud: %lu\nBaud (Byte) %lu\nBaud Period: %s microseconds per byte\nSuggested Debug Period: %s\nCPU Speed: %lu Mhz\nADC Conversion: 14 cycles\nADC Speed: %lu kHz\nADC Sampling Period: %s microseconds per sample\nADC Sampling Rate: %s hz\n",baud,baud_byte, br_str, debug_p_str, clock_speed,adc_clock_speed, adc_p_str, adc_r_str);
    Serial.println(msg_str);
    delete adc_p_str;
    delete br_str;
    delete adc_r_str;
    delete debug_p_str;
}
