#! /bin/bash
echo Enter the number upto which the sum has to be calculated: 
read num
sum=0

for((i=0; i< $num ; i++));do
    sum=$((sum+i))
    done
echo $sum
