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
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;   
        unordered_set<char> window;
        int res = 0;
        while(right < s.size())
        {
            if(window.find(s[right]) == window.end())
            {
                window.insert(s[right]);
                right++;
                res = max(res, right - left);
            }
            else
            {
                window.erase(s[left]);
                left++;
            }
        }
        return res;
    }
};