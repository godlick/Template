#!/bin/sh

if [ -e test.data ]
then
	rm test.data -fr
else
	touch test.data && echo hello > test.data
fi

