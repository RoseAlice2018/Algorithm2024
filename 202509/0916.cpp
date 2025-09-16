#include<vector>
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
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ret = 0;
        for(int i = 0; i < m; i++)
        {
            if(matrix[i][0] == '1')
            {   dp[i][0] = 1; ret = 1;}
        }

        for(int i = 0; i < n; i++)
        {
            if(matrix[0][i] == '1')
            {    dp[0][i] = 1;ret = 1;}
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j] == '0')
                    continue;
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                ret = max(ret, dp[i][j]);
            }
        }
        return ret*ret;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> num_set(nums.begin(), nums.end()); // 一次性初始化哈希集合
        int longest_streak = 0;

        for (int num : num_set) { // 遍历哈希集合，避免原数组重复值的影响
            // 只有当num是序列起点时（即num-1不存在），才进入内部循环统计
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_streak = 1;

                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num++;
                    current_streak++;
                }
                longest_streak = max(longest_streak, current_streak);
            }
        }
        return longest_streak;
    }
};