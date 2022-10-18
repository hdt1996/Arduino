
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
      template<typename BASE>
      struct Entry
      {
        char* key;
        BASE* value;
        Entry<BASE>* next;

      };

      template<typename BASE>
      struct Map
      {
        Entry<BASE> **entries;
      };

      template<typename ARG, typename BASE>
      void updateValue(Entry<BASE>* entry, ARG value)
      {
        *(entry->value)=value;
      };

      template<typename ARG, typename BASE>
      void updateValue(Entry<BASE>* entry, const char* value)
      {
        strcpy(entry->value,value);
      };
      

      template<typename BASE>
      Map<BASE>* init()
      {
        Map<BASE>* htbl = new Map<BASE>; //assign memory pointer location for this datatype
        htbl->entries = new Entry<BASE>* [sizeof(Entry<BASE>)*TABLE_SIZE];//malloc(sizeof(Entry) * TABLE_SIZE);
        for (int i = 0; i < TABLE_SIZE; i++)
        {
          htbl->entries[i] = NULL;
        }
        return htbl;
      };

      template<typename ARG, typename BASE>
      Entry<BASE>* allocEntry(const char* key, ARG value)
      {
        Entry<BASE>* entry = new Entry<BASE>; //malloc(sizeof(Entry+1);
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
        updateValue<ARG, BASE>(entry, value);
        entry->next = NULL;
        return entry;
      };

      template<typename ARG, typename BASE>
      void setEntry(Map<BASE> *htbl, const char *key, ARG value)
      {
        unsigned int slot = hash(key);
        Entry<BASE>* entry = htbl->entries[slot];
        if (entry == NULL)
        {
          htbl->entries[slot] = allocEntry<ARG,BASE>(key,value);
          return ;
        }
        Entry<BASE> *prev;
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

            updateValue<ARG, BASE>(entry, value);
            return ;
          }
          prev = entry;
          entry = prev->next;
        }
        prev->next = allocEntry<ARG,BASE>(key,value);
      };

      template <typename BASE>
      int removeEntry(Map<BASE> *htbl, const char *key)
      {
        unsigned int slot = hash(key);
        Entry<BASE>* entry = htbl->entries[slot];
        if (entry == NULL)
        {
          return 1;
        }
        Entry<BASE>* prev = NULL;
        Entry<BASE>* next = NULL;
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
              //Serial.println("FREED CONDITION 1");
              htbl->entries[slot]=entry->next;
              free(entry);
              return 0;
            }
            if(prev != NULL && entry->next != NULL) //WE ARE IN THE MIDDLE of nodes
            {
              //Serial.println("FREED CONDITION 2");
              prev->next = entry->next;
              free(entry);
              return 0;
            }
            if(prev!=NULL && entry->next == NULL)
            {
              //Serial.println("FREED CONDITION 3");
              free(entry);
              prev->next = NULL;
              return 0;
            }
            //Serial.println("FREED CONDITION 4");
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

      template <typename BASE>
      int prune(Map<BASE>** htbl_ptr)
      {
        Map<BASE>* htbl = *htbl_ptr;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
          Entry<BASE>* entry = htbl->entries[i];
          if (entry == NULL)
          {
            continue;
          }
          Entry<BASE> *prev;
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
      
      template <typename BASE>
      Entry<BASE>*  getEntry(Map<BASE> *htbl, const char *key)
      {
        unsigned int slot = hash(key);
        Entry<BASE>* entry = htbl->entries[slot];
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

      template <typename BASE>
      void printEntries(Map<BASE> *htbl)
      {
        const char key_str[]= "Key: ";
        const char val_str[] = "\nValue: ";
        unsigned int ksize = strlen(key_str);
        unsigned int vsize = strlen(val_str);
        unsigned long int size;
        for (int i = 0; i < TABLE_SIZE; i++)
        {
          Entry<BASE>* entry = htbl->entries[i];
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

   template <typename ARG, typename BASE>
    unsigned int Dictionary<ARG, BASE>::hash(const char *key)
    {
      return HashMap::hash(key);
    };

   template <typename ARG, typename BASE>
    HashMap::Map<BASE>* Dictionary<ARG, BASE>::init()
    {
      return HashMap::init<BASE>();
    };

   template <typename ARG, typename BASE>
    HashMap::Entry<BASE>* Dictionary<ARG, BASE>::allocEntry(const char key, ARG value)
    {
      return HashMap::allocEntry<ARG, BASE>(key, value);
    };

   template <typename ARG, typename BASE>
    Dictionary<ARG, BASE>::Dictionary()
    {
      hashtable=this->init();
    };

   template <typename ARG, typename BASE>
    void Dictionary<ARG, BASE>::updateValue(HashMap::Entry<BASE>* entry, ARG value)
    {
      HashMap::updateValue<ARG, BASE>(entry, value);
    };

   template <typename ARG, typename BASE>
    void Dictionary<ARG, BASE>::setEntry(const char* key, ARG value)
    {
      HashMap::setEntry<ARG,BASE>(hashtable, key, value);
    };

   template <typename ARG, typename BASE>
    HashMap::Entry<BASE>* Dictionary<ARG, BASE>::getEntry(const char* key)
    {
      return HashMap::getEntry<BASE>(hashtable, key);
    };

   template <typename ARG, typename BASE>
    int Dictionary<ARG, BASE>::prune()
    {
      return HashMap::prune<BASE>(&hashtable);
    };

   template <typename ARG, typename BASE>
    int Dictionary<ARG, BASE>::removeEntry(const char *key)
    {
      return HashMap::removeEntry<BASE>(hashtable, key);
    };
    
   template <typename ARG, typename BASE>
    void Dictionary<ARG, BASE>::printEntries()
    {
      HashMap::printEntries<BASE>(hashtable);
    };
};
  
  
#endif