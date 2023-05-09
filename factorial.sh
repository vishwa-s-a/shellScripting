#! /bin/bash

#program to find the factorial of the given number
factorial(){
    # taking the arguments of function into num1 variable
    local num1=$1
    fact=1
    for((i=1;i<=num1;i++))
    do
        fact=$((fact*i))
    done
    echo The factorial of the number is: $fact
}
#calling the function once
echo Enter the number
read num
factorial num
#calling the function another time
echo Enter another number
read num
factorial num