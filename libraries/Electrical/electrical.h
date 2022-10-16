#include <Arduino.h>

#ifndef ELECTRICAL
    #define ELECTRICAL

    namespace Electrical
    {
        double getVoltage(double i, double r); //V=IR
        double getCurrent(double v, double r); //V=IR
        double getResistance(double v, double i); //V=IR
        void logVoltage(int total_pins, int* read_pins);
        void logVoltage(int total_pins, int read_pin);
        double* getVoltage(int total_pins, int* read_pins);
        double getVoltage(int total_pins, int read_pin);
    }
#endif