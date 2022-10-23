
#ifndef TEMP_DATATYPES_FT_HPP
#define TEMP_DATATYPES_FT_HPP
namespace Datatypes
{

		template<typename T>
		void formatType(char* str, unsigned short val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
		{
			sprintf(str,"%u",val);
		};
		template<typename T>
		void formatType(char* str, unsigned int val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
		{
			sprintf(str,"%u",val);
		};
		template<typename T>
		void formatType(char* str, unsigned long val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
		{
			sprintf(str,"%u",val);
		};
		template<typename T>
		void formatType(char* str, long int val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
		{
			sprintf(str,"%u",val);
		};
		template<typename T>
		void formatType(char* str, long long val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
		{
			sprintf(str,"%u",val);
		};
		template<typename T>
		void formatType(char* str, short val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
		{
			sprintf(str,"%d",val);
		};
		template<typename T>
		void formatType(char* str, int val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
		{
			unsigned int col_size_conform = (unsigned int) max((int)min_size - (int)num_ldigits,0);
			char ext_space[2]="";

			char first_margin [col_size_conform/2 + 1];
			char second_margin [col_size_conform/2 + 1];
			for(int i = 0; i < col_size_conform/2; i++)
			{
				first_margin[i]=' ';
				second_margin[i]=' ';
			};
			if((col_size_conform/2)*2 < col_size_conform)
			{
				ext_space[0]=' ';
			};
			first_margin[col_size_conform/2] = '\0';
			second_margin[col_size_conform/2] = '\0';
			sprintf(str,"%s%i%s%s",first_margin,val,ext_space,second_margin);
		};

}
#endif
