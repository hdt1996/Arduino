
#ifndef TEMP_ARRAYS_PPV
#define TEMP_ARRAYS_PPV
#include "datatypes.h"
namespace Template
{
	namespace Arrays
	{

		template<typename PTR>
		void printPTRVals(unsigned int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(unsigned long* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(unsigned char* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(unsigned short* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(long int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(long long* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(long double* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(char* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(short* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(float* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(double* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
		template<typename PTR>
		void printPTRVals(bool* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);
	};
}
#include "temp_arrays_ppV.hpp"
#endif
