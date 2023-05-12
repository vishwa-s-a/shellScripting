#!/bin/bash

#sum of numbers using for loop 
echo Enter the total count of numbers to be added
read num
sum=0

for((i=0;i<num;i++))
do
    echo Enter the number
    read temp
    sum=$((sum+temp))
done
echo The sum is : $sum