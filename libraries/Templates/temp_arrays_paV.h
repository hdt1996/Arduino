
#ifndef TEMP_ARRAYS_PAV
#define TEMP_ARRAYS_PAV
#include "datatypes.h"
namespace Template
{
	namespace Arrays
	{

		template<typename PTR>
		void printARRVals(unsigned int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(unsigned long* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(unsigned char* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(unsigned short* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(long int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(long long* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(long double* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(char* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(short* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(float* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(double* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printARRVals(bool* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
	};
}
#include "temp_arrays_paV.hpp"
#endif
