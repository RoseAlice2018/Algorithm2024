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
    long long minimumSteps(string s) {
        long long ans = 0;
        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                sum++;
            }
            else 
            {
                ans+=sum;
            }
        }
        return ans;
    }
};