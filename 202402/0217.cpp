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


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;
        
        queue<Node*> _level;
        _level.push(root);

        while(!_level.empty())
        {
            int size = _level.size();

            vector<int> tmp;
            for(int idx = 0; idx < size; idx++)
            {
                Node* top = _level.front();
                _level.pop();

                // push all nodes
                for(int i = 0; i < top->children.size(); i++)
                {
                    _level.push(top->children[i]);
                }

                //push val
                tmp.push_back(top->val);
            }

            ret.push_back(tmp);
        }

        return ret;
    }
};