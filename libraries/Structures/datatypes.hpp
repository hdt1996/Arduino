
#ifndef DATATYPE_HPP
    #define DATATYPE_HPP
    namespace Datatypes
    {

        template <typename T>
        bool checkForString(T value)
        {
            char* strings[]={const_char_pstr,char_pstr};
            for(int i = 0; i < sizeof(strings)/sizeof(strings[0]);i++)
            {
                if(strcmp(strings[i],get(value))== 0)
                {
                    return true;
                }
            };
            return false;
        };

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

            ///////////////////////////////////////////// Data Class for MultiDimensional Data ///////////////////////////////////////////
            template <typename BASE, typename ARG>
            MULTI<BASE,ARG>::MULTI(ARG value, const char* type_name = NULL, bool detect = false)
            {
                Serial.println("Constructing MULTI Class...");
                Template::Pointers::PointerUnit*  pointer_data = Template::Pointers::getNDimsbyType<ARG>();
                pointer_data->test();
                //Template::Pointers::PointerUnit*  pointer_data = Template::Pointers::getNDimsbyType<ARG>();
                //pointer_data->extract();
                //Serial.println("My struct data: ");
                //typedef typename (*pointer_data).PUTYPE mytype;
                //Serial.print((pointer_data->msg));

                //Serial.println(Template::Arrays::isArray(test_ptr));
                //BASE** tp1 = test_ptr;
            };

            template <typename BASE, typename ARG>
            MULTI<BASE,ARG>::MULTI(ARG value, const char* type_name = NULL, unsigned int num_dimensions = 1, ... )
            {
                value_ptr = Container::init<BASE>(value);
                num_dimensions = num_dimensions;
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
            };


            template <typename BASE, typename ARG>
            void MULTI<BASE,ARG>::update(ARG new_value)
            {
                free(value_ptr); 
                value_ptr = Container::update<BASE>(new_value);
            };

            template <typename BASE, typename ARG>
            char* MULTI<BASE,ARG>::valueToString()
            {
                return Datatypes::toCharArray(this->value());
            };

            template <typename BASE, typename ARG>
            BASE* MULTI<BASE,ARG>::getPointer()
            {
                return value_ptr;
            };
            template <typename BASE, typename ARG>
            BASE MULTI<BASE,ARG>::value()
            {
                return Container::value<BASE>(value_ptr);
            };

            template <typename BASE, typename ARG>
            char* MULTI<BASE,ARG>::type()
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
        }

    };
#endif