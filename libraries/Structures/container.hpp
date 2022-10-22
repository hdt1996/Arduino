
#ifndef CONTAINER_HPP
    #define CONTAINER_HPP
        #include "datatypes.h"
        #include "templates.h"
        #include "container.h"
        namespace Container
        {
            ///////////////////////////////// Container template functions ///////////////////////////////////
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
            BASE* init(BASE value)
            {
                BASE* val_ptr = new BASE;
                *val_ptr = value;
                return val_ptr;
            };

            template<typename BASE>
            char* init(const char* value)
            {
                char* val_ptr = new char [strlen(value)+1];
                strcpy(val_ptr, value);
                return val_ptr;
            };

            template<typename BASE>
            char* init(char* value)
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

            //////////////////////////////////// MULTI value_ptr is POINTER ///////////////////////////////////////////

            template <typename BASE, typename ARG, unsigned int ND>
            MULTI<BASE,ARG,ND>::MULTI(ARG value, const char* type_name = NULL, bool = true) 
            {
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
                        Serial.println("Current DIM:");
                        Serial.println(dimensions[i]);
                    };
                    data->prune(data);
                    Serial.println();
                    Template::Arrays::allocPointer<heap_type>(&value_ptr, dimensions);
                    Template::Arrays::setPointer<heap_type, ARG>(&value_ptr, value, dimensions);
                    Serial.println();
                    Serial.println("Allocated and Set Values");
                    Serial.print(value_ptr[0][0][0][0]);
                    Serial.print(" ");
                    Serial.print(value_ptr[0][0][0][1]);
                    Serial.print(" ");
                    Serial.print(value_ptr[0][0][0][2]);
                    Serial.println();

                    Serial.print(value_ptr[1][0][0][0]);
                    Serial.print(" ");
                    Serial.print(value_ptr[1][0][0][1]);
                    Serial.print(" ");
                    Serial.print(value_ptr[1][0][0][2]);
                    Serial.println();
                    
                    Serial.print(value_ptr[2][0][0][0]);
                    Serial.print(" ");
                    Serial.print(value_ptr[2][0][0][1]);
                    Serial.print(" ");
                    Serial.print(value_ptr[2][0][0][2]);
                    Serial.println();
                };

            };
            template <typename BASE, typename ARG, unsigned int ND>
            MULTI<BASE,ARG,ND>::MULTI(ARG value, const char* type_name = NULL, ... ) 
            {
                Serial.println("MULTI-Type Pointer ------------ Constructing...");
                //Array Section
                /*
                    unsigned int num_dimensions  = Template::Arrays::getNDimsbyType<ARG>();
                    value_ptr = Container::init<BASE>(value);
                    if(type_name == NULL)
                    {
                        type_ptr = Datatypes::get(value);
                    }
                    else
                    {
                        type_ptr = new char [strlen(type_name)+1];
                        strcpy(type_ptr, type_name);
                    }

                    dimensions = new unsigned int [num_dimensions];
                    va_list dims;
                    va_start(dims, num_dimensions);
                    unsigned int curr_dim;
                    for(unsigned int n = 0; n < num_dimensions; n++)
                    {   
                        dimensions[n]=va_arg(dims, unsigned int);
                    };
                    va_end(dims);
                */
            };

            template <typename BASE, typename ARG, unsigned int ND>
            void MULTI<BASE,ARG,ND>::update(ARG new_value)
            {
                free(value_ptr); 
                value_ptr = Container::update<BASE>(new_value);
            };

            template <typename BASE, typename ARG, unsigned int ND>
            char* MULTI<BASE,ARG,ND>::valueToString()
            {
                return Datatypes::toCharArray(this->value());
            };

             template <typename BASE, typename ARG, unsigned int ND>
            BASE* MULTI<BASE,ARG,ND>::getPointer()
            {
                return value_ptr;
            };
            template <typename BASE, typename ARG, unsigned int ND>
            BASE MULTI<BASE,ARG,ND>::value()
            {
                return Container::value<BASE>(value_ptr);
            };

            template <typename BASE, typename ARG, unsigned int ND>
            char* MULTI<BASE,ARG,ND>::type()
            {
                return type_ptr;
            };

            /////////////////////////////////////// Class template without N --> Contains only singular Data ////////////////////////////////////

            template <typename ARG, typename BASE>
            SINGLE<ARG, BASE>::SINGLE(ARG value)
            {
                value_ptr = Container::init<BASE>(value);
                type_ptr = Datatypes::get(value);
            };

            template <typename ARG, typename BASE>
            void SINGLE<ARG,BASE>::update(ARG new_value)
            {
                free(value_ptr); 
                value_ptr = Container::update<BASE>(new_value);
            };

            template <typename ARG, typename BASE>
            char* SINGLE<ARG,BASE>::valueToString()
            {
                return Datatypes::toCharArray(this->value());
            };

            template <typename ARG, typename BASE>
            BASE* SINGLE<ARG,BASE>::getPointer()
            {
                return value_ptr;
            };
            template <typename ARG, typename BASE>
            BASE SINGLE<ARG,BASE>::value()
            {
                return Container::value<BASE>(value_ptr);
            };

            template <typename ARG, typename BASE>
            char* SINGLE<ARG,BASE>::type()
            {
                return type_ptr;
            };
        };
#endif