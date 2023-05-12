#!/bin/bash

echo Enter the Number:
read num
check=$((num % 2))
if [ $check = 0 ]; then
	echo "Entered number is even"
else
	echo "Entered number is odd"
fi
