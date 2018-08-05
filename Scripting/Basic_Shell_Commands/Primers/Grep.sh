#!/bin/bash
#The following command prints all the lines of the file input which contains a number
#
#cat input | grep '[0-9]*'
#
#Example:
#Assume that the input has the following content:
#
#axes12
#w143th
#qwer
#Then the given command prints the following ouput:
#
#axes12
#w143th
#
#
#Now change the command slighly so that it prints only the number part of the lines.
#

cat input | grep -o '[0-9]*'
