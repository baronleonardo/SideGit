#!/bin/bash

cd "$2"

get_branches()
{
    git for-each-ref --format='%(refname:short)'
}

get_current_branch()
{
    git branch | cut -d' ' -f2
}

set_current_branch()
{
    git checkout $2
}

# this is the part that help me call functions from outside the script
$@
