

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
    void dfs(TreeNode *root, int targetSum, vector<int>& path, vector<vector<int>> &ret)
    {
        if(root == nullptr )
            return;
        if(targetSum == root->val && root->left == nullptr && root->right == nullptr)
        {
            path.push_back(root->val);
            ret.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        dfs(root->left, targetSum-root->val, path, ret);
        dfs(root->right, targetSum-root->val, path, ret);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(root, targetSum, path, ret);
        return ret;
    }
};



class Solution {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });
        if (nums[0] == 0) {
            return "0";
        }
        string ret;
        for (int &x : nums) {
            ret += to_string(x);
        }
        return ret;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = 1;
        int count = 0, pre = 0;

        for(auto& num : nums)
        {
            pre += num;

            if(mp.find(pre - k) != mp.end())
            {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        
        return count;
    }
};





class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        int ret = 0;
        for(int i =0; i < m; i++)
        {
            if(nums1[i] == nums2[0])
            {    dp[i][0] = 1; ret = 1;}
            
        }

        for(int i = 0; i < n; i++)
        {
            if(nums2[i] == nums1[0])
            {
                dp[0][i] = 1;
                ret = 1;
            }
        }

        for(int i = 1; i < m ;i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ret = max(ret, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ret;
    }
};