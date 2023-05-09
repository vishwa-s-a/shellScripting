#! /bin/bash

echo Enter the number
read num

for((i=1;i<num;i++))
do
    for((j=0;j<i;j++))
    do
        if [ $j -eq 0 ] ; then
        echo -n "*"
        fi
        echo -n -e "\t*"
        if [ $j -eq $((i-1)) ]; then
        echo -e "\n"
        fi
    done
done