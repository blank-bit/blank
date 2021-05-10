#!/bin/sh
###
# @Author       : Mr.Wang
# @Date         : 2021-05-10 15:53:21
 # @FilePath     : /Experience/experience5.sh
# @Description  : message
###
if [ $# -ne 1 ]; then
    echo 'Usage:usr_monitor username'
    exit 0
fi

uname=$(who | cut -d ' ' -f 1)

echo $uname

if [ $uname -eq $1 ]
