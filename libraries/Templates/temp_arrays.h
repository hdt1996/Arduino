#ifndef TEMPLATE_ARRAYS
    #define TEMPLATE_ARRAYS
    #include <Arduino.h>
    #include "temp_arrays_aP.h"
    namespace Template
    {
        namespace Checks
        {
            ////////////////////// Check if is array ///////////////////////////////
            template<typename T> //not array
            struct is_array ;

            template<typename T, int N> //pointer to an array
            struct is_array<T(*)[N]> ;

            template<typename T, int N> //array
            struct is_array<T[N]> ;
        };

        namespace Modify
        {
            template<typename T> //not array
            struct remove_dimension;

            template<typename T, int N> //pointer to an array
            struct remove_dimension<T(*)[N]>;

            template<typename T, int N> //array
            struct remove_dimension<T[N]>;
        };

        namespace Structs
        {
            struct ArrayData;   
        };

        namespace Arrays
        {
            template<typename T>
            bool isArray(T arg);

            template<typename T>
            unsigned int getNDims(T arg);

            template<typename T>
            unsigned int getNDims(T* arg);

            template<typename T>
            void inputDims(T arg, Structs::ArrayData* data, unsigned int prev_size, unsigned int i = 0);

            template<typename T>
            void inputDims(T* arg, Structs::ArrayData* data, unsigned int prev_size, unsigned int i = 0);

            template<typename T>
            Structs::ArrayData* getArrayData(T args);

            template<typename PTR>
            void allocPointer(PTR* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
        
            template<typename T>
            unsigned int getNDimsbyType();

            template<typename PTR, typename ARG>
            void setPointer(double* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);

            template<typename PTR, typename ARG>
            void setPointer(PTR* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
        };
    };
    #include "temp_arrays.hpp""
#endif
