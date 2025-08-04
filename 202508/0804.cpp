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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        ListNode *pre = head;
        ListNode *cur = head;
        while(n--)
        {
            cur = cur->next;
            if(cur == nullptr)
                return head->next;
        }
        while(cur->next != nullptr)
        {
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root == nullptr)
            return ret;

        queue<TreeNode*> layer;
        layer.push(root);
        while(!layer.empty())
        {
            int len = layer.size();
            for(int i = 0; i < len;i++)
            {
                TreeNode *tmp = layer.front();
                if(i == len - 1)
                {
                    ret.push_back(tmp->val);
                }
                if(tmp->left)
                    layer.push(tmp->left);
                if(tmp->right)
                    layer.push(tmp->right);
                layer.pop();
            }
        }

        return ret; 
    }
};