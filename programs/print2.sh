#! /bin/bash

echo Enter the number: 
read num
temp=1
for((i=1;i<=num;i++))
do
    for((j=1;j<=i;j++))
    do

        if [ $temp -le  $num ];then
            echo -n "$temp "
            temp=$((temp+1))
        fi
        #echo "temp: $temp"
    done
    echo " "
    if [ $temp -gt $num ];then
        break
    fi
done