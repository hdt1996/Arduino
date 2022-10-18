#include "datatypes.h"
namespace Datatypes
{
    extern const char* const_char_pstr = "const char*";
    extern const char* char_pstr = "char*";
    extern const char* float_str="float";
    extern const char* double_str="double";
    extern const char* int_str="int";
    extern const char* long_str="long";
    extern const char* bool_str="bool";
    extern const char* byte_str="byte";
    extern const char* word_str="word";
    extern const char* float_pstr="float*";
    extern const char* double_pstr="double*";
    extern const char* int_pstr="int*";
    extern const char* long_pstr="long*";
    extern const char* bool_pstr="bool*";
    extern const char* byte_pstr="byte*";
    extern const char* word_pstr="word*";
    const char* get(char* val){return char_pstr;};
    const char* get(const char* val){return const_char_pstr;};
    const char* get(float val){return float_str;};
    const char* get(double val){return double_str;};
    const char* get(int val){return int_str;};
    const char* get(long val){return long_str;};
    const char* get(bool val){return bool_str;};
    const char* get(byte val){return byte_str;};
    const char* get(word val){return word_str;};
    const char* get(float* val){return float_pstr;};
    const char* get(double* val){return double_pstr;};
    const char* get(int* val){return int_pstr;};
    const char* get(long* val){return long_pstr;};
    const char* get(bool* val){return bool_pstr;};
    const char* get(byte* val){return byte_pstr;};
    const char* get(word* val){return word_pstr;};

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
