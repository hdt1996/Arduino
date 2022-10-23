
#ifndef TEMP_ARRAYS_SP
#define TEMP_ARRAYS_SP
namespace Template
{
	namespace Arrays
	{

		template<typename PTR, typename ARG>
		void setPointers(unsigned int* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(unsigned long* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(unsigned char* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(unsigned short* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(long int* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(long long* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(long double* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(char* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(short* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(int* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(float* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(double* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR, typename ARG>
		void setPointers(bool* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
	};
}
#include "temp_arrays_sP.hpp"
#endif
