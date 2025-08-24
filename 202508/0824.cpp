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
    bool deepsearch(TreeNode *root, int targetSum)
    {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(targetSum - root->val == 0)
                return true;
            else{
                return false;
            }
        }
        bool left = false, right = false;
        if(root->left)
        {
            left = deepsearch(root->left, targetSum - root->val);
        }
        if(root->right)
        {
            right = deepsearch(root->right, targetSum - root->val);
        }
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return deepsearch(root, targetSum);
    }
};