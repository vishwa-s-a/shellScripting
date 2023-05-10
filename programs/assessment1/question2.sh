#! /bin/bash

echo length:
read length

echo breadth:
read breadth

length=$((length-6))
breadth=$((breadth-6))
rows=$((length/3 + 1))
columns=$((breadth/3 + 1))

total=$((rows * columns))
echo Number of wine trees: $total