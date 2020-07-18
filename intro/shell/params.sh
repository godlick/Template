#!/bin/sh

var=hello

echo ${var:-default}
unset var
echo ${var:-default}

echo $var
var=helloworld

echo ${#var}
