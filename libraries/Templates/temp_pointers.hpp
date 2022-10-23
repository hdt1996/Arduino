#ifndef TEMPLATE_POINTERS_HPP 
    #define TEMPLATE_POINTERS_HPP
    #include "temp_arrays.h"
    namespace Template
    {
        namespace Checks
        {
            // Bool of true has value 1, 0 otherwise
            /////////////////////// Check if is pointer ////////////////////////
            template<typename T> //not pointer
            struct is_pointer { static const bool value = false; };

            template<typename T> //pointer
            struct is_pointer<T*> { static const bool value = true; };
        };

        namespace Modify
        {
            template<typename T>
            struct addPointer{typedef T* type;};

            template<typename T>
            struct lessPointer{typedef T type;};

            template<typename T>
            struct lessPointer<T*>{typedef T type;};
        };

        namespace Pointers
        {
            template<typename T>
            T recursePointer(T* arg) //main recursion for pointers
            {
                return recursePointer(*arg);
            };

            template<typename T> //ending recursion for pointers; starting recursion for array type/ pointer to arrays
            T recursePointer(T arg)
            {
                return arg;
            }

            template<typename T, typename R>
            R getValue(T arg)
            {
                Checks::is_pointer<T> is_pointer;
                if(is_pointer.value)
                {
                return recursePointer(arg);
                }
            };

        };
    };
#endif
