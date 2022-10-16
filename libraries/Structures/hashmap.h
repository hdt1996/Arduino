#include <Arduino.h>
#ifndef HASHMAP
    #define HASHMAP
    #define TABLE_SIZE 1
    namespace Structures
    {
        namespace HashMap
        {
            unsigned int hash(const char *key);

            template<typename MEMBER>
            struct Entry;

            template<typename MEMBER>
            struct Map;

            template<typename MEMBER>
            Map<MEMBER>* init();

            template<typename MEMBER, typename ARG>
            void updateValue(Entry<MEMBER>* entry, ARG value);

            template<typename MEMBER, typename ARG>
            void updateValue(Entry<MEMBER>* entry, const char* value);

            template<typename MEMBER, typename ARG, typename BASE>
            Entry<MEMBER>* allocEntry(const char key, ARG value);

            template<typename MEMBER, typename ARG, typename BASE>
            void setEntry(Map<MEMBER> *htbl, const char* key, ARG value);

            template<typename MEMBER>
            Entry<MEMBER>* getEntry(Map<MEMBER> *htbl, const char* key);

            template<typename MEMBER>
            void printEntries(Map<MEMBER> *htbl);

            template<typename MEMBER>
            int removeEntry(Map<MEMBER> *htbl, const char *key);

            template<typename MEMBER>
            int prune(Map<MEMBER>** htbl_ptr);
        };

        template <typename MEMBER, typename ARG, typename BASE>
        class Dictionary
        {
            private:
                unsigned int hash(const char *key);
                HashMap::Map<MEMBER>* init();
                HashMap::Entry<MEMBER>* allocEntry(const char key, ARG value);
                HashMap::Map<MEMBER>* hashtable;
            public:
                Dictionary();
                void updateValue(HashMap::Entry<MEMBER>* entry, ARG value);
                void setEntry(const char* key, ARG value);
                HashMap::Entry<MEMBER>* getEntry(const char* key);
                int prune();
                int removeEntry(const char *key);
                void printEntries();
        };
    };

    #include "hashmap.hpp"
#endif