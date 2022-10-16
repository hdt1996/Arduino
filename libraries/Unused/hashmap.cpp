#include "hashmap.h"

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
};
/*
template class HashMap::HMap<int*>;
template class HashMap::HMap<char*>;
//template class HashMap::HMap<char>;
//template class HashMap::HMap<float>;
//template class HashMap::HMap<double>;
//template HashMap::HMap<int>* HashMap::init<int>();
//template HashMap::HMap<float>* HashMap::init<float>();
//template HashMap::HMap<double>* HashMap::init<double>();
template HashMap::HMap<char*>* HashMap::init<char*>();
template HashMap::HMap<int*>* HashMap::init<int*>();

template HashMap::HM_ENTRY<int*>* HashMap::allocEntry<int*, int, int>(const char* key, int value);
template HashMap::HM_ENTRY<char*>* HashMap::allocEntry<char*, const char *, char>(const char* key, const char* value);
//template HashMap::HM_ENTRY<float>* HashMap::allocEntry<float>(const char* key, float* value);
//template HashMap::HM_ENTRY<double>* HashMap::allocEntry<double>(const char* key, double* value);

template void HashMap::setEntry<int*, int, int>(HMap<int*>* htbl, const char *key, int value);
template void HashMap::setEntry<char*, const char *, char>(HMap<char*>* htbl, const char *key, const char *value);
//template void HashMap::setEntry(HMap<int> *htbl, const char *key, int *value);
//template void HashMap::setEntry(HMap<float> *htbl, const char *key, float *value);
//template void HashMap::setEntry(HMap<double> *htbl, const char *key, double *value);
//template void HashMap::setEntry<char*, const char *>(HMap<char*>* htbl, const char *key, const char *value);
template HashMap::HM_ENTRY<char*>* HashMap::getEntry(HMap<char*> *htbl, const char *key);
template HashMap::HM_ENTRY<int>* HashMap::getEntry(HMap<int> *htbl, const char *key);
//template float* HashMap::getEntry(HMap<float> *htbl, const char *key);
//template double* HashMap::getEntry(HMap<double> *htbl, const char *key);

template void HashMap::printEntries(HMap<char*> *htbl);
template void HashMap::printEntries(HMap<int*> *htbl);
//template void HashMap::printEntries(HMap<float> *htbl);
//template void HashMap::printEntries(HMap<double> *htbl);

template int HashMap::removeEntry(HMap<char*> *htbl, const char *key);
template int HashMap::removeEntry(HMap<int*> *htbl, const char *key);
//template int HashMap::removeEntry(HMap<float> *htbl, const char *key);
//template int HashMap::removeEntry(HMap<double> *htbl, const char *key);

template int HashMap::prune(HMap<char*>** htbl_ptr);
template int HashMap::prune(HMap<int*>** htbl_ptr);
//template int HashMap::prune(HMap<float>** htbl_ptr);
//template int HashMap::prune(HMap<double>** htbl_ptr);

template void HashMap::updateValue<char*, const char *>(HashMap::HM_ENTRY<char*>* entry, const char * value);
template void HashMap::updateValue<int*, int>(HashMap::HM_ENTRY<int*>* entry, int value);
*/
