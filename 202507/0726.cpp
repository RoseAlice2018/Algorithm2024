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
    int maxProfit(vector<int>& prices) {
        int n = prices.size() - 1;
        int max_value = prices[n];
        int ret = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(max_value - prices[i] > ret)
            {
                ret = max_value - prices[i];
            }
            if(prices[i] > max_value)
                max_value = prices[i];
        }
        return ret;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root ||(root == p || root == q))
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left && right) return root;

        return left ? left : right;    
    }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> layer;
        vector<vector<int>> ret;
        if(!root) return ret;
        layer.push(root);
        int _r = 0;
        while(!layer.empty())
        {
            vector<int> tmp;
            int size = layer.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode *f = layer.front();
                layer.pop();
                tmp.push_back(f->val);
                if(f->left) layer.push(f->left);
                if(f->right) layer.push(f->right);
            }
            if(_r)
                reverse(tmp.begin(), tmp.end());
            _r = !_r;
            ret.push_back(std::move(tmp));
        }
        return ret;      
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *first = head;
        if(!head) return false;
        ListNode *second = head->next;
        while(first&&second)
        {
            if(first == second)
                return true;
            first = first->next;
            if(second->next)
                second = second->next->next;
            else{
                return false;
            }
        }
        return false;
    }
};