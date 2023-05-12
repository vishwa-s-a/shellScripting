#! /bin/bash

case ${1,,} in
	vishwa | admin )
		echo "Hello, ${1,,} you are my boss"
		;;
	help )
		echo "Login to get help"
		;;
	*)
		echo "You are not my boss"
esac
# here ;; indicates the break statement of c's case statements
# esac is the reverse of case which indicates the end of case block
# *) is given for default condition if the above cases are not met then it comes to this default block

