#!/bin/bash

full_name=$(git rev-parse --show-toplevel)"/"$1

if [[ "$1" == "" || "$2" == "" || "$3" == "" ]]; then
    echo "Неверные параметры. Введите путь до файла (относительно корневой директории репозитория), строку для замены и саму замену (в виде строки)"
fi
if [ -f $full_name ]; then
    if !(grep -q $2 $full_name); then
        echo "Строка не найдена"
    else
        sed -i '' "s/$2/$3/g" $full_name
        echo "$1 - $(stat -f %z $full_name) - $(date -r $full_name +"%Y-%m-%d %H:%M") - $(shasum -a 256 $full_name | awk '{print $1}' ) - sha256" >> files.log
        echo "Замена строки произведена"
    fi
else
    echo "File not found!"
fi
