#! /bin/bash

echo -n "Enter filename(path): "
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
    echo "Empty directory!"
    exit;
fi

echo -n "Enter word: "
read word

count=`cd $dir && ls -d $word* | wc -l`
echo $count
if [ $count -lt 6 ]; then
    cd $dir && ls -d $word*
else
    cd $dir && ls -d $word* | head -n 3 && ls -d $word* | tail -n 3
fi
