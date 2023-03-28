#! /bin/bash

var1=5
while [ $var1 -gt 9 ]
do
echo $var1
done


if pwd
then
echo "It works"
fi
echo `pwd`
pwd
echo $?
echo $(pwd)

b=2
c=3
a=$[ $b + $c ]
echo $a
a=$(( $b * $c ))
echo $a
let "a = $b / $c"
echo $a

echo ${!#}

read -s passw
echo $passw
if read -t 5 -p "enter your name: " name
then
echo "hello $name, welcome to my script"
else
echo "sorry, too slow! "
fi


read a
read -p "hello : " a
file="hi"

# chbavarari paymanin
while [[ $file = "hi" ]];
do
	read file
done

# petq e bavarari paymanin
until [[ $file = "hi" ]];
do
	read file
done

echo "Введите a: "
read a
echo "Введите b: "
read b

let "c = a + b" #сложение
echo "a+b= $c"
let "c = a / b" #деление
echo "a/b= $c"
let "c <<= 2" #сдвигает c на 2 разряда влево
echo "c после сдвига на 2 разряда: $c"
let "c = a % b" # находит остаток от деления a на b
echo "$a / $b. остаток: $c "


#export a=6
a=6
