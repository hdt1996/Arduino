#include <Arduino.h>
#ifndef DATATYPES
    #define DATATYPES

    namespace Datatypes
    {
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
        const char* get(float val);
        const char* get(double val);
        const char* get(int val);
        const char* get(long val);
        const char* get(bool val);
        const char* get(byte val);
        const char* get(word val);
        const char* get(float* val);
        const char* get(double* val);
        const char* get(int* val);
        const char* get(long* val);
        const char* get(bool* val);
        const char* get(byte* val);
        const char* get(word* val);
        
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

            template <typename ARG, typename BASE>
            class MULTI: public Unit
            {
                private:
                    BASE* value_ptr;
                    const char* type_ptr;
                    unsigned int* dimensions;
                    unsigned int num_dimensions;
                public:
                    MULTI(ARG value, const char* type_name = NULL, unsigned int num_dimensions = 1, ...);
                    MULTI(){};
                    void update(ARG new_value);
                    char* valueToString();
                    BASE* getPointer();
                    BASE value();
                    char* type();
            };
            template <typename ARG, typename BASE>
            class SINGLE: public Unit
            {
                private:
                    BASE* value_ptr;
                    char* type_ptr;
                public:
                    SINGLE(ARG value);
                    SINGLE(){};
                    void update(ARG new_value);
                    char* valueToString();
                    BASE* getPointer();
                    BASE value();
                    char* type();
            };
        };

    };
    #include "datatypes.hpp"
#endif
