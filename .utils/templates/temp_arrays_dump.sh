#!/bin/bash
BASEDIR=$(readlink -f $(dirname "$0"))
signables="int long char short"
signs="unsigned"

longables="int long double"
longs="long"

prim_types="char short int float double bool"

SP_signables="int long short"
SP_types="short int float double bool"

read -p "

Default location: $BASEDIR
Choose Options
.................................................
<Enter>: Use default location above
q:       Quit
<Dest>:  Custom folder destination for output file
..................................................
Enter Option: " dest

if [ "$dest" == "q" ]; then

    return  


elif [ "$dest" == "" ]; then

    dest=$BASEDIR

else

    dest=$(echo $dest | sed s/\'//g)
fi


################################################# allocPointers DUMP for different base pointer types ###########################################


########### Declaration #############

echo -e "
#ifndef TEMP_ARRAYS_AP
#define TEMP_ARRAYS_AP
namespace Template
{
\tnamespace Arrays
\t{
" > $dest/output/temp_arrays_aP.h

for i in $signables
do
    for a in $signs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid allocPointers($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_aP.h
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid allocPointers($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_aP.h
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename PTR>
\t\tvoid allocPointers($i* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_aP.h
    

done
echo -e "\t};
}
#include \"temp_arrays_aP.hpp\"
#endif" >> $dest/output/temp_arrays_aP.h


################ Implementation ###############
echo -e "
#ifndef TEMP_ARRAYS_AP_HPP
#define TEMP_ARRAYS_AP_HPP
namespace Template
{
\tnamespace Arrays
\t{
" > $dest/output/temp_arrays_aP.hpp

for i in $signables
do
    for a in $signs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid allocPointers($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_aP.hpp
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid allocPointers($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_aP.hpp
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename PTR>
\t\tvoid allocPointers($i* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_aP.hpp
    

done
echo -e "\t};
}
#endif" >> $dest/output/temp_arrays_aP.hpp



################################################################################## setPointers #############################################################################################


############### Declaration #################

echo -e "
#ifndef TEMP_ARRAYS_SP
#define TEMP_ARRAYS_SP
namespace Template
{
\tnamespace Arrays
\t{
" > $dest/output/temp_arrays_sP.h

for i in $signables
do
    for a in $signs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR, typename ARG>
\t\tvoid setPointers($comb pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_sP.h
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR, typename ARG>
\t\tvoid setPointers($comb pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_sP.h
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename PTR, typename ARG>
\t\tvoid setPointers($i* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_sP.h
    

done
echo -e "\t};
}
#include \"temp_arrays_sP.hpp\"
#endif" >> $dest/output/temp_arrays_sP.h


##################### Implementation #######################
echo -e "
#ifndef TEMP_ARRAYS_SP_HPP
#define TEMP_ARRAYS_SP_HPP
namespace Template
{
\tnamespace Arrays
\t{
" > $dest/output/temp_arrays_sP.hpp

for i in $SP_signables
do
    for a in $signs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR, typename ARG>
\t\tvoid setPointers($comb pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\t// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
\t\t\tfor(int d = 0; d < prev; d++)
\t\t\t{
\t\t\t\tpointer[d] = value[d];
\t\t\t};
\t\t};" >> $dest/output/temp_arrays_sP.hpp
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR, typename ARG>
\t\tvoid setPointers($comb pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\t// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
\t\t\tfor(int d = 0; d < prev; d++)
\t\t\t{
\t\t\t\tpointer[d] = value[d];
\t\t\t};
\t\t};">> $dest/output/temp_arrays_sP.hpp
    done

done
for i in $SP_types
do
echo -e "\t\ttemplate<typename PTR, typename ARG>
\t\tvoid setPointers($i* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\t// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
\t\t\tfor(int d = 0; d < prev; d++)
\t\t\t{
\t\t\t\tpointer[d] = value[d];
\t\t\t};
\t\t};">> $dest/output/temp_arrays_sP.hpp
done

echo -e "\t\ttemplate<typename PTR, typename ARG>
\t\tvoid setPointers(char* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\t// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
\t\t\tstrncpy(pointer, value, prev);
\t\t\tpointer[prev-1]='\\\0';
\t\t};">> $dest/output/temp_arrays_sP.hpp

echo -e "\t\ttemplate<typename PTR, typename ARG>
\t\tvoid setPointers(unsigned char* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\t// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
\t\t\tstrncpy(pointer, value, prev);
\t\t\tpointer[prev-1]='\\\0';
\t\t};">> $dest/output/temp_arrays_sP.hpp
echo -e "\t};
}
#endif" >> $dest/output/temp_arrays_sP.hpp

############################################################## freePointers ###############################################################

############### Declaration #################

echo -e "
#ifndef TEMP_ARRAYS_FP
#define TEMP_ARRAYS_FP
namespace Template
{
\tnamespace Arrays
\t{
" > $dest/output/temp_arrays_fP.h

for i in $signables
do
    for a in $signs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid freePointers($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_fP.h
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid freePointers($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_fP.h
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename PTR>
\t\tvoid freePointers($i* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_fP.h
    

done
echo -e "\t};
}
#include \"temp_arrays_fP.hpp\"
#endif" >> $dest/output/temp_arrays_fP.h


##################### Implementation #######################
echo -e "
#ifndef TEMP_ARRAYS_FP_HPP
#define TEMP_ARRAYS_FP_HPP
namespace Template
{
\tnamespace Arrays
\t{
" > $dest/output/temp_arrays_fP.hpp

for i in $signables
do
    for a in $signs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid freePointers($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_fP.hpp
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid freePointers($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_fP.hpp
    done

done
for i in $prim_types
do 
echo -e "\t\ttemplate<typename PTR>
\t\tvoid freePointers($i* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_fP.hpp
    

done
echo -e "\t};
}
#endif" >> $dest/output/temp_arrays_fP.hpp


############################################################## printValues ###############################################################
# (PTR* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);  
############### Declaration #################

echo -e "
#ifndef TEMP_ARRAYS_PV
#define TEMP_ARRAYS_PV
namespace Template
{
\tnamespace Arrays
\t{
" > $dest/output/temp_arrays_pV.h

for i in $signables
do
    for a in $signs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid printValues($comb pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_pV.h
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid printValues($comb pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_pV.h
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename PTR>
\t\tvoid printValues($i* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_pV.h
    

done
echo -e "\t};
}
#include \"temp_arrays_pV.hpp\"
#endif" >> $dest/output/temp_arrays_pV.h


##################### Implementation #######################
echo -e "
#ifndef TEMP_ARRAYS_PV_HPP
#define TEMP_ARRAYS_PV_HPP
namespace Template
{
\tnamespace Arrays
\t{
" > $dest/output/temp_arrays_pV.hpp

for i in $signables
do
    for a in $signs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid printValues($comb pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\t// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
\t\t\tchar* num_str;
\t\t\t//Serial.print(index);
\t\t\tfor(int i = 1; i < num_dimensions; i++)
\t\t\t{
\t\t\t\tSerial.print(indices[i]);
\t\t\t\tSerial.write(\' \');
\t\t\t};
\t\t\tSerial.print(\"| \");

\t\t\tfor(int d = 0; d < prev; d++)
\t\t\t{
\t\t\t\tnum_str = Datatypes::toCharArray(pointer[d],col_size);
\t\t\t\tSerial.write(num_str);
\t\t\t\tSerial.print(\" | \");
\t\t\t\tdelete num_str;
\t\t\t};
\t\t\tSerial.println();
\t\t};" >> $dest/output/temp_arrays_pV.hpp
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid printValues($comb pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\t// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
\t\t\tchar* num_str;
\t\t\t//Serial.print(index);
\t\t\tfor(int i = 1; i < num_dimensions; i++)
\t\t\t{
\t\t\t\tSerial.print(indices[i]);
\t\t\t\tSerial.write(\' \');
\t\t\t};
\t\t\tSerial.print(\"| \");

\t\t\tfor(int d = 0; d < prev; d++)
\t\t\t{
\t\t\t\tnum_str = Datatypes::toCharArray(pointer[d],col_size);
\t\t\t\tSerial.write(num_str);
\t\t\t\tSerial.print(\" | \");
\t\t\t\tdelete num_str;
\t\t\t};
\t\t\tSerial.println();
\t\t};" >> $dest/output/temp_arrays_pV.hpp
    done

done
for i in $prim_types
do 
echo -e "\t\ttemplate<typename PTR>
\t\tvoid printValues($i* pointer, unsigned int num_dimensions, unsigned int* dimensions, unsigned int* indices, unsigned int col_size = 1, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\t// WE DO NOT NEED EARLY STOPPER FOR RECURSION AKA if current equals some number because there is default template in arrays_aP that handles base pointer type (double*, int*, etc.)
\t\t\tchar* num_str;
\t\t\t//Serial.print(index);
\t\t\tfor(int i = 1; i < num_dimensions; i++)
\t\t\t{
\t\t\t\tSerial.print(indices[i]);
\t\t\t\tSerial.write(\' \');
\t\t\t};
\t\t\tSerial.print(\"| \");

\t\t\tfor(int d = 0; d < prev; d++)
\t\t\t{
\t\t\t\tnum_str = Datatypes::toCharArray(pointer[d],col_size);
\t\t\t\tSerial.write(num_str);
\t\t\t\tSerial.print(\" | \");
\t\t\t\tdelete num_str;
\t\t\t};
\t\t\tSerial.println();
\t\t};" >> $dest/output/temp_arrays_pV.hpp
    

done
echo -e "\t};
}
#endif" >> $dest/output/temp_arrays_pV.hpp

read x