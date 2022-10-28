#ifndef TEMPLATE_ARRAYS
    #define TEMPLATE_ARRAYS
    #include <Arduino.h>
    #include "temp_arrays_aP.h"
    #include "temp_arrays_sP.h"
    #include "temp_arrays_fP.h"
    #include "temp_arrays_paV.h"
    #include "temp_arrays_ppV.h"
    #include "temp_arrays_sA.h"

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

            extern unsigned int alloc_pointers;

            template<typename PTR>
            void allocPointers(PTR* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
        
            template<typename T>
            unsigned int getNDimsbyType();

            template<typename PTR>
            void freePointers(PTR* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);

            template<typename PTR, typename ARG>
            void setPointers(PTR* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);

            template<typename PTR,  typename ARG>
            void setArrays(PTR pointer, ARG value, unsigned int num_dimensions,  unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);  

            template<typename PTR>
            void printPTRVals(PTR* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);  

            template<typename PTR>
            void printARRVals(PTR pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);

        };
    };
    #include "temp_arrays.hpp""
#endif
