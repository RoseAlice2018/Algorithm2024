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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> min_stack;
        if(temperatures.size() == 1) return {0};
        int temperatures_size =  temperatures.size();
        vector<int> ret(temperatures_size, 0);
        for(int i = 0; i < temperatures_size; i++)
        {
            if(min_stack.empty())
            {
                min_stack.push(i);
                continue;
            }
            else{
                int tmp = temperatures[min_stack.top()];
                while(tmp < temperatures[i])
                {
                    ret[min_stack.top()] = i - min_stack.top();
                    min_stack.pop();
                    if(min_stack.empty()) break;
                    tmp = temperatures[min_stack.top()];
                }
                min_stack.push(i);
            }
        }
        return ret;
    }
};