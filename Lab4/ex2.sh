#!/bin/sh

for i in $@;do
	if [ ! -e $i ]; then
		echo "$i does not exist"
	else
		echo "Are you sure you want to delete $i?"
		echo "y/n"
		read a
		if [ $a = "y" ];then
			`rm $i`
			echo "Deleted $i"
		elif [ $a = "n" ];then
			echo "Not deleting $i"
		else
			echo "Invalid input"
		fi
	fi
done
