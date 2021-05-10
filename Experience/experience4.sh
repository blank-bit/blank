#!/bin/sh
###
# @Author       : Mr.Wang
# @Date         : 2021-05-10 14:37:55
# @FilePath     : /Experience/experience4.sh
# @Description  : message
###
clear
echo 'begin test'
echo "Input the test filename: \c" #\c 不换行
read file

if [ -f $file ]; then
    echo "Current satatus of [$file] is: "
    ls -l $file
else
    echo "Can't find the file [$file]!"
    exit 0
fi

size1=$(ls -l $file | cut -d ' ' -f 5) #-rwxrwxrwx 1 yling yling 36 May 10 14:57 data.txt 第5列为大小
size2=$(ls -l $file | cut -d ' ' -f 5)

count=0
sleeptime=5

for i in $(seq 1 10); do
    size2=$(ls -l $file | cut -d ' ' -f 5)
    if [ $size1 -eq $size2 ]; then
        echo "file's status ..."
    else
        size1=$size2
        echo "file [$file] is changed"
        count=$((count + 1))
    fi

    if [ $count -eq 2 ]; then
        echo "change number is exceed two, test end."
        exit 0
    fi
    sleep $sleeptime
done

echo "test number exceed ten!"
