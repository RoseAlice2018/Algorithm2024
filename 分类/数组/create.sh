#!/bin/bash

#获取当前日期
current_date=$(date +"%m%d" | awk '{print substr($0,1,4)}')
echo "${current_date}"
current_year=$(date +"%Y%m" | awk '{print substr($0,1,6)}')
echo "${current_year}!"

#创建文件�?
#mkdir -p "${current_year}"

#检查是否有参数输入
if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

filename=$1

#创建cpp文件�?
cpp_file="${filename}.cpp"

#在cpp文件中添加内�?

echo "#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode *next):val(x), next(next){}
};" > "${cpp_file}"

#移动文件到文件夹�?
#if [ -e "${current_year}/${cpp_file}" ]; then  
#    echo "File ${cpp_file} already exists in the target folder. Skipping move."
#else
    #移动文件
#    mv "${cpp_file}" "${current_year}"/
#    echo "Moved ${cpp_file} to ${current_year} successfully!"
#fi

#输出创建成功的消�?
#echo "Created ${cpp_file} successfully!"