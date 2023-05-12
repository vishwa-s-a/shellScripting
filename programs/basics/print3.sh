#! /bin/bash

echo Enter the number
read num

for((i=0;i<num;i++))
do
    temp=$((num-i))
    for((j=temp;j>0;j--))
    do
        if [ $j -eq $temp ]; then

            for((k=0;k<i;k++))
            do
                echo -n "  "
            done

        fi
        echo -n "* "
    done
    echo " "
done