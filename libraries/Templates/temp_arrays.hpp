#ifndef TEMPLATE_ARRAYS_HPP 
    #define TEMPLATE_ARRAYS_HPP
    #include "temp_pointers.h"
    #include "datatypes.h"

    namespace Template
    {
        namespace Checks
        {
            ////////////////////// Check if is array ///////////////////////////////
            template<typename T> //not array
            struct is_array{ static const bool value = false; };

            template<typename T, int N> //pointer to an array
            struct is_array<T(*)[N]> { static const bool value = true; };

            template<typename T, int N> //array
            struct is_array<T[N]> { static const bool value = true; };
        };

        namespace Modify
        {
            template<typename T> //not array
            struct remove_dimension{typedef T type;};

            template<typename T, int N> //pointer to an array
            struct remove_dimension<T(*)[N]>
            {
                typedef T type;
            };

            template<typename T, int N> //array
            struct remove_dimension<T[N]> 
            {
                typedef T type;
            };
        };
        
        namespace Structs
        {
            struct ArrayData
            {
                unsigned int* dimensions;
                unsigned int num_dimensions;
                void printDimensions()
                {
                    for(int i = 0; i < num_dimensions; i++)
                    {
                        Serial.print(dimensions[i]);
                        if(i < num_dimensions - 1)
                        {
                            Serial.print(", ");
                        }
                        else {Serial.println();};
                    };
                };
                void prune(ArrayData* ptr)
                {
                    delete dimensions;
                    delete ptr;
                };
            };  
        };

        namespace Arrays
        {
            template<typename T>
            bool isArray(T arg)
            {
                Checks::is_array<T> is_array;
                return is_array.value;
            };

            template<typename T>
            unsigned int getNDims(T arg) //arg defines variable as NONpointer
            {
                return 0;
            }

            template<typename T>
            unsigned int getNDims(T* arg) //arg defines variable as pointer type (can be array passed to function)
            {
                if(isArray(arg))
                {
                    return 1 + getNDims(*arg);
                };
                return 0;
            };

            template<typename T>
            void inputDims(T arg, Structs::ArrayData* data, unsigned int prev_size, unsigned int i = 0)
            {
                return;
            };
            template<typename T>
            void inputDims(T* arg, Structs::ArrayData* data, unsigned int prev_size, unsigned int i = 0) //double(*)[3][3] T = 
            {
                unsigned int curr_size;
                unsigned int dim_size;
                curr_size = sizeof(*arg);
                dim_size = prev_size/curr_size;
                data->dimensions[i] = dim_size;
                i++;
                return inputDims(*arg, data, curr_size, i); //double[3][3] -> double(*)[3]                       //double(*)[3] -> double (*)
            };

            template<typename T>
            Structs::ArrayData* getArrayData(T args)
            {
                unsigned int num_dimensions = getNDims(args); //double(*)[3][3][3]
                Serial.println("Num Dimensions ......................");
                Serial.println(num_dimensions);
                if(num_dimensions > 0)
                {
                    Structs::ArrayData* data = new Structs::ArrayData;
                    data -> num_dimensions = num_dimensions;
                    data->dimensions = new unsigned int [num_dimensions];
                    inputDims(*args,data,sizeof(*args)); //double[3][3][3] -> double(*)[3][3]
                    return data;
                };
                return NULL;
            };


            
            template<typename PTR>
            void allocPointers(PTR* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1) //0, 3, 3, 3
            {
                // WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
                unsigned int ndims = dimensions[current]; 
                for(int i = 0; i < prev; i++) 
                {
                    typedef typename Template::Modify::lessPointer<PTR>::type less_type;
                    pointer[i] = new less_type[ndims];
                    alloc_pointers++;
                    allocPointers<less_type>(pointer[i], dimensions, current + 1, ndims);
                };
            };

            template<typename PTR>
            void freePointers(PTR* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
            {
                // WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
                unsigned int ndims = dimensions[current]; 
                current++; 
                for(int d = 0; d < prev; d++)
                {
                    typedef typename Template::Modify::lessPointer<PTR>::type less_type;
                    freePointers<less_type>(pointer[d], dimensions, current, ndims);
                    delete pointer[d];
                };
            };
            

            template<typename PTR, typename ARG>
            void setPointers(PTR* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
            {
                // WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
                unsigned int ndims = dimensions[current]; 
                current++; 
                for(int d = 0; d < prev; d++)
                {
                    typedef typename Template::Modify::lessPointer<PTR>::type less_type;
                    setPointers<less_type>(pointer[d], value[d], dimensions, current, ndims);
                };
            };

            template<typename PTR>
            void printValues(PTR* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
            {
                // WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
                unsigned int ndims = dimensions[current]; 
                current++; 
                for(int d = 0; d < prev; d++)
                {
                    indices[current-1] = d;
                    typedef typename Template::Modify::lessPointer<PTR>::type less_type;
                    printValues<less_type>(pointer[d], num_dimensions, dimensions, indices, col_size, current, ndims);
                };
            };

            template<typename T>
            unsigned int getNDimsbyType()
            {
                Checks::is_array<T> is_array;
                if(is_array.value == true)
                {
                    typedef typename Modify::remove_dimension<T>::type reduced_arr_type;
                    return 1 + getNDimsbyType<reduced_arr_type>();
                };
                return 0;
            };


        };
    }
#endif
