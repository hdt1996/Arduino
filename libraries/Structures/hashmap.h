#include <Arduino.h>
#ifndef HASHMAP
    #define HASHMAP
    #define TABLE_SIZE 1
    namespace Structures
    {
        namespace HashMap
        {
            unsigned int hash(const char *key);

            template<typename BASE>
            struct Entry;

            template<typename BASE>
            struct Map;

            template<typename BASE>
            Map<BASE>* init();

            template<typename ARG, typename BASE>
            void updateValue(Entry<BASE>* entry, ARG value);

            template<typename ARG, typename BASE>
            void updateValue(Entry<BASE>* entry, const char* value);

            template<typename ARG, typename BASE>
            Entry<BASE>* allocEntry(const char key, ARG value);

            template<typename ARG, typename BASE>
            void setEntry(Map<BASE> *htbl, const char* key, ARG value);

            template<typename BASE>
            Entry<BASE>* getEntry(Map<BASE> *htbl, const char* key);

            template<typename BASE>
            void printEntries(Map<BASE> *htbl);

            template<typename BASE>
            int removeEntry(Map<BASE> *htbl, const char *key);

            template<typename BASE>
            int prune(Map<BASE>** htbl_ptr);
        };

        template <typename ARG, typename BASE>
        class Dictionary
        {
            private:
                unsigned int hash(const char *key);
                HashMap::Map<BASE>* init();
                HashMap::Entry<BASE>* allocEntry(const char key, ARG value);
                HashMap::Map<BASE>* hashtable;
            public:
                Dictionary();
                void updateValue(HashMap::Entry<BASE>* entry, ARG value);
                void setEntry(const char* key, ARG value);
                HashMap::Entry<BASE>* getEntry(const char* key);
                int prune();
                int removeEntry(const char *key);
                void printEntries();
        };
    };

    #include "hashmap.hpp"
#endif