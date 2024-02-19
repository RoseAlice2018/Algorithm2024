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
    TreeNode *helper(vector<int>&nums, int i, int j)
    {
        if (i > j)  return nullptr;
        if(i < 0 || i >= nums.size())
            return nullptr;
        
        if(j < 0 || j >=  nums.size())
            return nullptr;
        int max_value = -1;
        int max_idx = -1;
        for(int idx = i; idx <= j; idx++)
        {
            if(nums[idx] > max_value)
            {
                max_value = nums[idx];
                max_idx = idx;
            }
        }
        TreeNode *root = new TreeNode(max_value);
        root->left = helper(nums, i, max_idx-1);
        root->right = helper(nums, max_idx + 1, j);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};