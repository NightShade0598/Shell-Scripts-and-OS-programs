#!/bin/sh

if [ ! -e $1 ];then
	echo "The file $1 does not exist"
elif [ -e $2 ];then
	echo "The file $2 already exists"
else
	`cp $1 $2`
	echo "Copied $1 to $2"
fi
