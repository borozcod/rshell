#!/bin/sh

BASEDIR=$(dirname $0)
COMMAND="echo hi || ls -a && exit ; echo last"

clear

echo "COMMAND TO RUN: ${COMMAND}"

$BASEDIR/../rshell "${COMMAND}"
