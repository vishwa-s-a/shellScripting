#! /bin/bash
# here in below statement {1,,} is used to show that we are passing arguments through execution command
# ex: bash conditional.sh vishwa
if [ ${1,,}  = vishwa ]; then
	echo "Hello Vishwa, welcome"
elif [ ${1,,} = help ]; then 
	echo "we cannot help you until logged in"
else
	echo "I don't know who you are "
fi
# fi indicates the end of conditional block