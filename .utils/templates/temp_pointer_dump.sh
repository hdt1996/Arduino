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

if [ "$dest" == "q" ]; then

    return  


elif [ "$dest" == "" ]; then

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
\t\tstruct makePointer;" > $dest/output/temp_pointers_mP.h

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tstruct makePointer<T,$i>;" >> $dest/output/temp_pointers_mP.h
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
\t\tstruct makePointer{typedef T type;};" > $dest/output/temp_pointers_mP.hpp

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tstruct makePointer<T,$i>{typedef T$asts type;};" >> $dest/output/temp_pointers_mP.hpp
done
echo -e "\t};
}
#endif" >> $dest/output/temp_pointers_mP.hpp



############################################################################# dereference Pointer #######################################################################################


######################## Declaration ########################
echo -e "
#ifndef TEMP_POINTERS_DP
#define TEMP_POINTERS_DP
namespace Template
{
\tnamespace Modify
\t{
\t\ttemplate<typename T>
\t\tstruct derefPointer;" > $dest/output/temp_pointers_dP.h

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tstruct derefPointer<T$asts>;" >> $dest/output/temp_pointers_dP.h
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
\t\tstruct derefPointer{typedef T type;};" > $dest/output/temp_pointers_dP.hpp

for i in $(seq 1 $num)
do
    asts=""
    for c in $(seq 1 $i)
    do
        asts+='*'
    done
echo -e "\t\ttemplate<typename T>
\t\tstruct derefPointer<T$asts>{typedef T type;};" >> $dest/output/temp_pointers_dP.hpp
done
echo -e "\t};
}
#endif" >> $dest/output/temp_pointers_dP.hpp