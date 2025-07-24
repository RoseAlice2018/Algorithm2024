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
    bool isValid(string s) {
       stack<char> _s;
       std::map<char,char> _dict = {
        {'(',')'},
        {'[', ']'},
        {'{','}'}
       };

       for(int i = 0; i < s.size(); i++)
        {
            if(_s.empty())
            {
                _s.push(s[i]);
                continue;
            }
            char top = _s.top();
            if(_dict.find(top) != _dict.end())
            {
                if(s[i] == _dict[top])
                {
                    _s.pop();
                    continue;
                }
            }
            _s.push(s[i]);
       } 
       return _s.empty();
    }
};