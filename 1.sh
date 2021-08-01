#!/bin/sh
###
# @Author       : Mr.Wang
# @Date         : 2021-07-02 00:04:25
# @FilePath     : /1.sh
# @Description  : message
###
# Put  line  numbers  on  all  lines  of  a  file
if [ $# -ne 1 ]; then
    echo "Usage: $0  filename " >&2
    exit 1
fi
count=1                      # Initialize count
cat $1 | while read line; do # Input is coming from file on command line
    echo $count $line
    count=$(expr $count + 1)
done >tmp$$ # Output is going to a temporary file
mv tmp$$ $1
