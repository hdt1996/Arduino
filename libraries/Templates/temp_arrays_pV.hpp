
#ifndef TEMP_ARRAYS_PV_HPP
#define TEMP_ARRAYS_PV_HPP
#include "datatypes.h"
namespace Template
{
	namespace Arrays
	{

		template<typename PTR>
		void printValues(unsigned int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(unsigned long* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(unsigned char* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(unsigned short* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(long int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(long long* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(long double* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(char* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(short* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(float* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(double* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
		template<typename PTR>
		void printValues(bool* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			//Serial.print(index);
			for(int i = 1; i < num_dimensions; i++)
			{
				Serial.print(indices[i]);
				Serial.write(' ');
			};
			Serial.print("| ");

			for(int d = 0; d < prev; d++)
			{
				num_str = Datatypes::toCharArray(pointer[d],col_size);
				Serial.write(num_str);
				Serial.print(" | ");
				delete num_str;
			};
			Serial.println();
		};
	};
}
#endif
