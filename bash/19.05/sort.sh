#! /bin/bash

echo "Enter file path:";
read file

#Check is file exist
if [ -f "$file" ]; then
    echo "File exist!"
else
    while !([ -d "$dir" ]); do
        echo "Incorrect path for file, please try again :("
        read file
    done
fi

#Read file to array
arr=()
while IFS= read -r line; do
   arr+=("$line")
done < $file

#Get file's lines count
length=`wc -l < $file`
echo "File lines count: $length"

#Show file lines
echo "**************"
echo "* File lines *"
echo "**************"
echo ${arr[*]} 

# Bubble sort
for ((i = 0; i < $length; i++)); do
    for ((j = 0; j < $length - i - 1; j++)); do
        if [[ "${arr[j]}" > "${arr[$((j+1))]}" ]]; then
            # swap 
            temp=${arr[j]} 
            arr[$j]=${arr[$((j+1))]}   
            arr[$((j+1))]=$temp 
        fi
    done
done

echo "***************"
echo "* Sorted file *"
echo "***************"
echo ${arr[*]}
rm -rf $file

#Write on file sorted lines
for i in "${arr[@]}"; do
	echo "$i" >> $file
done
