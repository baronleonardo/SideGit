#!/bin/bash

files=`ls | cut -d. -f1`

for file in $files
do
	inkscape -z -e $file.png -w 48 -h 48 $file.svg
done