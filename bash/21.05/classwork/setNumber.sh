#! /bin/bash

echo -n "Enter the file path: "
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

#Delete empty lines
sed -i '/^$/d' $path

#Delete multiple spaces
file=`tr -s " " < porc`
echo "$file" > $path

#Set numbers to line
file=`grep -n '^' $path`
echo "$file" > $path

echo "Wel done, see the file!!"
