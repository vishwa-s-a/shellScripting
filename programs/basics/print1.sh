#!/bin/bash

echo Enter the number for printing the pattern: 
read num
for((i=1;i<=num;i++))
do
    temp=$num
    for((j=0;j<i;j++))
    do
        temp2=$((temp-j))
        echo -n "$temp2 "
    done
    echo " "
done