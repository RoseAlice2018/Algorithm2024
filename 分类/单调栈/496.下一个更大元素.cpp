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
    unordered_map<int, int> dic; 
    void find_next_bigger_element(vector<int>& nums)
    {
        stack<int> _stack;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            while(!_stack.empty() && _stack.top() < nums[i])
            {
                _stack.pop();
            }
            dic[nums[i]] = _stack.empty() ? -1 : _stack.top();
            _stack.push(nums[i]);
        }
        return;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        find_next_bigger_element(nums2);
        vector<int> ans;
        for(auto iter = nums1.begin(); iter != nums1.end(); iter++)
        {
            ans.push_back(dic[*iter]);
        }
        return ans;
    }
};