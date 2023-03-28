#! /bin/bash

proc=`ps -o pid -u $USER`

for i in ${proc[@]}; do
	if [ "$i" != "PID" ]; then
		childNum=`ps --no-headers -o pid --ppid=$i | wc -w`
		if [ "childNum" = "2" ]; then
			pkill -9 -p $i
			kill -9 "$i"
		fi
	fi
done
