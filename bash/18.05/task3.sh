#! /bin/bash

echo -n "Input file path: "
read path

#Check is path correct
if test -f "$path"; then
    echo "$path exist"

#Enter path while it is not correct
else
    while !(test -f "$path"); do
        echo -n "You'r enter invalid path, please try again :(  "
        read path
    done
fi

sed -i '/^#/d' $path
sed -i '/^[//]/d' $path
