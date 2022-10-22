#ifndef TEMPLATE_POINTERS
    #define TEMPLATE_POINTERS
    #include <Arduino.h>
    #include "temp_pointers_mP.h"
    #include "temp_pointers_dP.h"
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
        };
        
        namespace Modify
        {
            template<typename T>
            struct add_pointer;

            template<typename T>
            struct remove_pointer;

            template<typename T>
            struct remove_pointer<T*>;
        };

        namespace Structs
        {
            struct PointerUnit{ //Base
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
                void testPrint() override
                {
                    Serial.println("I am the child");
                };
            };
        };

        namespace Pointers
        {
            template<typename T>
            T recursePointer(T* arg); //main recursion for pointers

            template<typename T> //ending recursion for pointers; starting recursion for array type/ pointer to arrays
            T recursePointer(T arg);

            template<typename T, typename R>
            R getValue(T arg); 


        };
    };
    #include "temp_pointers.hpp"
#endif
