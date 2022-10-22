#include <Arduino.h>
#ifndef CONTAINER
    #define CONTAINER
        namespace Container
        {
            class Unit
            {
                public:
                    Unit(){};
            };
            template <typename BASE>
            BASE* update(BASE new_value);

            template <typename BASE>
            char* update(const char* new_value);

            template <typename BASE>
            char* update(char* new_value);

            template <typename BASE>
            BASE* init(BASE value);

            template <typename BASE>
            char* init(const char* value);

            template <typename BASE>
            BASE value(BASE* val_ptr);

            template <typename BASE, typename ARG, unsigned int ND> //We need ND to value_ptr type for storing converted pointer or pointer to array
            class MULTI: public Unit
            {
                private:
                    typedef typename Template::Modify::makePointer<BASE,ND>::type heap_type;
                    unsigned int num_dimensions = Template::Arrays::getNDimsbyType<ARG>();
                    heap_type value_ptr;
                    const char* type_ptr;
                    unsigned int* dimensions = new unsigned int[ND];

                public: // Constructor takes Pointer or ARRAY to Pointer
                    MULTI(ARG value, const char* type_name = NULL, bool = true);
                    MULTI(ARG value, const char* type_name = NULL, ...); //Pointer as ARG requires dimensions
                    MULTI(){};
                    void update(ARG new_value);
                    char* valueToString();
                    BASE* getPointer();
                    BASE value();
                    char* type();
            };

            template <typename ARG, typename BASE>
            class SINGLE: public Unit
            {
                private:
                    BASE* value_ptr;
                    char* type_ptr;
                public:
                    SINGLE(ARG value);
                    SINGLE(){};
                    void update(ARG new_value);
                    char* valueToString();
                    BASE* getPointer();
                    BASE value();
                    char* type();
            };
            
        };
    #include "container.hpp"
#endif
