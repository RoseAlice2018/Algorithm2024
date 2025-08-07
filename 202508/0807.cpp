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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* trainingPlan(ListNode* head, int cnt) {
        if(head == nullptr) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while(cnt--)
        {
            fast = fast->next;
        }
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

class Solution {
public:
    unordered_map<int, int> dict;
    TreeNode * _buildTree(vector<int> &preorder, vector<int> &inorder, int pre_index, int left, int right)
    {
        if(left > right) return nullptr;
        TreeNode * root = new TreeNode(preorder[pre_index]);
        int inorder_index = dict[preorder[pre_index]];
        int left_size = inorder_index - left;
        if(left_size)
            root->left = _buildTree(preorder, inorder, pre_index + 1, left, inorder_index - 1);
        root->right = _buildTree(preorder, inorder, pre_index + left_size + 1, inorder_index + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size();i++)
            dict[inorder[i]] = i;
        return _buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};