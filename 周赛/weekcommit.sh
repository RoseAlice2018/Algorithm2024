#!/bin/bash

# 获取当前日期
current_date=$(date + "%Y-%m-%d")

cd "${current_date}"||exit 

for i in {1..4};do
    file="${i}.cpp"

    # git add 
    git add "${file}"
    # git commit
    git commit "[Algorithm] add  周赛 ${current_date}/${file}"
    # git push
    git push
done