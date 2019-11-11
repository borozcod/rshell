#!/bin/sh

clear
BASEDIR=$(dirname $0)
COMMAND="echo comment #ls"

echo "COMMAND TO RUN: ${COMMAND}"

$BASEDIR/../rshell "${COMMAND}"
