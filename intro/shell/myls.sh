#!/bin/sh
#myls.h

if [ $# -lt 1 ]
then
	for file in *
	do
		echo $file
	done
else
	cd $1
	for file in *
	do
		echo $file
	done
fi
