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
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){};
};

class Solution {
public:
    pair<TreeNode*, int> findTarget(TreeNode* root, int target, int depth)
    {
        pair<TreeNode*, int> res;
        res.first = nullptr;
        if(root == nullptr)
            return res;
        //left
        if(root->left != nullptr && root->left->val == target)
        {
            //find it
            res.first = root;
            res.second = depth;
            return res;
        }
        //right
        if(root->right != nullptr && root->right->val == target)
        {
            //find it
            res.first = root;
            res.second = depth;
            return res;
        }

        //dfs
        if(root->left != nullptr)
        {
            pair<TreeNode*, int> left;
            left = findTarget(root->left, target, depth + 1);
            if(left.first != nullptr)
            {
                res = left;
            }
        }

        if(root->right != nullptr)
        {
            pair<TreeNode*, int> right;
            right = findTarget(root->right, target, depth + 1);
            if(right.first != nullptr)
            {
                res = right;
            }
        }

        return res;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        //x, y
        pair<TreeNode*, int> left = findTarget(root, x, 0);
        pair<TreeNode*, int> right = findTarget(root, y, 0);
        if((left.first != nullptr && right.first != nullptr)&&(left.first != right.first)&&(left.second == right.second))
        {
            return true;            
        }
        return false;
    }
};