#!/bin/bash

#获取当前日期
current_date=$(date +"%m%d" | awk '{print substr($0,1,4)}')
echo "${current_date}"
current_year=$(date +"%Y%m" | awk '{print substr($0,1,6)}')
echo "${current_year}!"

#创建cpp文件名
cpp_file="${current_date}.cpp"

#file to add
file_to_add="${current_year}/${cpp_file}"

# git add
git add "${file_to_add}"

# git commit
git commit -m "[Algorithm] add ${current_date}/${curent_year}"

# git push
git push