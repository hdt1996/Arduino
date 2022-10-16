#include <Arduino.h>

#ifndef LOGGER
    #define LOGGER
    #include "timing.h"
    namespace Logger
    {
        void loopLog(const char* msg, Timing::Timer timer);
    }
#endif