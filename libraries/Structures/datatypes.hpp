
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

            ///////////////////////////////////////////// Data Class ///////////////////////////////////////////
            template <typename MEMBER, typename ARG, typename BASE>
            Data<MEMBER, ARG, BASE>::Data(ARG value)
            {
                value_ptr = Container::init<BASE>(value);
                type = Datatypes::get(value);
            };

            template <typename MEMBER, typename ARG, typename BASE>
            void Data<MEMBER, ARG, BASE>::update(ARG new_value)
            {
                free(value_ptr); 
                value_ptr = Container::update<BASE>(new_value);
            };

            template <typename MEMBER, typename ARG, typename BASE>
            char* Data<MEMBER, ARG, BASE>::valueToString()
            {
                return Datatypes::toCharArray(this->value());
            };

            template <typename MEMBER, typename ARG, typename BASE>
            MEMBER Data<MEMBER, ARG, BASE>::getPointer()
            {
                return value_ptr;
            };
            template <typename MEMBER, typename ARG, typename BASE>
            BASE Data<MEMBER, ARG, BASE>::value()
            {
                return Container::value<BASE>(value_ptr);
            };
        }

    };
#endif