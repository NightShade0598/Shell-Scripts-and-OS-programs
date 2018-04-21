declare -a arr
echo "Enter the number of elements : "
read N
for((i=0;i<N;i++));do
read arr[i]
done
read -a arr2
for((i=1;i<${#arr[@]};i++));do
echo "Element at index $i is ${arr[i]}"
done
echo "Array 2 is ${arr2[@]}"
