#!/bin/sh

var=hello

echo $var
echo ${hello}
echo $(ls /myWork)

for file in *
do
	echo $file
done
