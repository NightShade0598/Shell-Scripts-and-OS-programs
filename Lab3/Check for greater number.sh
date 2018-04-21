echo "Enter two numbers : "
read a
read b
if [ $a == $b ]; then
echo $a is equal to $b
elif [ $a -gt $b ]; then
echo $a is greater than $b
elif (( a<b)) ; then
echo $a is less than $b
else
echo Invalid
fi
