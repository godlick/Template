#!/bin/sh

foo()
{
	echo "arg num is $#"
	echo "arg 0 is $0"
	echo "arg 1 is $1"
	echo "arg 2 is $2"
}

foo aaa bbb

