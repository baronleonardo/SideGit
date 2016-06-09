#!/bin/bash

# get the path from the file_name
path=`echo "$1" | sed 's/\(.*\)\/.*/\1/'`

cd $path
git add -v "$1"
