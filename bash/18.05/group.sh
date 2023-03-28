#! /bin/bash

echo "Enter directory path:";
read dir

#Check is directory exist
if [ -d "$dir" ]; then
    echo "Directory exist"
else 
    while !([ -d "$dir" ]); do
	echo "Incorrect path or directory, please try again :("
	read dir
    done
fi

#Check is directory empty
file=($(ls $dir));
if [[ "$file" == "" ]]; then 
    echo "No files to group, directory clean!"
    exit;
elif [[ 1 == ${#ArrayName[@]} ]]; then
    echo "Only one file, is allready grouped!"
    exit;
else
    #Make directories with group's names
    IFS='_';
    for i in "${file[@]}"; do
	read -ra arr <<< "$i"
	mkdir -p $dir/$arr
   	mv $dir/$arr* $dir/$arr 2> out
    done
fi
