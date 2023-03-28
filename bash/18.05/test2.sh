#! /bin/bash 

if [ -d "/home/$USER/Desktop" ] 
    then
        myDir=`find /home/$USER/Desktop -name "*.txt"`
	myDir=`grep -wl 'test' $myDir`
	echo $myDir
	if [ "$myDir" == "" ]
            then echo "Please make file, were is word 'test'. File not exist!))";
	fi
        filenames=""
        
        for i in "${myDir[@]}"
        do
            filenames="$filenames $i"
        done
        tar cfz foo.tar.gzip  $filenames &> out && echo "Your new zip file is foo.tar.gzip, enjoy)"

else
    echo "Please make directorry for your user /home/<user-name>/Desktop)"
fi



