#!/bin/sh

BASEDIR=$(dirname $0)
COMMAND="echo multiple || ls -a ; cat some_file.txt && echo bye || echo bye2 ; echo last"

clear

echo "COMMAND TO RUN: ${COMMAND}"

printf "\nFROM REGULAR EXECUTION\n\n"
eval $COMMAND &> $BASEDIR/output_multiple_commands.txt

cat $BASEDIR/output_multiple_commands.txt
printf "\nFROM RSHELL\n\n"

$BASEDIR/../rshell "${COMMAND}"

printf "\n"
