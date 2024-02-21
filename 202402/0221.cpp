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
class Solution {
public:
    TreeNode *helper(vector<int>& inorder, int left_in, int right_in, 
        vector<int>& postorder, int left_post, int right_post)
    {
        if(left_in > right_in)return nullptr;
        if(left_post > right_post)return nullptr;

        TreeNode *root = new TreeNode(postorder[right_post]);

        auto iter = find(inorder.begin(), inorder.end(), root->val);
        if(iter == inorder.end()) return root;
        int idx = std::distance(inorder.begin(), iter);
        
        int left_size = idx - left_in;
        // left tree
        root->left = helper(inorder, left_in, idx - 1, postorder, left_post, left_post + left_size);
        // right tree
        root->right = helper(inorder, idx + 1, right_in, postorder, left_post + left_size + 1, right_post - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};