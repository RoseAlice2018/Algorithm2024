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
class FindElements {
public:
    FindElements(TreeNode* root) {
        recover(root, 0);
        _root = root;
    }
    
    bool find(int target) {
        return _find(_root, target);
    }

    bool _find(TreeNode *root, int target)
    {
        if(root->val == target)
            return true;
        if(root->left != nullptr && root->right != nullptr)
        {
            return _find(root->left, target) | _find(root->right, target);
        }
        else if(root->right != nullptr)
            return _find(root->right, target);
        else if(root->left != nullptr)
            return _find(root->left, target);
        return false;
    }

    void recover(TreeNode *root, int val)
    {
        root->val = val;
        if(root->left != NULL)
            recover(root->left, 2 * val + 1);
        if(root->right != NULL)
            recover(root->right, 2 * val + 2);
        return;
    }
    TreeNode *_root;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */