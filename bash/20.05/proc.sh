#! /bin/bash


getChildren() {
	if [ "$1" = "n" ]; then
		echo -n "Enter the name: "
		read name
		ppid=`ps aux | grep $name | tr -s ' ' | cut -d ' ' -f 2`
	else
		echo -n "Enter pid: "
		read ppid
	fi

	if [[ "$ppid" == "" ]]; then 
		echo "Can't find process with name-> $name"
		exit
	fi
	ps aux | pgrep $ppid
}

way="x"
while [[ "$way" != "n" && "$way" != "i" ]]; do
	echo -n "Find by process name or ID?(n/i): "
	read way
done

getChildren $way
