
#ifndef TEMP_ARRAYS_PAV_HPP
#define TEMP_ARRAYS_PAV_HPP
namespace Template
{
	namespace Arrays
	{

		template<typename PTR>
		void printARRVals(unsigned int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(unsigned long* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(unsigned char* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(unsigned short* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(long int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(long long* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(long double* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(char* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(short* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(int* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(float* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(double* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
		void printARRVals(bool* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
		{
			// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
			char* num_str;
			Serial.print((indices-1)[0]);
			Serial.write(' ');
			for(int i = 1; i < num_dimensions - 1; i++)
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
