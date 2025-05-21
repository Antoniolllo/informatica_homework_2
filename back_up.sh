#!/bin/bash

saves="game_saves"
backups="game_backups"

while true
do
	for file in "$saves"/*
    		do
    		# Если файл изменялся в последнюю минуту
    			if [ -f "$file" ]  # Если это файл (а не папка)
			then
    		# Если файл изменялся в последнюю минуту
    				if [ $(stat -c %Y "$file") -gt $(date +%s --date="1 min ago") ]
    					then
        					cp "$file" "$backups"
    				fi
			fi
	done
    sleep 60
done &

echo "Бэкап запущен в фоне!"
