
#ifndef HASHMAP_HPP
  #define HASHMAP_HPP
  #include "logger.h"
  #include "datatypes.h"
  #include "hashmap.h"
  #include <limits.h>
  namespace HashMap
  {
    template<typename T>
    struct HM_ENTRY
    {
      char* key;
      T value;
      HM_ENTRY<T>* next;

    };

    template<typename T>
    struct HMap
    {
      HM_ENTRY<T> **entries;
    };

    template<typename MEMBER, typename ARG>
    void updateValue(HM_ENTRY<MEMBER>* entry, ARG value)
    {
      *(entry->value)=value;
    };

    template<typename MEMBER, typename ARG>
    void updateValue(HM_ENTRY<MEMBER>* entry, const char* value)
    {
      strcpy(entry->value,value);
    };
    template<typename MEMBER>
    void nullValue(HM_ENTRY<char*>* entry)
    {
      *(entry->value) = NULL;
    };

    template<typename MEMBER>
    void nullValue(HM_ENTRY<MEMBER>* entry)
    {
      *(entry->value) = NAN;
    };
    template<typename T>
    HMap<T>* init()
    {
      HMap<T>* htbl = new HMap<T>; //assign memory pointer location for this datatype
      htbl->entries = new HM_ENTRY<T>* [sizeof(HM_ENTRY<T>)*TABLE_SIZE];//malloc(sizeof(HM_ENTRY) * TABLE_SIZE);
      for (int i = 0; i < TABLE_SIZE; i++)
      {
        htbl->entries[i] = NULL;
      }
      return htbl;
    };

    template<typename MEMBER, typename ARG, typename BASE>
    HM_ENTRY<MEMBER>* allocEntry(const char* key, ARG value)
    {
      HM_ENTRY<MEMBER>* entry = new HM_ENTRY<MEMBER>; //malloc(sizeof(HM_ENTRY+1);
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
    void setEntry(HMap<MEMBER> *htbl, const char *key, ARG value)
    {
      unsigned int slot = hash(key);
      HM_ENTRY<MEMBER>* entry = htbl->entries[slot];
      if (entry == NULL)
      {
        htbl->entries[slot] = allocEntry<MEMBER,ARG,BASE>(key,value);
        return ;
      }
      HM_ENTRY<MEMBER> *prev;
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

    template <typename T>
    int removeEntry(HMap<T> *htbl, const char *key)
    {
      unsigned int slot = hash(key);
      HM_ENTRY<T>* entry = htbl->entries[slot];
      if (entry == NULL)
      {
        return 1;
      }
      HM_ENTRY<T>* prev = NULL;
      HM_ENTRY<T>* next = NULL;
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

    template <typename T>
    int prune(HMap<T>** htbl_ptr)
    {
      HMap<T>* htbl = *htbl_ptr;
      for (int i = 0; i < TABLE_SIZE; i++)
      {
        HM_ENTRY<T>* entry = htbl->entries[i];
        if (entry == NULL)
        {
          continue;
        }
        HM_ENTRY<T> *prev;
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
    
    template <typename T>
    HM_ENTRY<T>*  getEntry(HMap<T> *htbl, const char *key)
    {
      unsigned int slot = hash(key);
      HM_ENTRY<T>* entry = htbl->entries[slot];
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

    template <typename T>
    void printEntries(HMap<T> *htbl)
    {
      const char key_str[]= "Key: ";
      const char val_str[] = "\nValue: ";
      unsigned int ksize = strlen(key_str);
      unsigned int vsize = strlen(val_str);
      unsigned long int size;
      for (int i = 0; i < TABLE_SIZE; i++)
      {
        HM_ENTRY<T>* entry = htbl->entries[i];
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
  
#endif