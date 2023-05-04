#! /bin/bash

# creating of array
My_array=(one two three four)
echo $My_array
# this only prints the first element in the array
echo ${My_array[@]}
# this will print the complete array
echo ${My_array[0]}
# this will print the first element of the array
echo ${My_array[2]}
# this will print the third element of the array

# now we will print the same using a for loop
echo "Now we are using for loop to print the element"
for item in ${My_array[@]};
do echo -n $item | wc -c; #here instead of 'wc -c' if we use echo $item then we get the required output 
done