
#ifndef DATATYPE_HPP
    #define DATATYPE_HPP
    #include "templates.h"
    //#include "temp_datatypes_fT.h"
    namespace Datatypes
    {
        template<typename T>
        void formatType(char* str, T val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
        {
            dtostrf(val,min_size,num_rdigits,str);
        };

        template <typename T>
        bool checkForString(T value)
        {
            char* strings[]={const_char_pstr,char_pstr};
            for(int i = 0; i < sizeof(strings)/sizeof(strings[0]);i++)
            {
                if(strcmp(strings[i],get(value))== 0)
                {
                    return true;
                };
            };
            return false;
        };

        template<typename T>
        unsigned int getLeftNumDigits(T val) //ARDUINO LIMITATION FOR datatypes: ONLY 4 bytes max (32 bits) for numbers double == float; ALSO MAX of 7-9 significant digits. Prevent mistakes by using scientific notation
        {
            T ldigits = floor(val);
            if(ldigits >= 0 && ldigits <= 1)
            {
                return 1;
            };
            unsigned int num_ldigits=0;
            while(ldigits > 1)
            {
                ldigits = ldigits/10;
                num_ldigits++;
                if(ldigits >= 1 && ldigits < 10)
                {
                    num_ldigits++;
                    break;
                };
            };
            return num_ldigits;
        };

        template <typename T>
        char* toCharArray(T val, unsigned int min_size = 1, unsigned int num_rdigits = 2)
        {
            typedef typename Template::Modify::unPointer<T>::type base_type;
            base_type drf_val = Template::Modify::derefPointer(val);
            unsigned int num_ldigits = getLeftNumDigits(drf_val);

            unsigned int size = num_ldigits+num_rdigits+2; //accounts for "." and NULL terminator
            if(min_size > size)
            {
                size = size + (min_size - size) + 1; //1 Extra for more precaution regarding null terminator
            };
            char * str = new char [size];
            //dtostrf(val,min_size,num_rdigits,str);
            formatType<base_type>(str, drf_val,num_ldigits, min_size,num_rdigits);
            return str;
        };

        template<typename T>
        char* toCharArray(char val, unsigned int min_size = 1, unsigned int num_rdigits = 2)
        {
            char * str = new char [2];
            str[0] = val;
            str[1] = '\0';
            return str;
        };
        
        template<typename T>
        char* toCharArray(char * val, unsigned int min_size = 1, unsigned int num_rdigits = 2)
        {
            char * str = new char [strlen(val)+1];
            strcpy(str, val);
            return val;
            
        };

        template<typename T>
        char* toCharArray(const char * val, unsigned int min_size = 1, unsigned int num_rdigits = 2)
        {
            char * str = new char [strlen(val)+1];
            strcpy(str, val);
            return str;
        };
    };
#endif