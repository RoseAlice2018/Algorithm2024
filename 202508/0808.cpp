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