#! /bin/bash

echo Enter the year
read year

temp1=$((year%4))
temp2=$((year%100))
temp3=$((year%400))

if [ $temp1 -eq 0 ];then
    if [ $temp2 -ne 0 ]; then
        echo "Its a leap year"
    else
        echo "Its not a leap year"
    fi

elif [ $temp3 -eq 0 ]; then
    echo "Its a leap year"
else
    echo "Its not a leap year"
fi