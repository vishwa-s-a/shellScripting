#!/bin/bash

echo -n Enter the number until which sum has to be calculated :
read num
sum=0
for(( i=0 ; i< $num ; i++ ))
do
    sum=$((sum+i))
    
done
echo The sum of first n numbers is: $sum