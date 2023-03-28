#! /bin/bash

declare -r a="a1"
readonly b="b1"
declare -p a b

#varibles are readonly, will be error
declare -r a="a1"
declare -r b="b1"

#readonly command is to make it final and permanent
#we can't delete mySite
mySite="superuser"
readonly mySite
unset mySite

arr=(1 2 5 6)

#is is not local
for i in ${arr[@]}; do
	echo $i
done
echo $i

declare -r i=2
for i in ${arr[@]}; do
	echo $i
	let a=5
	declare b=4
	#locals
	let f=6
	set k=8
done
echo $i
echo $a
echo $b
echo $f
echo $k

mane="kolibri"
echo $mane
unset mane
echo $mane
