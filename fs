#!/bin/bash
set -o errexit

if [[ -n $1 ]]
then
	echo "Options:"
	echo "# fs open 	- set status to open"
	echo "# fs close	- set status to close"
	echo "# fs status	- show current status"
else
	
	if [ $1 == "open" ]
	then
		fsopen open
	fi
	if [ $1 == "close" ]
	then
		fsopen close
	fi
	if [ $1 == "status" ]
	then
		fsopen
	fi
fi
