#!/bin/bash

#获取当前日期
current_date=$(date +"%m%d" | awk '{print substr($0,1,4)}')
echo "${current_date}"
current_year=$(date +"%Y%m" | awk '{print substr($0,1,6)}')
echo "${current_year}!"

#创建文件夹
mkdir -p "${current_year}"

#创建cpp文件名
cpp_file="${current_date}.cpp"

#在cpp文件中添加内容

echo "#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;" > "${cpp_file}"

#移动文件到文件夹里
if [ -e "${current_year}/${cpp_file}" ]; then  
    echo "File ${cpp_file} already exists in the target folder. Skipping move."
else
    #移动文件
    mv "${cpp_file}" "${current_year}"/
    echo "Moved ${cpp_file} to ${current_year} successfully!"
fi

#输出创建成功的消息
echo "Created ${cpp_file} successfully!"