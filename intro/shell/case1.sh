#!/bin/sh

echo "Please input yes or no"

read var

case $var in
	yes|y|YES|Yes)	echo yes;;
	no|NO|No)		echo no;;
	*)		echo "input error";;
esac
