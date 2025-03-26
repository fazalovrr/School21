#!/bin/bash

LOG_FILE=$1

if [ -z "$LOG_FILE" ]; then
      echo "Ошибка: Не указан путь до файла лога."
else
    if [ ! -f "$LOG_FILE" ]; then
          echo "Ошибка: Файл '$LOG_FILE' не найден."#обработка отстутствующих файлов
    else
        if [[ ! -z "$(awk 'NR==1 {print $8; exit}' $LOG_FILE)" ]]; then #обработка некорректных файлов
        
            total_entries=0
            unique_files=()
            hash_changes=0
            unique_hash=()

            while IFS= read -r line; do
                ((total_entries++))
                
                IFS=' - ' read -r -a parts <<< "$line"
                file_name=${parts[0]}
                file_hash=${parts[6]}

                if [[ ! " ${unique_files[@]} " =~ " ${file_name} " ]]; then
                    unique_files+=("$file_name")
                fi
              
                if [[ ! " ${unique_hash[@]} " =~ " ${file_hash} " ]]; then
                    unique_hash+=("$file_hash")
                fi

            done < "$LOG_FILE"

            let "hash_changes=${#unique_hash[@]}-${#unique_files[@]}"

            echo "$total_entries ${#unique_files[@]} $hash_changes "
        else
            echo "Ошибка: Файл '$LOG_FILE' некорректный."#обработка отстутствующих файлов
        fi
    fi
fi


