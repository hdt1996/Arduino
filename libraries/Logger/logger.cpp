#include "logger.h"
#include <stdio.h>
#include "system.h"
#include <HardwareSerial.h>
char* Logger::floatToChar(double num)
{
    char * num_str = new char [50];
    dtostrf(num,1,2,num_str);
    //snprintf(num_str,49,"%f",num); //WILL NOT WORK for arduino because arduino CANNOT handle float to string conversion using regular c++ libraries
    //WE MUST use either built in or CALCULATE integer and float portions (NO STRING libraries) then convert to integer pieces delimited by period
    return num_str;
};

void Logger::safeLog(const char* msg)
{   
    unsigned int size = strlen(msg);
    int c = 0;
    /*
        while(c < size)
        {
            if(micros() - System::SystemProperties::timer > System::SystemProperties::baud_period)
            {
                System::SystemProperties::timer+=System::SystemProperties::baud_period;
                Serial.write(msg[c]);
                c++;
            };
        };
    */
    if(micros() - System::SystemProperties::timer > System::SystemProperties::baud_period*(size+1)*10)
    {
        System::SystemProperties::timer+=System::SystemProperties::baud_period*(size+1)*10;
        for(;c<size;c++)
        {
            Serial.write(msg[c]);
        };
    }
};

