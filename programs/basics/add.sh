#! /bin/bash

# program to add two numbers
sum1=$(($1+$2))
echo the sum of numbers given through terminal is $sum1
echo enter first number
read a
echo enter second number
read b
sum=$((a+b))
echo the sum of two numbers is $sum