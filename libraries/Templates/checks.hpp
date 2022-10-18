#ifndef TEMPLATE_CHECKS_HPP 
    #define TEMPLATE_CHECKS_HPP

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

            ////////////////////// Check if is array ///////////////////////////////
            template<typename T> //not array
            struct is_array{ static const bool value = false; };


            template<typename T, int N> //pointer to an array
            struct is_array<T(*)[N]> { static const bool value = true; };

            template<typename T, int N> //array
            struct is_array<T[N]> { static const bool value = true; };
        }

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
        }

        namespace Arrays
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
            void inputDims(T arg, ArrayData* data, unsigned int prev_size, unsigned int i = 0)
            {
                Serial.println("Default\n\n\n");
                return;
            };

            template<typename T>
            void inputDims(T* arg, ArrayData* data, unsigned int prev_size, unsigned int i = 0)
            {
                unsigned int curr_size;
                if(isArray(arg))
                {
                    Serial.print("Current size: ");
                    curr_size = sizeof(*arg);
                    unsigned int dim_size = prev_size/curr_size;
                    Serial.print(dim_size);
                    Serial.println();
                    data->dimensions[i] = dim_size;
                    i++;
                    return inputDims(*arg, data, curr_size, i);
                };
                curr_size =  sizeof(arg);
                data->dimensions[i] = curr_size;
                Serial.print("Last Level Size: ");
                Serial.print(curr_size);
                Serial.println();
            };

            template<typename T>
            ArrayData* getArrayData(T args)
            {
                unsigned int num_dimensions = getNDims(args);
                if(num_dimensions > 0)
                {
                    ArrayData* data = new ArrayData;
                    data -> num_dimensions = num_dimensions;
                    data->dimensions = new unsigned int [num_dimensions];
                    inputDims(*args,data,sizeof(*args));
                    return data;
                };
                return NULL;
            };
        };
    }
#endif
