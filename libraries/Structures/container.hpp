
#ifndef CONTAINER_HPP
    #define CONTAINER_HPP
        #include "datatypes.h"
        #include "templates.h"
        namespace Container
        {
            ///////////////////////////////// Container template functions ///////////////////////////////////
            namespace Single
            {
                template <typename BASE>
                BASE* update(BASE new_value)
                {
                    BASE* ptr = new BASE;
                    *ptr = new_value;
                    return ptr;
                };
            
                template <typename BASE>
                char* update(const char* new_value)
                {
                    char* str_ptr = new char [strlen(new_value)+1];
                    return str_ptr;
                };

                template <typename BASE>
                char* update(char* new_value)
                {
                    char* str_ptr = new char [strlen(new_value)+1];
                    return str_ptr;
                };

                template<typename BASE>
                BASE* assignValue(BASE value)
                {
                    BASE* val_ptr = new BASE;
                    *val_ptr = value;
                    return val_ptr;
                };

                template<typename BASE>
                char* assignValue(const char* value)
                {
                    char* val_ptr = new char [strlen(value)+1];
                    strcpy(val_ptr, value);
                    return val_ptr;
                };

                template<typename BASE>
                char* assignValue(char* value)
                {
                    char* val_ptr = new char [strlen(value)+1];
                    strcpy(val_ptr, value);
                    return val_ptr;
                };

                template <typename BASE>
                BASE value(BASE* val_ptr)
                {
                    return *val_ptr;
                };


                /////////////////////////////////////// Class template without N --> Contains only singular Data ////////////////////////////////////

                template <typename ARG, typename BASE>
                SINGLE<ARG, BASE>::SINGLE(ARG value)
                {
                    value_ptr = Single::assignValue<BASE>(value);
                    type_ptr = Datatypes::get(value);
                };

                template <typename ARG, typename BASE>
                void SINGLE<ARG,BASE>::update(ARG new_value)
                {
                    free(value_ptr); 
                    value_ptr = Single::update<BASE>(new_value);
                };

                template <typename ARG, typename BASE>
                char* SINGLE<ARG,BASE>::valueToString()
                {
                    return Datatypes::toCharArray(value_ptr);
                };

                template <typename ARG, typename BASE>
                BASE* SINGLE<ARG,BASE>::getPointer()
                {
                    return value_ptr;
                };
                template <typename ARG, typename BASE>
                BASE SINGLE<ARG,BASE>::value()
                {
                    return Single::value<BASE>(value_ptr);
                };

                template <typename ARG, typename BASE>
                char* SINGLE<ARG,BASE>::type()
                {
                    return type_ptr;
                };

                template <typename ARG, typename BASE>
                void SINGLE<ARG,BASE>::prune()
                {
                    delete value_ptr;
                };

                template <typename ARG, typename BASE>
                void SINGLE<ARG,BASE>::printValues()
                {
                    char* str = Datatypes::toCharArray(value_ptr);
                    Serial.println(str);
                    delete str;
                };
            };


            namespace Multiple
            {
                //////////////////////////////////// MULT_UCM value_ptr is POINTER ///////////////////////////////////////////

                template <typename BASE, typename ARG, unsigned int ND>
                MULT_UCM<BASE,ARG,ND>::MULT_UCM(ARG value, const char* type_name = NULL, bool = true) 
                {
                    Serial.println("ARRAY CONSTRUCTOR");
                    if(num_dimensions == 0)
                    {
                        Serial.println("Please pass in array with at least one dimension as first Constructor ARG!");
                        return;
                    }
                    
                    if(type_name == NULL)
                    {
                        type_ptr = Datatypes::get(value);
                    }
                    else
                    {
                        type_ptr = new char [strlen(type_name)+1];
                        strcpy(type_ptr, type_name);
                    };

                    Template::Structs::ArrayData* data = Template::Arrays::getArrayData(value);
                    for(int i = 0; i < data->num_dimensions; i++)
                    {
                        dimensions[i] = data->dimensions[i];
                    };
                    data->prune(data);
                    Template::Arrays::allocPointers<heap_type>(&value_ptr, dimensions);
                    Template::Arrays::alloc_pointers = 0;
                    Template::Arrays::setPointers<heap_type, ARG>(&value_ptr, value, dimensions);
                    
                };

                template <typename BASE, typename ARG, unsigned int ND>
                MULT_UCM<BASE,ARG,ND>::MULT_UCM(ARG value, const char* type_name = NULL, ... ) 
                {                
                    Serial.println("POINTER CONSTRUCTOR");
                    if(type_name == NULL)
                    {
                        type_ptr = Datatypes::get(value);
                    }
                    else
                    {
                        type_ptr = new char [strlen(type_name)+1];
                        strcpy(type_ptr, type_name);
                    };

                    va_list dims;
                    va_start(dims, num_dimensions);
                    unsigned int curr_dim;
                    for(unsigned int n = 0; n < num_dimensions; n++)
                    {   
                        dimensions[n]=va_arg(dims, unsigned int);
                    };
                    va_end(dims);
                    Template::Arrays::allocPointers<heap_type>(&value_ptr, dimensions);
                    Template::Arrays::alloc_pointers = 0;
                    Template::Arrays::setPointers<heap_type, ARG>(&value_ptr, value, dimensions);
                };

                template <typename BASE, typename ARG, unsigned int ND>
                void MULT_UCM<BASE,ARG,ND>::update(ARG new_value)
                {
                    //free(value_ptr); 
                    //value_ptr = Container::update<BASE>(new_value);
                };

                template <typename BASE, typename ARG, unsigned int ND>
                char* MULT_UCM<BASE,ARG,ND>::valueToString()
                {
                    return Datatypes::toCharArray(this->value());
                };

                template <typename BASE, typename ARG, unsigned int ND>
                BASE* MULT_UCM<BASE,ARG,ND>::getPointer()
                {
                    return value_ptr;
                };
                template <typename BASE, typename ARG, unsigned int ND>
                BASE MULT_UCM<BASE,ARG,ND>::value()
                {
                    //return Container::value<BASE>(value_ptr);
                };

                template <typename BASE, typename ARG, unsigned int ND>
                char* MULT_UCM<BASE,ARG,ND>::type()
                {
                    return type_ptr;
                };

                template <typename BASE, typename ARG, unsigned int ND>
                void MULT_UCM<BASE,ARG,ND>::prune()
                {
                    return Template::Arrays::freePointers<heap_type>(&value_ptr,dimensions);
                }; 

                template <typename BASE, typename ARG, unsigned int ND>
                void MULT_UCM<BASE,ARG,ND>::printValues(unsigned int col_size = 10)
                {
                    Serial.println();
                    unsigned int* indices = new unsigned int [num_dimensions+1];
                    const char* ind_str = "Idx";
                    int ind_size = strlen(ind_str);
                    unsigned int ind_num_spaces = (unsigned int)max(((int)num_dimensions-1)*2-ind_size,0);
                    unsigned int bord_length = ind_size;
                    Serial.write(ind_str); //length of 5 for OUTPUT not actual memory length
                    for(int i = 0; i < ind_num_spaces; i++)
                    {
                        Serial.write(' ');
                        bord_length++;
                    };
                    Serial.write('|');
                    bord_length++;
                    char* i_str;
                    for(int i = 0; i < dimensions[num_dimensions-1]; i++)
                    {
                        for(int i = 0; i < col_size/2; i++)
                        {
                            Serial.write(' ');
                            bord_length++;
                        };
                        i_str = Datatypes::toCharArray(i);
                        Serial.write('C');
                        Serial.write(i_str);
                        bord_length++;
                        bord_length+=strlen(i_str);
                        delete i_str;

                        for(int i = 0; i < col_size/2; i++)
                        {
                            Serial.write(' ');
                            bord_length++;
                        };
                        if((col_size/2)*2 < col_size)
                        {
                            Serial.write(' ');
                            bord_length++;
                        };
                        Serial.write('|');
                        bord_length++;
                    };
                    Serial.println();
                    for(int i = 0; i < bord_length; i++)
                    {
                        Serial.write('-');
                    };
                    Serial.println();
                    Template::Arrays::printPTRVals<heap_type>(&value_ptr, num_dimensions, dimensions, indices,col_size);
                    delete indices;
                }; 


                /////////////////////////////////////////// MULTI CM /////////////////////////////////////////////////////////////////////////////////


                template <typename BASE, typename ARG, typename CTG>
                MULT_CM<BASE,ARG,CTG>::MULT_CM(ARG value, const char* type_name = NULL, bool = true) 
                {
                    Serial.println("ARRAY CONSTRUCTOR");
                    if(num_dimensions == 0)
                    {
                        Serial.println("Please pass in array with at least one dimension as first Constructor ARG!");
                    }
                    else
                    {
                        Template::Structs::ArrayData* data = Template::Arrays::getArrayData(value);
                        for(int i = 0; i < data->num_dimensions; i++)
                        {
                            dimensions[i] = data->dimensions[i];
                            elements = elements*dimensions[i];
                        };
                        data->prune(data);
                        
                        memcpy(value_ptr, value,elements*(sizeof(BASE))); //need address of array as first or double(*)[][][] // double(*)[3][3][3]
                    };
                };

                template <typename BASE, typename ARG, typename CTG>
                MULT_CM<BASE,ARG,CTG>::MULT_CM(ARG value, const char* type_name = NULL, ... ) 
                {                

                    Serial.println("POINTER CONSTRUCTOR");
                    if(type_name == NULL)
                    {
                        type_ptr = Datatypes::get(value);
                    }
                    else
                    {
                        type_ptr = new char [strlen(type_name)+1];
                        strcpy(type_ptr, type_name);
                    };

                    va_list dims;
                    va_start(dims, num_dimensions);
                    unsigned int curr_dim;
                    for(unsigned int n = 0; n < num_dimensions; n++)
                    {   
                        dimensions[n]=va_arg(dims, unsigned int);
                    };
                    va_end(dims);
                    for(int i = 0; i < dimensions[0];i++)
                    {
                        //double (*)[3][3]   double(*)[3][3][3]
                        Template::Arrays::setArrays<val_type>(value_ptr+i,*(value)+i, num_dimensions, dimensions);
                    };
                };

                template <typename BASE, typename ARG, typename CTG>
                void MULT_CM<BASE,ARG,CTG>::update(ARG new_value)
                {
                    //free(value_ptr); 
                    //value_ptr = Container::update<BASE>(new_value);
                };

                template <typename BASE, typename ARG, typename CTG>
                char* MULT_CM<BASE,ARG,CTG>::valueToString()
                {
                    return Datatypes::toCharArray(this->value());
                };

                template <typename BASE, typename ARG, typename CTG>
                BASE* MULT_CM<BASE,ARG,CTG>::getPointer()
                {
                    return value_ptr;
                };
                template <typename BASE, typename ARG, typename CTG>
                BASE MULT_CM<BASE,ARG,CTG>::value()
                {
                    //return Container::value<BASE>(value_ptr);
                };

                template <typename BASE, typename ARG, typename CTG>
                char* MULT_CM<BASE,ARG,CTG>::type()
                {
                    return type_ptr;
                };

                template <typename BASE, typename ARG, typename CTG>
                void MULT_CM<BASE,ARG,CTG>::prune()
                {
                    //return Template::Arrays::freePointers<heap_type>(&value_ptr,dimensions);
                }; 

                template <typename BASE, typename ARG, typename CTG>
                void MULT_CM<BASE,ARG,CTG>::printValues(unsigned int col_size = 10)
                {
                    Serial.println();
                    unsigned int* indices = new unsigned int [num_dimensions+1];
                    const char* ind_str = "Idx";
                    int ind_size = strlen(ind_str);
                    unsigned int ind_num_spaces = (unsigned int)max(((int)num_dimensions-1)*2-ind_size,0);
                    unsigned int bord_length = ind_size;
                    Serial.write(ind_str); //length of 5 for OUTPUT not actual memory length
                    for(int i = 0; i < ind_num_spaces; i++)
                    {
                        Serial.write(' ');
                        bord_length++;
                    };
                    Serial.write('|');
                    bord_length++;
                    char* i_str;
                    for(int i = 0; i < dimensions[num_dimensions- 1]; i++)
                    {
                        for(int i = 0; i < col_size/2; i++)
                        {
                            Serial.write(' ');
                            bord_length++;
                        };
                        i_str = Datatypes::toCharArray(i);
                        Serial.write('C');
                        Serial.write(i_str);
                        bord_length++;
                        bord_length+=strlen(i_str);
                        delete i_str;

                        for(int i = 0; i < col_size/2; i++)
                        {
                            Serial.write(' ');
                            bord_length++;
                        };
                        if((col_size/2)*2 < col_size)
                        {
                            Serial.write(' ');
                            bord_length++;
                        };
                        Serial.write('|');
                        bord_length++;
                    };
                    Serial.println();
                    for(int i = 0; i < bord_length; i++)
                    {
                        Serial.write('-');
                    };
                    Serial.println();
                    for(int i = 0; i < dimensions[0];i++)
                    {
                        indices[0] = i;
                        Template::Arrays::printARRVals<val_type>(value_ptr+i, num_dimensions, dimensions, indices+1,col_size);
                    };
                    delete indices;
                }; 
            };


        };
#endif