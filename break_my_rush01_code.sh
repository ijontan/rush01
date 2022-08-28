#!/usr/bin/env bash

PROG_NAME=${PWD}/a.out

echo "3 2 3 1 2 3 1 3 3 2 1 2 1 2 3 2"
printf '\n'
$PROG_NAME "3 2 3 1 2 3 1 3 3 2 1 2 1 2 3 2"
# 1 3 2 4
# 2 4 1 3
# 4 2 3 1
# 3 1 4 2
printf '\n\n'

echo "1 3 2 2 2 1 2 3 1 3 2 2 3 1 2 2"
printf '\n'
$PROG_NAME "1 3 2 2 2 1 2 3 1 3 2 2 3 1 2 2"
# 4 1 3 2
# 2 3 1 4
# 1 2 4 3
# 3 4 2 1
printf '\n\n'

# echo "3 2 1 2 2 3 2 1 3 2 1 3 2 2 4 1"
# printf '\n'
# $PROG_NAME "3 2 1 2 2 3 2 1 3 2 1 3 2 2 4 1"


# printf '\n\n'
