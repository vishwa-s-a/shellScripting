#! /bin/bash

# here we are going to define a  function which will show us the uptime of the device

showUpTime(){
	# here we will convert the up and since variables as local by giving local before up so that they
	# are only available in the function's scope and not modified outside the function
	local up=$(uptime -p | cut -c4- ) # here we are cutting the starting 4 characters of the output by giving -c4-  
	local since=$(uptime -s)
	# now we give a multiline string as output using EOF tag
	cat << EOF
--------------
This machine is up for ${up}
And this machine is up since ${since}
--------------
EOF
}
# calling the function
showUpTime
