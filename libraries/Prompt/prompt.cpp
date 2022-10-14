#include "prompt.h"

char* Prompt::incomingStrData()
{
    while(Serial.available() == 0){};
    int size = 100;
    char * input_str = new char[size];
    unsigned int i = 0;
    char c;
    while(Serial.available() > 0 && i < size-1)
    {
        c =Serial.read();
        if(c == '\n')
        {
            input_str[i] = '\0';
            break;
        }
        input_str[i] = c;
    };
    return input_str;
};
String Prompt::inputStrPrompt()
{
    while(Serial.available() == 0){};
    int size = 100;
    char * input_str = new char[size];
    unsigned int i = 0;
    return Serial.readString();
};

int Prompt::inputIntPrompt()
{
    while(Serial.available() == 0){};
    return Serial.parseInt();
};
float Prompt::inputFloatPrompt()
{
    while(Serial.available() == 0){};
    return Serial.parseFloat();
};
int Prompt::incomingIntData()
{
    while(Serial.available() == 0){};
    int size = 100;
    char * input_str = new char[size];
    unsigned int i = 0;
    char c;
    while(Serial.available() > 0 && i < size-1)
    {
        c =Serial.read();
        if(c == '\n')
        {
            input_str[i] = '\0';
            break;
        }
        input_str[i] = c;
    };
    return atoi(input_str);

}