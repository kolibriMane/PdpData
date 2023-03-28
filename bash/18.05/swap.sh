#! /bin/bash

#If files exist, then continue
#if files not exist show comment and end the program
FILE1=/home/$USER/Desktop/a.txt
if test -f "$FILE1"; then
    echo "$FILE1 exist => continue...";
    else echo "Please, make file with name $FILE1 !"; exit;
fi

FILE2=/home/$USER/Desktop/b.txt
if [ -f "$FILE2" ]; then
    echo "$FILE2 exist => continue..."
    else echo "Please, make file with name $FILE2 !"; exit;
fi

#Get line counts
lines1=`wc -l < $FILE1`
lines2=`wc -l < $FILE2`

if [[ $lines2 -gt $lines1 ]]; then
    temp=$FILE1
    FILE1=$FILE2
    FILE2=$temp
fi

lines1=`wc -l < $FILE1`
lines2=`wc -l < $FILE2`

swapLines1=$(cat $FILE1 | head -$lines2)
swapLines2=$(cat $FILE2 | head -$lines2)
lineNum=$(echo $(( $lines1 - $lines2 )))
moreLines=$(cat $FILE1 | tail -$lineNum) 

for i in "${swapLines1[@]}"; do
    echo "$i" > $FILE2
done

for i in "${swapLines2[@]}"; do
    echo "$i" > $FILE1
done

for i in "${moreLines[@]}"; do
    echo "$i" >> $FILE1
done
