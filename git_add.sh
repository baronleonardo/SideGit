#!/bin/bash

# get the path from the file_name
#path=`echo "$1" | sed 's/\(.*\)\/.*/\1/'`

cd "$1"

if [ "$2" == "all" ]
    then git add -v *
    else git add -v "$2"
fi
