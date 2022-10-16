#include <Arduino.h>
#ifndef HASHMAP
    #define HASHMAP
    #define TABLE_SIZE 10
    namespace HashMap
    {
        unsigned int hash(const char *key);

        template<typename T>
        struct HM_ENTRY;

        template<typename T>
        struct HMap;

        template<typename T>
        HMap<T>* init();

        template<typename MEMBER, typename ARG>
        void updateValue(HM_ENTRY<MEMBER>* entry, ARG value);

        template<typename MEMBER, typename ARG>
        void updateValue(HM_ENTRY<MEMBER>* entry, const char* value);

        template<typename MEMBER, typename ARG, typename BASE>
        HM_ENTRY<MEMBER>* allocEntry(const char key, ARG value);

        template<typename MEMBER, typename ARG, typename BASE>
        void setEntry(HMap<MEMBER> *htbl, const char* key, ARG value);

        template<typename T>
        HM_ENTRY<T>* getEntry(HMap<T> *htbl, const char* key);

        template<typename T>
        void printEntries(HMap<T> *htbl);

        template<typename T>
        int removeEntry(HMap<T> *htbl, const char *key);

        template<typename T>
        int prune(HMap<T>** htbl_ptr);
    };

    #include "hashmap.hpp"
#endif