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

            namespace Single
            {
                template <typename BASE>
                BASE* update(BASE new_value);

                template <typename BASE>
                char* update(const char* new_value);

                template <typename BASE>
                char* update(char* new_value);

                template <typename BASE>
                BASE* assignValue(BASE value);

                template <typename BASE>
                char* assignValue(const char* value);
                
                template <typename BASE>
                BASE value(BASE* val_ptr);

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
                        void prune();
                        void printValues();
                };
            };         


            namespace Multiple
            {
                template <typename BASE, typename ARG, unsigned int ND> //We need ND to value_ptr type for storing converted pointer or pointer to array
                class MULT_UCM: public Unit
                {
                    private:
                        typedef typename Template::Modify::addNPointers<BASE,ND>::type heap_type;
                        unsigned int num_dimensions = ND;
                        heap_type value_ptr;
                        const char* type_ptr;
                        unsigned int* dimensions = new unsigned int[ND];

                    public: // Constructor takes Pointer or ARRAY to Pointer
                        MULT_UCM(ARG value, const char* type_name = NULL, bool = true);
                        MULT_UCM(ARG value, const char* type_name = NULL, ...); //Pointer as ARG requires dimensions
                        MULT_UCM(){};
                        void update(ARG new_value);
                        char* valueToString();
                        BASE* getPointer();
                        BASE value();
                        char* type();
                        void prune();
                        void printValues(unsigned int col_size = 10);
                };

                template <typename BASE, typename ARG, typename CTG>
                class MULT_CM: public Unit
                {
                    private:
                        unsigned int num_dimensions = Template::Arrays::getNDimsbyType<CTG>();
                        typedef typename Template::Modify::lessPointer<CTG>::type ctg_type;
                        typedef typename Template::Modify::remove_dimension<CTG>::type val_type;
                        val_type value_ptr = new ctg_type;
                        const char* type_ptr;
                        unsigned int* dimensions = new unsigned int[num_dimensions];
                        unsigned int elements = 1;

                    public: // Constructor takes Pointer or ARRAY to Pointer
                        MULT_CM(ARG value, const char* type_name = NULL, bool = true);
                        MULT_CM(ARG value, const char* type_name = NULL, ...); //Pointer as ARG requires dimensions
                        MULT_CM(){};
                        void update(ARG new_value);
                        char* valueToString();
                        BASE* getPointer();
                        BASE value();
                        char* type();
                        void prune();
                        void printValues(unsigned int col_size = 10);
                };
            };


        };
    #include "container.hpp"
#endif
