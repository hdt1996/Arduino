#include "datatypes.h"
namespace Datatypes
{

    char * get(char* val){return char_pstr;};
    char * get(const char* val){return const_char_pstr;};
    char * get(float val){return float_str;};
    char * get(double val){return double_str;};
    char * get(int val){return int_str;};
    char * get(long val){return long_str;};
    char * get(bool val){return bool_str;};
    char * get(byte val){return byte_str;};
    char * get(word val){return word_str;};
    char * get(float* val){return float_pstr;};
    char * get(double* val){return double_pstr;};
    char * get(int* val){return int_pstr;};
    char * get(long* val){return long_pstr;};
    char * get(bool* val){return bool_pstr;};
    char * get(byte* val){return byte_pstr;};
    char * get(word* val){return word_pstr;};

    char* toCharArray(double val)
    {
        char * str = new char [50];
        dtostrf(val,1,2,str);
        return str;
    };
    char* toCharArray(double* val)
    {
        char * str = new char [50];
        dtostrf(*val,1,2,str);
        return str;
    };
    char* toCharArray(int val)
    {
        char * str = new char [50];
        sprintf(str,"%i",val);
        return str;
    };
    char* toCharArray(int* val)
    {
        char * str = new char [50];
        sprintf(str,"%i",*val);
        return str;
    };

    char toCharArray(char val)
    {
        return val;
    };
    
    char* toCharArray(char * val)
    {
        char * str = new char [strlen(val)+1];
        strcpy(str, val);
        return val;
        
    };
    char* toCharArray(const char * val)
    {
        char * str = new char [strlen(val)+1];
        strcpy(str, val);
        return str;
    };
}
