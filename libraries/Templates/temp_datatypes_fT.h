
#ifndef TEMP_DATATYPES_FT
#define TEMP_DATATYPES_FT
namespace Datatypes
{
		template<typename T>
		void formatType(char* str, unsigned short val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);
		template<typename T>
		void formatType(char* str, unsigned int val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);
		template<typename T>
		void formatType(char* str, unsigned long val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);
		template<typename T>
		void formatType(char* str, long int val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);
		template<typename T>
		void formatType(char* str, long long val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);
		template<typename T>
		void formatType(char* str, short val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);
		template<typename T>
		void formatType(char* str, int val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);

};
#include "temp_datatypes_fT.hpp"
#endif
