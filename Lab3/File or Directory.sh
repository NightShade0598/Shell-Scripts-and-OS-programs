echo Enter a File or Directory  name.
read name
if [ -d $name ]; then
	echo It is a directory.
elif [ -f $name ]; then
	echo "It is a file."
else
	echo Not Found.
fi
