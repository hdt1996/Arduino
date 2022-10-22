
BASEDIR=$(readlink -f $(dirname "$0"))
signables="int long char short"
signs="unsigned"

longables="int long double"
longs="long"

prim_types="char short int float double bool"

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
\t\tvoid allocPointer($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_aP.h
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid allocPointer($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_aP.h
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename PTR>
\t\tvoid allocPointer($i* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_aP.h
    

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
\t\tvoid allocPointer($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
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
\t\tvoid allocPointer($comb pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_aP.hpp
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename PTR>
\t\tvoid allocPointer($i* pointer, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_aP.hpp
    

done
echo -e "\t};
}
#endif" >> $dest/output/temp_arrays_aP.hpp



################################################################################## set Pointer #############################################################################################


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
echo -e "\t\ttemplate<typename PTR>
\t\tvoid setPointer(PTR* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_sP.h
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid setPointer(PTR* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_sP.h
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename PTR>
\t\tvoid setPointer(PTR* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1);" >> $dest/output/temp_arrays_sP.h
    

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

for i in $signables
do
    for a in $signs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid setPointer(PTR* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_sP.hpp
    done

done
for i in $longables
do
    for a in $longs
    do
    comb="$a $i*"
echo -e "\t\ttemplate<typename PTR>
\t\tvoid setPointer(PTR* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_sP.hpp
    done

done
for i in $prim_types
do
echo -e "\t\ttemplate<typename PTR>
\t\tvoid setPointer(PTR* pointer, ARG value, unsigned int* dimensions, unsigned int current= 0, unsigned int prev = 1)
\t\t{
\t\t\treturn;
\t\t}" >> $dest/output/temp_arrays_sP.hpp
    

done
echo -e "\t};
}
#endif" >> $dest/output/temp_arrays_sP.hpp