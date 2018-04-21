function1(){
echo "$1 and $2 arguments"
arr[1]="Programmer"
echo "${arr[@]} need not be passed"
return $(($1+$2))
}
arr[0]="Hello"
arr[1]="World"
echo "This is global space  and now arr is ${arr[@]}"
function1 5 6
echo "Return value from function is $?"
