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
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int i = 0;
        stack<int> stk;
        while(i < n)
        {
            if(stk.empty())
            {
                return false;
            }
            else if(preorder[i] == ',')
            {
                i++;
            }
            else if(preorder[i] == '#')
            {
                stk.top() -= 1;
                if(stk.top() == 0)
                {
                    stk.pop();
                }
                i++;
            }
            else 
            {
                while(i < n && preorder[i] !=',')
                {
                    i++;
                }
                stk.top() -= 1;
                if(stk.top() == 0)
                {
                    stk.pop();
                }
                stk.push(2);
            }
        }
        return stk.empty();
    }
};


class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int i = 0;
        int slots = 1;

        while( i < n)
        {
            if(slots == 0)
            {
                return false;
            }
            else if(preorder[i] == ',')
            {
                i++;
            }
            else if(preorder[i] == '#')
            {
                slots--;
                i++;
            }
            else {
                // read a number
                while( i < n && preorder[i] != ',')
                {
                    i++;
                }
                slots++;
            }
        }
        return slots == 0;
    }
};


class Solution {
public:
    string finalString(string s) {
        string res;
        for(char t : s)
        {
            if(t == 'i')
                std::reverse(res.begin(), res.end());
            else 
                res.push_back(t);
        }
        return res;
    }
};