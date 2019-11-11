#!/bin/sh

BASEDIR=$(dirname $0)
$BASEDIR/../rshell "echo multiple || ls -a ; cat some_file.txt && echo bye"
