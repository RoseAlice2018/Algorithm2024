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
    int binarysearch(vector<int>& nums, int left, int right)
    {
        if(left > right) return -1;
        int mid = (left + right) / 2;
        
        if(mid == 0 && nums[mid] > nums[mid+1])
            return mid;
        else if(mid == 0)
            return binarysearch(nums, mid + 1, right);
        if(mid == nums.size()-1 && nums[mid] > nums[mid - 1])
            return mid;
        else if(mid == nums.size() - 1)
            return binarysearch(nums, left, mid-1);
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            return mid;
        if(nums[mid-1] <= nums[mid] && nums[mid] <= nums[mid+1])
        {
            return binarysearch(nums, mid+1, right);
        }
        else{
            return binarysearch(nums, left, mid-1);
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int ret = binarysearch(nums, 0, nums.size()-1);
        return ret;
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
    int widthOfBinaryTree(TreeNode* root) {
       if(root == nullptr) return 0;
       queue<TreeNode*> layer;
       layer.push(root);
       int ret = 1;
       while(!layer.empty())
       {
            int len = layer.size();
            int begin_idx = -1, end_idx = -1;
            for(int i = 0; i < len; i++)
            {
                TreeNode *tmp = layer.front();
                layer.pop();
                if(tmp == nullptr) {
                    layer.push(nullptr);
                    layer.push(nullptr);
                    continue;
                }
                if(begin_idx == -1){
                    begin_idx = i;
                    end_idx = i;
                }
                else{
                    end_idx = i;
                }
                layer.push(tmp->left);
                layer.push(tmp->right);
            }
            ret = max(end_idx - begin_idx + 1, ret);
            if(begin_idx == -1){
                break;
            }
       } 
       return ret;
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int index = 1;
        queue<pair<TreeNode*,unsigned long long>> layer;
        layer.push({root, 1});

        unsigned long long ret = 1;
        while(!layer.empty())
        {
            int len = layer.size();
            unsigned long long left_index = -1, right_index = -1;
            for(int i = 0; i < len; i++)
            {
                auto tmp = layer.front();
                layer.pop();
                if(left_index == -1)
                {
                    left_index = tmp.second;
                    right_index = tmp.second;
                }
                else{
                    right_index = tmp.second;
                }
                if(tmp.first->left) layer.push({tmp.first->left, 2 * tmp.second});
                if(tmp.first->right) layer.push({tmp.first->right, 2 * tmp.second + 1});
            }
            ret = max(ret, right_index - left_index + 1);
        }
        return ret;
    }
};








