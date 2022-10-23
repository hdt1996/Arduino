#include <Arduino.h>
#ifndef DATATYPES
    #define DATATYPES
    #include "temp_datatypes_fT.h"
    namespace Datatypes
    {
        extern const char* char_str;
        extern const char* const_char_pstr ;
        extern const char* char_pstr ;
        extern const char* float_str;
        extern const char* double_str;
        extern const char* int_str;
        extern const char* long_str;
        extern const char* bool_str;
        extern const char* byte_str;
        extern const char* word_str;

        extern const char* float_pstr;
        extern const char* double_pstr;
        extern const char* int_pstr;
        extern const char* long_pstr;
        extern const char* bool_pstr;
        extern const char* byte_pstr;
        extern const char* word_pstr;

        const char* get(char* val);
        const char* get(const char* val);
        const char* get(char val);
        const char* get(float val);
        const char* get(double val);
        const char* get(int val);
        const char* get(long val);
        const char* get(bool val);
        const char* get(byte val);
        const char* get(word val);

        const char* get(char val);
        const char* get(char* val);
        const char* get(const char* val);
        const char* get(float val);
        const char* get(double val);
        const char* get(int val);
        const char* get(long val);
        const char* get(bool val);
        const char* get(byte val);
        const char* get(word val);

        template<typename T>
        void formatType(char* str, T val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);

        template<typename T>
        char* toCharArray(char val, unsigned int min_size = 1, unsigned int num_rdigits = 2);

        template<typename T>
        char* toCharArray(char * val, unsigned int min_size = 1, unsigned int num_rdigits = 2);
        
        template<typename T>
        char* toCharArray(const char * val, unsigned int min_size = 1, unsigned int num_rdigits = 2);

        template<typename T>
        char* toCharArray(T val, unsigned int min_size = 1, unsigned int num_rdigits = 2);

        template <typename T>
        bool checkForString(T value, unsigned int min_size = 1, unsigned int num_rdigits = 2);

        template<typename T>
        unsigned int getLeftNumDigits(char* val);

        template<typename T>
        unsigned int getLeftNumDigits(const char* val);

        template <typename T>
        unsigned int getLeftNumDigits(T val);
    };
    #include "datatypes.hpp"
#endif
