
#ifndef TEMP_ARRAYS_AP
#define TEMP_ARRAYS_AP
namespace Template
{
	namespace Arrays
	{

		template<typename PTR>
		void allocPointers(unsigned int* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(unsigned long* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(unsigned char* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(unsigned short* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(long int* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(long long* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(long double* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(char* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(short* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(int* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(float* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(double* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointers(bool* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
	};
}
#include "temp_arrays_aP.hpp"
#endif
