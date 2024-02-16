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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        if(root == nullptr)
            return ret;
        
        queue<TreeNode*> _level;
        _level.push(root);

        bool _direction = 0; // 0 l->r 1 r->l 
        while(!_level.empty())
        {
            vector<int> tmp;
            int size = _level.size();

            for(int i = 0; i < size; i++)
            {
                TreeNode *_front = _level.front();
                _level.pop();
                
                if(_front->left != nullptr) _level.push(_front->left);
                if(_front->right != nullptr) _level.push(_front->right);

                tmp.push_back(_front->val);
            }
            if(_direction)
            {
                reverse(tmp.begin(), tmp.end());
            }

            ret.push_back(tmp);

            _direction = !_direction;
        }

        return ret;
    }
};