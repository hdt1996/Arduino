#!/bin/bash
BASEDIR=$(readlink -f $(dirname "$0"))
signables="short int long"
signs="unsigned"

longables="int long"
longs="long"

prim_types="short int"

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


################################################# formatTypes  #################################################


########### Declaration #############

echo -e "
#ifndef TEMP_DATATYPES_FT
#define TEMP_DATATYPES_FT
namespace Datatypes
{
" > $dest/output/temp_datatypes_fT.h

for i in $signables
do
    for a in $signs
    do
    comb="$a $i"
echo -e "\t\ttemplate<typename T>
\t\tvoid formatType(char* str, $comb val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);" >> $dest/output/temp_datatypes_fT.h
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i"
echo -e "\t\ttemplate<typename T>
\t\tvoid formatType(char* str, $comb val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);" >> $dest/output/temp_datatypes_fT.h
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename T>
\t\tvoid formatType(char* str, $i val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2);" >> $dest/output/temp_datatypes_fT.h
    

done
echo -e "
};
#include \"temp_datatypes_fT.hpp\"
#endif" >> $dest/output/temp_datatypes_fT.h


################ Implementation ###############
echo -e "
#ifndef TEMP_DATATYPES_FT_HPP
#define TEMP_DATATYPES_FT_HPP
namespace Datatypes
{
" > $dest/output/temp_datatypes_fT.hpp

for i in $signables
do
    for a in $signs
    do
    comb="$a $i"
echo -e "\t\ttemplate<typename T>
\t\tvoid formatType(char* str, $comb val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
\t\t{
\t\t\tsprintf(str,\"%u\",val);
\t\t};" >> $dest/output/temp_datatypes_fT.hpp
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i"
echo -e "\t\ttemplate<typename T>
\t\tvoid formatType(char* str, $comb val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
\t\t{
\t\t\tsprintf(str,\"%u\",val);
\t\t};" >> $dest/output/temp_datatypes_fT.hpp
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename T>
\t\tvoid formatType(char* str, $i val, unsigned int num_ldigits, unsigned int min_size = 1, unsigned int num_rdigits = 2)
\t\t{
\t\t\tsprintf(str,\"%d\",val);
\t\t};" >> $dest/output/temp_datatypes_fT.hpp
    

done
echo -e "
}
#endif" >> $dest/output/temp_datatypes_fT.hpp
