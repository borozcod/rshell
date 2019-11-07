#!/bin/sh

../rshell "echo multiple || ls -a ; git status && echo bye"
