#! /bin/bash

echo "Input file path->"
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
    echo "Nothing to delete. Entered file is clear !!!"
    exit;
fi

#Show file content    
echo "*******************"
echo "* See the content *"
echo "*******************"
echo "$path exist"
cat $path
echo "******* EOF *******"

rm -rf $path;
a=0;

#Delete comments if exist, and count deleetd lines
for i in "${file[@]}"; do
    if [[ $i =~ ^#.* ]] || [[ $i =~ ^//.* ]]; then
	(( a++ ));
    else
	echo "$i" >> $path
    fi
done

#Show information about deleted lines
if [[ $a -gt 0 ]]; then
    echo "deleted $a lines !!!"
else
    echo "There are not comments to delete !!!"
    exit;
fi

#Show new file content
echo "********************"
echo "* New file content *"
echo "********************"
cat $path; 
echo "******** EOF *******"
