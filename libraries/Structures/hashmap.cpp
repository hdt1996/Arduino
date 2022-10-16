#include "hashmap.h"

namespace Structures
{
  namespace HashMap
  {
    unsigned int hash(const char *key)
    {
      unsigned long int value = 0;
      unsigned int i = 0;
      unsigned int key_len = strlen(key);
      for (; i< key_len; ++i)
      {
        value = value * 37 + key[i];
      }
      value = value % TABLE_SIZE;
      return value;
    };
  }
};
