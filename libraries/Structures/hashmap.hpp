
#ifndef HASHMAP_HPP
  #define HASHMAP_HPP
  #include "logger.h"
  #include "datatypes.h"
  #include "hashmap.h"
  #include <limits.h>
  namespace Structures
  {
    namespace HashMap
    {
      template<typename MEMBER>
      struct Entry
      {
        char* key;
        MEMBER value;
        Entry<MEMBER>* next;

      };

      template<typename MEMBER>
      struct Map
      {
        Entry<MEMBER> **entries;
      };

      template<typename MEMBER, typename ARG>
      void updateValue(Entry<MEMBER>* entry, ARG value)
      {
        *(entry->value)=value;
      };

      template<typename MEMBER, typename ARG>
      void updateValue(Entry<MEMBER>* entry, const char* value)
      {
        strcpy(entry->value,value);
      };
      

      template<typename MEMBER>
      Map<MEMBER>* init()
      {
        Map<MEMBER>* htbl = new Map<MEMBER>; //assign memory pointer location for this datatype
        htbl->entries = new Entry<MEMBER>* [sizeof(Entry<MEMBER>)*TABLE_SIZE];//malloc(sizeof(Entry) * TABLE_SIZE);
        for (int i = 0; i < TABLE_SIZE; i++)
        {
          htbl->entries[i] = NULL;
        }
        return htbl;
      };

      template<typename MEMBER, typename ARG, typename BASE>
      Entry<MEMBER>* allocEntry(const char* key, ARG value)
      {
        Entry<MEMBER>* entry = new Entry<MEMBER>; //malloc(sizeof(Entry+1);
        entry->key = new char [strlen(key)+1];
        if(Datatypes::checkForString<ARG>(value))
        {
          entry->value = new BASE [strlen(value) + 1];
        }
        else
        {
          entry->value = new BASE;
        }
        strcpy(entry->key, key);
        updateValue<MEMBER, ARG>(entry, value);
        entry->next = NULL;
        return entry;
      };

      template<typename MEMBER, typename ARG, typename BASE>
      void setEntry(Map<MEMBER> *htbl, const char *key, ARG value)
      {
        unsigned int slot = hash(key);
        Entry<MEMBER>* entry = htbl->entries[slot];
        if (entry == NULL)
        {
          htbl->entries[slot] = allocEntry<MEMBER,ARG,BASE>(key,value);
          return ;
        }
        Entry<MEMBER> *prev;
        while (entry != NULL)
        {
          if(strcmp(entry->key, key) == 0)
          {
            free(entry->value);
            if(Datatypes::checkForString<ARG>(value))
            {
              entry->value = new BASE [strlen(value) + 1];
            }
            else
            {
              entry->value = new BASE;
            }

            updateValue<MEMBER, ARG>(entry, value);
            return ;
          }
          prev = entry;
          entry = prev->next;
        }
        prev->next = allocEntry<MEMBER,ARG,BASE>(key,value);
      };

      template <typename MEMBER>
      int removeEntry(Map<MEMBER> *htbl, const char *key)
      {
        unsigned int slot = hash(key);
        Entry<MEMBER>* entry = htbl->entries[slot];
        if (entry == NULL)
        {
          return 1;
        }
        Entry<MEMBER>* prev = NULL;
        Entry<MEMBER>* next = NULL;
        unsigned long int curr_i = 0;
        while (entry != NULL) //hash key collision
        {
          if (strcmp(entry->key, key) == 0) 
          {
            //free(entry->value);
            //free(entry->key);
            free(entry->value);
            free(entry->key);
            if(prev == NULL && entry->next != NULL) //prev will only be NULL on FIRST ITERATION
            {
              Serial.println("FREED CONDITION 1");
              htbl->entries[slot]=entry->next;
              free(entry);
              return 0;
            }
            if(prev != NULL && entry->next != NULL) //WE ARE IN THE MIDDLE of nodes
            {
              Serial.println("FREED CONDITION 2");
              prev->next = entry->next;
              free(entry);
              return 0;
            }
            if(prev!=NULL && entry->next == NULL)
            {
              Serial.println("FREED CONDITION 3");
              free(entry);
              prev->next = NULL;
              return 0;
            }
            Serial.println("FREED CONDITION 4");
            free(entry);
            htbl->entries[slot]=NULL;
            return 0;
          }
          prev = entry;
          entry = entry->next;
          curr_i++;
        }
        return 1;
      };

      template <typename MEMBER>
      int prune(Map<MEMBER>** htbl_ptr)
      {
        Map<MEMBER>* htbl = *htbl_ptr;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
          Entry<MEMBER>* entry = htbl->entries[i];
          if (entry == NULL)
          {
            continue;
          }
          Entry<MEMBER> *prev;
          for(;;)
          {
            free(entry->key);
            free(entry->value);
            if (entry ->next == NULL)
            {
              free(entry);
              break;
            }
            prev = entry;
            entry = prev->next;
            free(prev);
          };
        };
        free(htbl->entries);
        free(htbl);
        return 0;
      };
      
      template <typename MEMBER>
      Entry<MEMBER>*  getEntry(Map<MEMBER> *htbl, const char *key)
      {
        unsigned int slot = hash(key);
        Entry<MEMBER>* entry = htbl->entries[slot];
        if (entry == NULL)
        {
          return NULL;
        };
        while (entry != NULL)
        {
          if (strcmp(entry->key, key) == 0)
          {
            return entry;
          }
          entry = entry->next;
        };
        return NULL;
      };

      template <typename MEMBER>
      void printEntries(Map<MEMBER> *htbl)
      {
        const char key_str[]= "Key: ";
        const char val_str[] = "\nValue: ";
        unsigned int ksize = strlen(key_str);
        unsigned int vsize = strlen(val_str);
        unsigned long int size;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
          Entry<MEMBER>* entry = htbl->entries[i];
          if (entry == NULL)
          {
            continue;
          }
          for(;;)
          {
            char* val_ptr = Datatypes::toCharArray(entry->value);
            size=strlen(entry->key)+strlen(val_ptr) + ksize + vsize + 1;
            char msg [size] = "";
            strcat(msg,key_str);
            strcat(msg, entry->key);
            strcat(msg, val_str);
            strcat(msg, val_ptr);
            Serial.println(msg);
            delete val_ptr;
            if (entry ->next == NULL)
            {
              break;
            }
            entry = entry->next;
          }
        } 
      };
    };

    template <typename MEMBER, typename ARG, typename BASE>
    unsigned int Dictionary<MEMBER, ARG, BASE>::hash(const char *key)
    {
      return HashMap::hash(key);
    };

    template <typename MEMBER, typename ARG, typename BASE>
    HashMap::Map<MEMBER>* Dictionary<MEMBER, ARG, BASE>::init()
    {
      return HashMap::init<MEMBER>();
    };

    template <typename MEMBER, typename ARG, typename BASE>
    HashMap::Entry<MEMBER>* Dictionary<MEMBER, ARG, BASE>::allocEntry(const char key, ARG value)
    {
      return HashMap::allocEntry<MEMBER, ARG, BASE>(key, value);
    };

    template <typename MEMBER, typename ARG, typename BASE>
    Dictionary<MEMBER, ARG, BASE>::Dictionary()
    {
      hashtable=this->init();
    };

    template <typename MEMBER, typename ARG, typename BASE>
    void Dictionary<MEMBER, ARG, BASE>::updateValue(HashMap::Entry<MEMBER>* entry, ARG value)
    {
      HashMap::updateValue<MEMBER, ARG>(entry, value);
    };

    template <typename MEMBER, typename ARG, typename BASE>
    void Dictionary<MEMBER, ARG, BASE>::setEntry(const char* key, ARG value)
    {
      HashMap::setEntry<MEMBER,ARG,BASE>(hashtable, key, value);
    };

    template <typename MEMBER, typename ARG, typename BASE>
    HashMap::Entry<MEMBER>* Dictionary<MEMBER, ARG, BASE>::getEntry(const char* key)
    {
      return HashMap::getEntry<MEMBER>(hashtable, key);
    };

    template <typename MEMBER, typename ARG, typename BASE>
    int Dictionary<MEMBER, ARG, BASE>::prune()
    {
      return HashMap::prune<MEMBER>(&hashtable);
    };

    template <typename MEMBER, typename ARG, typename BASE>
    int Dictionary<MEMBER, ARG, BASE>::removeEntry(const char *key)
    {
      return HashMap::removeEntry<MEMBER>(hashtable, key);
    };
    
    template <typename MEMBER, typename ARG, typename BASE>
    void Dictionary<MEMBER, ARG, BASE>::printEntries()
    {
      HashMap::printEntries<MEMBER>(hashtable);
    };
};
  
  
#endif