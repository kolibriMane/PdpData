#! /bin/bash

ip=`hostname -I | awk -F"." '{print $1"."$2"."$3"."}'`
ip+="0/24"
#ip="${ip:5}"
echo "Your network address is: $ip"

echo  "Get ips for $ip network ->"
arr=`nmap -sP $ip | grep -E -o "([0-9]{1,3}[\.]){3}[0-9]{1,3}"`
echo ${arr[*]}
