#! /bin/bash

echo -n "Input file path: "
read path

#Check is path correct
if test -f "$path"; then
    echo "$path good path"

#Enter path while it is not correct
else
    while !(test -f "$path"); do
        echo "You'r enter invalid path, please try again :("
        read path
    done
fi

#Print every 3th lines in green
awk 'NR % 3 == 0' $path | awk '{print "\033[32m" $1 "\033[31m" $2 }'
