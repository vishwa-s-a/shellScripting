#!/bin/sh
cd /home/vishwa
echo "********************where you want to work************************"
ls
read work
cd /home/vishwa/$work
echo "********************Now where*****************************"
ls
read new
cd /home/vishwa/$work/$new
echo "***************These are content of the folder********************"
ls
code .

