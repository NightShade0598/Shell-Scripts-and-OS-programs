name=${1}

echo "1. Search Patterns"
echo "2. Delete Patterns"
echo "3. Exit"
while true
do
	echo "Enter choice.(1/2/3)"
	read choice
	case $choice in
		1) 
			for i in ${@:2}
			do
				grep "$i" $name
			done 
			;;
		2) 
			for i in ${@:2}
			do
				sed -i "s/$i//g" $name
			done
			;;
		3) 
			exit
			;;
		*) 
			echo "Invalid option."
			;;
	esac
done