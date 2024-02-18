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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 解法1： 层序遍历
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        queue<Node*> _level;
        _level.push(root);
        
        while(!_level.empty())
        {
            int size = _level.size();
            
            Node* before = _level.front();
            _level.pop();
            
            if(before->left) _level.push(before->left);
            if(before->right) _level.push(before->right);

            for(int i = 1; i < size; i++)
            {
                Node *cur = _level.front();
                _level.pop();
                before->next = cur;
                before = cur;
                if(before->left) _level.push(before->left);
                if(before->right) _level.push(before->right);
            }
        }

        return root;
    }
};


//解法2： 迭代
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        Node *leftmost = root;

        while(leftmost->left != nullptr)
        {
            Node *head = leftmost;
            while(head != nullptr)
            {
                //conection1
                head->left->next = head->right;

                //conection2
                if(head->next != nullptr)
                    head->right->next = head->next->left;

                head = head->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};

//解法3：

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        traverse(root->left, root->right);

        return root;
    }


    void traverse(Node *left, Node *right)
    {
        if(left == nullptr || left->right == nullptr)
            return ;
        
        left->next = right;

        traverse(left->left, left->right);
        traverse(right->left, right->right);
        traverse(left->right, right->left);
        return;
    }
};