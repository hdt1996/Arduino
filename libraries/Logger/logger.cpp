#include "logger.h"
#include <stdio.h>
#include "system.h"
#include "timing.h"

void Logger::loopLog(const char* msg, Timing::Timer timer) //Need to input in microseconds
{   
    unsigned int size = strlen(msg);
    int c = 0;
    if(timer.check())
    {
        timer.update();
        for(;c<size;c++)
        {
            Serial.write(msg[c]);
        };
    }
};
