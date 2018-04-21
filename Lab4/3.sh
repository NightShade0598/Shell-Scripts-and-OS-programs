function sortlist()
{
	n=${#a[@]}
	for ((i=0; i<$n-1; i++))
	do
		for ((j=$i+1; j<$n; j++))
		do
			if [ ${a[$i]} \> ${a[$j]} ]
				then
				t=${a[$i]}
				a[$i]=${a[$j]}
				a[$j]=$t
			fi
		done
	done
}

a=("$@")
sortlist
echo ${a[*]}