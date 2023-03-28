#! /bin/bash

a=1
b=2

if (( $a < $b )); then 
	echo hi
fi

if test $a -lt $b; then 
	echo hi
fi

if (test $a -gt $b ); then 
	echo hi
fi


if [ $a -gt $b ]; then 
	echo hi
fi

if [[ ($a >  $b) || ($a = $b) ]]; then 
	echo hi
fi


case $doing in
2) 
echo hi
;;

3)
echo hello
;;
1)
echo hihi
;;
*)
echo hii
esac
