#!/bin/bash
set -o errexit

if [[ -z $1 ]]
then
	echo "Options:"
	echo "# fs open 	- set status to open"
	echo "# fs close	- set status to close"
	echo "# fs status	- show current status"
	echo "# fs mpd		- show mpd stats"
	echo "# fs mute		- mute fs"
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
	if [ $1 == "mpd" ]
	then
		mpc
	fi
	if [ $1 == "mute" ]
	then
		amixer -q set Master toggle
	fi
fi
