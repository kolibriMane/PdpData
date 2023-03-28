#! /bin/bash

echo -n "Input file path: "
read path

#Check is path correct
if test -f "$path"; then
    echo "$path exist"

#Enter path while it is not correct
else
    while !(test -f "$path"); do
        echo "You'r enter invalid path, please try again :("
        read path
    done
fi

#Check is file empty
file=($(cat $path));
if [[ "$file" == "" ]]; then
    echo "Entered file is empty!!!"
    exit;
fi

#delete line, were second column is "data"
file=`awk '$2 == "data" { next } { print }' "$path"`
echo "$file" > $path
