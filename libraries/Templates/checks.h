#ifndef TEMPLATE_CHECKS 
    #define TEMPLATE_CHECKS
    #include <Arduino.h>

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
            template<typename T>
            struct add_pointer;

            template<typename T>
            struct remove_pointer;

            template<typename T>
            struct remove_pointer<T*>;

            template<typename T> //not array
            struct remove_dimension;

            template<typename T, int N> //pointer to an array
            struct remove_dimension<T(*)[N]>;

            template<typename T, int N> //array
            struct remove_dimension<T[N]>;


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
            struct PointerUnit{
                void test()
                {
                    this->testPrint();
                };
                virtual void testPrint()
                {
                    Serial.println("I am the parent");
                };

            };

            template<typename T>
            struct PointerDerived: public PointerUnit
            {
                typedef T type;
                void testPrint()
                {
                    Serial.println("I am the child");
                };
            };


            template<typename T>
            T recursePointer(T* arg); //main recursion for pointers

            template<typename T> //ending recursion for pointers; starting recursion for array type/ pointer to arrays
            T recursePointer(T arg);

            template<typename T, typename R>
            R getValue(T arg); 

            template<typename T>
            Pointers::PointerUnit* getNDimsbyType();
        };
    };
    #include "checks.hpp"
#endif
