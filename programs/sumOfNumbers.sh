#! /bin/bash
#using while loop for finding the sum of the numbers
echo Enter the total count of numbers which will be entered:
read num
i=1
sum=0

while [ $i -le $num ]
do
    echo enter the number: 
    read temp
    sum=$((sum+temp))
    i=$((i+1))
done

echo The sum of these numbers is $sum