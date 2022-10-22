
#ifndef TEMP_ARRAYS_AP
#define TEMP_ARRAYS_AP
namespace Template
{
	namespace Arrays
	{

		template<typename PTR>
		void allocPointer(unsigned int* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(unsigned long* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(unsigned char* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(unsigned short* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(long int* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(long long* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(long double* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(char* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(short* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(int* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(float* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(double* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void allocPointer(bool* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);
	};
}
#include "temp_arrays_aP.hpp"
#endif
