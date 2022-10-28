
#ifndef TEMP_ARRAYS_SA
#define TEMP_ARRAYS_SA
#include "datatypes.h"
namespace Template
{
	namespace Arrays
	{

		template<typename PTR, typename ARG>
		void setArrays(unsigned int* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(unsigned long* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(unsigned char* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(unsigned short* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(long int* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(long long* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(long double* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(char* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(short* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(int* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(float* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(double* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setArrays(bool* pointer, ARG value, unsigned int num_dimensions, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
	};
}
#include "temp_arrays_sA.hpp"
#endif
