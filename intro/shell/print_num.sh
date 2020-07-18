#!/bin/sh

var=1

while [ $var -le 100 ]; do
	echo num$var
	var=$(expr $var + 1)
done
