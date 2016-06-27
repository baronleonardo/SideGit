#!/bin/bash


is_repo()
{
    cd "$1"
    git status &> /dev/null;

    if [ $? -ne 0 ]
#        then >&2 echo "Not a GIT repository."
        then return -1
        else return 0
    fi
}

is_repo $1
