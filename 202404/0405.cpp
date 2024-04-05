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
    vector<int> path;
    int max = 0;
    void dfs(TreeNode *root)
    {
        if(root == nullptr)
            return;
        
        auto iter = std::max_element(path.begin(), path.end());
        auto min_val = std::min_element(path.begin(), path.end());
        if(iter != path.end())
        {
            max = (*iter - root->val) > max ? (*iter - root->val) : max;
        }
        if(min_val != path.end())
        {
            max = (root->val - *min_val) > max ? (root->val - *min_val) : max;
        }


        path.push_back(root->val);
        if(root->left)
            dfs(root->left);
        if(root->right)
            dfs(root->right);
        path.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return max;
    }
};   