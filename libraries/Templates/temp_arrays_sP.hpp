
#ifndef TEMP_ARRAYS_SP_HPP
#define TEMP_ARRAYS_SP_HPP
namespace Template
{
	namespace Arrays
	{

		template<typename PTR, typename ARG>
		void setPointers(unsigned int* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(unsigned long* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(unsigned short* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(long int* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(long long* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(long double* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(short* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(int* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(float* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(double* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(bool* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			for(int d = 0; d < prev; d++)
			{
				pointer[d] = value[d];
			};
		};
		template<typename PTR, typename ARG>
		void setPointers(char* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			strncpy(pointer, value, prev);
			pointer[prev-1]='\0';
		};
		template<typename PTR, typename ARG>
		void setPointers(unsigned char* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			strncpy(pointer, value, prev);
			pointer[prev-1]='\0';
		};
	};
}
#endif
