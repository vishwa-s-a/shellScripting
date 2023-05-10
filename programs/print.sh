#!/bin/bash

echo Enter the number for printing the pattern: 
read num

echo Printing the number is increasing order:
for((i=1;i<=num;i++))
do
    for((j=1;j<=i;j++))
    do
        echo -n "$j "
    done
    echo ' '
done