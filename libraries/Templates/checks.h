#ifndef TEMPLATE_CHECKS 
    #define TEMPLATE_CHECKS

    namespace Template
    {
        namespace Checks
        {
            // Bool of true has value 1, 0 otherwise
            /////////////////////// Check if is pointer ////////////////////////
            template<typename T> //not pointer
            struct is_pointer ;

            template<typename T> //pointer
            struct is_pointer<T*> ;

            ////////////////////// Check if is array ///////////////////////////////
            template<typename T> //not array
            struct is_array ;

            template<typename T, int N> //pointer to an array
            struct is_array<T(*)[N]> ;

            template<typename T, int N> //array
            struct is_array<T[N]> ;
        };

        namespace Arrays
        {
            struct ArrayData;   

            template<typename T>
            bool isArray(T arg);

            template<typename T>
            unsigned int getNDims(T arg);

            template<typename T>
            unsigned int getNDims(T* arg);

            template<typename T>
            void inputDims(T arg, ArrayData* data, unsigned int prev_size, unsigned int i = 0);

            template<typename T>
            void inputDims(T* arg, ArrayData* data, unsigned int prev_size, unsigned int i = 0);

            template<typename T>
            ArrayData* getArrayData(T args);

        }

        namespace Pointers
        {
            template<typename T>
            T recursePointer(T* arg); //main recursion for pointers

            template<typename T> //ending recursion for pointers; starting recursion for array type/ pointer to arrays
            T recursePointer(T arg);

            template<typename T, typename R>
            R getValue(T arg); 
        }

    }
    #include "checks.hpp"
#endif
