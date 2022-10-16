#include <Arduino.h>

#ifndef PROMPT
    #define PROMPT
    namespace Prompt
    {
        char* incomingStrData();
        int incomingIntData();
        String inputStrPrompt();
        int inputIntPrompt();
        float inputFloatPrompt();
    }
#endif