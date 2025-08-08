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
    vector<vector<int>> ret;
    void backtrace(vector<int> &candidates, int target, int idx, vector<int> &path)
    {
        if(target == 0)
        {
            ret.push_back(path);
            return;
        }
        else if(target < 0)
        {
            return;
        }
        else if(idx >= candidates.size())
        {
            return;
        }
        // 1 choose
        path.push_back(candidates[idx]);
        backtrace(candidates, target - candidates[idx], idx, path);
        path.pop_back();
        // 2 don't choose
        backtrace(candidates, target, idx + 1, path);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtrace(candidates, target, 0, path);
        return ret;
    }
};

class Solution {
public:
    string decodeString(string s) {
        stack<char> _stack;
        for(auto c : s)
        {
            if(c == ']')
            {
                string tmp;
                while(_stack.top() != '[')
                {
                    tmp.push_back(_stack.top());
                    _stack.pop();
                }
                _stack.pop();
                int num = 0;
                string num_s;
                while(!_stack.empty() && isdigit(_stack.top()))
                {
                    num_s.push_back(_stack.top());
                    _stack.pop();
                }
                for(int i = num_s.size() - 1; i >= 0; i--)
                {
                    num = num * 10 + num_s[i] - '0';
                }
                num = (num == 0) ? 1 : num;
                cout<<num<<endl;
                for(int i = 0; i < num; i++)
                {
                    for(int j = tmp.size() - 1; j >= 0; j--)
                        _stack.push(tmp[j]);
                }
            }
            else{
                _stack.push(c);
            }
        }
        string ret;
        while(!_stack.empty())
        {
            ret.push_back(_stack.top());
            _stack.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};