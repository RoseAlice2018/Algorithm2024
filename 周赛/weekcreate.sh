#!/bin/bash

# 获取当前日期
current_date=$(date + "%Y-%m-%d")

#创建以当前日期命名的文件夹

mkdir "${current_date}"
cd "${current_date}"||exit 


for i in {1..4};do
    touch"${i}.cpp"
    echo "#include<vector>
#include<stack>
#include<queue>
using namespace std;" > "${i}.cpp"
done