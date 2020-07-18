#!/bin/sh

foo()
{
	sleep "$1"
	echo "$1"
}

while [ -n "$1" ]
do
	foo "$1" &
	shift
done

wait
