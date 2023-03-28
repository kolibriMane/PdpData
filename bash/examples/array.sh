#! /bin/bash

arr=(1
2 7
3 7
4)

for i in ${arr[@]}; do
	echo hello  $i
done

my_array=(foo bar)

for i in "${my_array[@]}"; do echo "$i"; done
for i in "${my_array[*]}"; do echo "$i"; done

for index in "${!my_array[@]}"; do echo "$index"; done

declare -A array
array=([foo]=bar [baz]=foobar)
for key in "${!array[@]}"; do echo "$key"; done


echo ${#my_array[@]}
echo ${!my_array[@]}

declare -A my
my+=([foo]=bar [baz]=foobar)
echo ${!my[@]}
