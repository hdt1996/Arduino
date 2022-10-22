
#ifndef DATATYPE_HPP
    #define DATATYPE_HPP
    namespace Datatypes
    {

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
    };
#endif