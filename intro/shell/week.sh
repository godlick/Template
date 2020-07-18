#!/bin/sh

echo "Please input 1~7:"
read num

case "$num" in
	1) echo Mon;;
	2) echo Tue;;
	3) echo Wed;;
	4) echo Thu;;
	5) echo Fri;;
	6) echo Sat;;
	7) echo Sun;;
	*) echo "input error!";;
esac
