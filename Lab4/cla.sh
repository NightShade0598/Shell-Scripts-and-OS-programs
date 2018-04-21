echo "Total number of arguments : $#"
echo "Argument of String $*"
echo "Argument as array $@"
#echo "Argument 0 is $0 and argument 1 is $1"
for i in $@;do
echo $i
done
for((i=0;i<=$#;i++));do
echo "argument $i is ${!i}"
done
