#! /bin/bash

declare -f foo 
function foo {
	echo hello world $1
}

foo 2


function myfunc {
	return 256
}

myfunc
echo "The new value is $?"

function myfunc {
	echo $@
}

h=`myfunc`
h=$(myfunc $@)
echo "The new value is $h"

