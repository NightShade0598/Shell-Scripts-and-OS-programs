name=${1}

for i in ${@:2}
do
	case "$i" in
		"-linecount" ) 
			wc -l < $name
			;;
		"-wordcount" ) 
			wc -w < $name 
			;;
		"-charcount" ) 
			wc -m < $name
			;; 
		* ) 
			echo "Invalid option $i" 
			;;
	esac
done