#!/bin/sh

for file in $(ls *.c)
do
    gcc $file -c
done

