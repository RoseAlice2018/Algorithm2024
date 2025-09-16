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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode *root)
    {
        if(root == nullptr) return 0;

        int left_height = height(root->left);
        int right_height = height(root->right);

        if(abs(left_height - right_height) > 1 || left_height == -1|| right_height == -1) return -1;
        return max(left_height, right_height) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};

class Solution {
public:
    void backtrace(vector<int>& candidates, int index, int target, vector<vector<int>>& ret, vector<int>& path)
    {
        if(index >= candidates.size())
            return;
        if(target == 0)
        {
            ret.push_back(path);
            return;
        }

        // skip
        backtrace(candidates, index+1, target, ret, path);

        // chooose
        if(target >= candidates[index])
        {
            path.push_back(candidates[index]);
            backtrace(candidates, index, target - candidates[index], ret, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> path;
        backtrace(candidates, 0, target, ret, path);
        return ret;
    }
};


class MinStack {
public:
    stack<int> min_stack;
    stack<int> normal;
    MinStack() {
    }
    
    void push(int val) {
        normal.push(val);
        if(min_stack.empty())
        {
            min_stack.push(val);
            return;
        }
        if(min_stack.top() > val)
        {
            min_stack.push(val);
        }
        else{
            min_stack.push(min_stack.top());
        }
    }
    
    void pop() {
        if(normal.empty()) return;
        normal.pop();
        min_stack.pop();
    }
    
    int top() {
        return normal.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


 class Solution {
public:
    int left_index;
    int right_index;
    void binarysearch(vector<int>& nums, int target, int left, int right)
    {
        if(left > right) return ;
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            // find it
            if(mid < left_index) left_index = mid;
            if(mid > right_index) right_index = mid;
            binarysearch(nums, target, left, mid - 1);
            binarysearch(nums, target, mid + 1, right);
        }
        else if(nums[mid] > target)
        {
            binarysearch(nums, target, left, mid - 1);
        }
        else {
            binarysearch(nums, target, mid + 1, right);
        }
        return;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        left_index = INT_MAX;
        right_index = INT_MIN;
        binarysearch(nums, target, 0, nums.size() - 1);
        if(left_index == INT_MAX) return {-1, -1};
        return {left_index, right_index};
    }
};

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int row, col, idx;
        do{
            row = rand7();
            col = rand7();
            idx = (row - 1) * 7 + col;
        }while(idx > 40);

        return 1 + (idx - 1)%10;
    }
};