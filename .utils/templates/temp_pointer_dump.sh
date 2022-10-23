#!/bin/bash
BASEDIR=$(readlink -f $(dirname "$0"))

read -p \
"Please enter max number of nested pointer levels:
..................................................
Enter Number: " num

read -p "

Default location: $BASEDIR
Choose Options
.................................................
<Enter>: Use default location above
q:       Quit
<Dest>:  Custom folder destination for output file
..................................................
Enter Option: " dest

if [ "$dest" = "q" ]; then

    return  

elif [ "$dest" = "" ]; then
    dest=$BASEDIR
else

    dest=$(echo $dest | sed s/\'//g)
fi


############################################################################## add Pointer ###################################################################################

##################### Declaration #######################

echo -e "
#ifndef TEMP_POINTERS_MP
#define TEMP_POINTERS_MP
namespace Template
{
\tnamespace Modify
\t{
\t\ttemplate<typename T, unsigned int N>
\t\tstruct addNPointers;" > $dest/output/temp_pointers_mP.h

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tstruct addNPointers<T,$i>;" >> $dest/output/temp_pointers_mP.h
done
echo -e "\t};
}
#include \"temp_pointers_mP.hpp\"
#endif" >> $dest/output/temp_pointers_mP.h




#################Implementation #################


echo -e "
#ifndef TEMP_POINTERS_MP_HPP
#define TEMP_POINTERS_MP_HPP
namespace Template
{
\tnamespace Modify
\t{
\t\ttemplate<typename T, unsigned int N>
\t\tstruct addNPointers{typedef T type;};" > $dest/output/temp_pointers_mP.hpp

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tstruct addNPointers<T,$i>{typedef T$asts type;};" >> $dest/output/temp_pointers_mP.hpp
done
echo -e "\t};
}
#endif" >> $dest/output/temp_pointers_mP.hpp


############################################################################# remove Pointer #######################################################################################


######################## Declaration ########################
echo -e "
#ifndef TEMP_POINTERS_RP
#define TEMP_POINTERS_RP
namespace Template
{
\tnamespace Modify
\t{
\t\ttemplate<typename T>
\t\tstruct unPointer;" > $dest/output/temp_pointers_rP.h

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tstruct unPointer<T$asts>;" >> $dest/output/temp_pointers_rP.h
done
echo -e "\t};
}
#include \"temp_pointers_rP.hpp\"
#endif" >> $dest/output/temp_pointers_rP.h

################### Implementation ######################

echo -e "
#ifndef TEMP_POINTERS_RP_HPP
#define TEMP_POINTERS_RP_HPP
namespace Template
{
\tnamespace Modify
\t{
\t\ttemplate<typename T>
\t\tstruct unPointer{typedef T type;};" > $dest/output/temp_pointers_rP.hpp

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tstruct unPointer<T$asts>{typedef T type;};" >> $dest/output/temp_pointers_rP.hpp
done
echo -e "\t};
}
#endif" >> $dest/output/temp_pointers_rP.hpp



############################################################################ deref Pointer ##############################################################################


######################## Declaration ########################
echo -e "
#ifndef TEMP_POINTERS_DP
#define TEMP_POINTERS_DP
namespace Template
{
\tnamespace Modify
\t{
\t\ttemplate<typename T>
\t\tT derefPointer(T arg);" > $dest/output/temp_pointers_dP.h

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tT derefPointer(T$asts arg);" >> $dest/output/temp_pointers_dP.h
done
echo -e "\t};
}
#include \"temp_pointers_dP.hpp\"
#endif" >> $dest/output/temp_pointers_dP.h

################### Implementation ######################

echo -e "
#ifndef TEMP_POINTERS_DP_HPP
#define TEMP_POINTERS_DP_HPP
namespace Template
{
\tnamespace Modify
\t{
\t\ttemplate<typename T>
\t\tT derefPointer(T arg){return arg;};" > $dest/output/temp_pointers_dP.hpp

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tT derefPointer(T$asts arg){return $asts arg;};" >> $dest/output/temp_pointers_dP.hpp
done
echo -e "\t};
}
#endif" >> $dest/output/temp_pointers_dP.hpp

