#include <Arduino.h>
#ifndef DATATYPES
    #define DATATYPES

    namespace Datatypes
    {
        static char* const_char_pstr = "const char*";
        static char* char_pstr = "char*";
        static char* float_str="float";
        static char* double_str="double";
        static char* int_str="int";
        static char* long_str="long";
        static char* bool_str="bool";
        static char* byte_str="byte";
        static char* word_str="word";
        static char* float_pstr="float*";
        static char* double_pstr="double*";
        static char* int_pstr="int*";
        static char* long_pstr="long*";
        static char* bool_pstr="bool*";
        static char* byte_pstr="byte*";
        static char* word_pstr="word*";

        char * get(char* val);
        char * get(const char* val);
        char * get(float val);
        char * get(double val);
        char * get(int val);
        char * get(long val);
        char * get(bool val);
        char * get(byte val);
        char * get(word val);
        char * get(float* val);
        char * get(double* val);
        char * get(int* val);
        char * get(long* val);
        char * get(bool* val);
        char * get(byte* val);
        char * get(word* val);
        
        char* toCharArray(double val);
        char* toCharArray(double* val);
        char* toCharArray(int val);
        char* toCharArray(int* val);
        char* toCharArray(char * val);
        char* toCharArray(const char * val);
        template <typename T>
        bool checkForString(T value);



        namespace Container
        {
            class Unit
            {
                public:
                    Unit(){};
            };
            template <typename BASE>
            BASE* update(BASE new_value);

            template <typename BASE>
            char* update(const char* new_value);

            template <typename BASE>
            char* update(char* new_value);

            template <typename BASE>
            BASE* init(BASE value);

            template <typename BASE>
            char* init(const char* value);

            template <typename BASE>
            BASE value(BASE* val_ptr);

            template <typename MEMBER, typename ARG, typename BASE>
            class Data: public Unit
            {
                private:
                    MEMBER value_ptr;
                    char* type;
                public:
                    Data(ARG value);
                    Data(){};
                    void update(ARG new_value);
                    char* valueToString();
                    MEMBER getPointer();
                    BASE value();
            };
        };

    };
    #include "datatypes.hpp"
#endif
