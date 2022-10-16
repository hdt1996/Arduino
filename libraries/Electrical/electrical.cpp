#include "electrical.h"
#include "logger.h"
#include "datatypes.h"
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
    
    void logVoltage(int total_pins, int read_pin)
    {
        double v;
        char* v_str;
        char volt_str1[] = "Analog Pin ";
        char volt_str2[] = " Voltage: ";
        v=(double)analogRead(read_pin)/1023.0*5.0; //To supplement with System Voltage Active Pins
        v_str = Datatypes::toCharArray(v);
        char msg [(strlen(volt_str1)+strlen(volt_str2))+strlen(v_str)+1];
        sprintf(msg, "%s %s %s %s",volt_str1, volt_str2, (const char *)(read_pin),v_str);
        free(v_str);
        Serial.println(msg);
    }
    void logVoltage(int total_pins, int* read_pins)
    {
        double v;
        char volt_str1[] = "Analog Pin ";
        char volt_str2[] = " Voltage: ";
        char* volts[total_pins];
        unsigned int num_chars = 0;
        unsigned int i = 0;
        for(; i < total_pins; i++)
        {
            v=(double)analogRead(read_pins[i])/1023.0*5.0; //To supplement with System Voltage Active Pins
            volts[i] = Datatypes::toCharArray(v);
            num_chars+=strlen(volts[i]);
        };
        char msg [(strlen(volt_str1)+strlen(volt_str2))+num_chars+1];
        i = 0;
        for(; i < total_pins;i++)
        {
            strcat(msg,volt_str1);
            strcat(msg, (const char *)(read_pins[i]));
            strcat(msg,volt_str2);
            strcat(msg,volts[i]);
            strcat(msg,"\n");
            free(volts[i]);
        };
        Serial.println(msg);
    }

    double getVoltage(int total_pins, int read_pin)
    {
        return (double)analogRead(read_pin)/1023.0*5.0; //To supplement with System Voltage Active Pins
    }
    double* getVoltage(int total_pins, int* read_pins)
    {
        double* volts = new double [total_pins];
        unsigned int i = 0;
        for(; i < total_pins; i++)
        {
            //To supplement with System Voltage Active Pins
            volts[i] = (double)analogRead(read_pins[i])/1023.0*5.0;
        };
        return volts;
    }
}