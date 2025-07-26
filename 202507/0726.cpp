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
    int maxProfit(vector<int>& prices) {
        int n = prices.size() - 1;
        int max_value = prices[n];
        int ret = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(max_value - prices[i] > ret)
            {
                ret = max_value - prices[i];
            }
            if(prices[i] > max_value)
                max_value = prices[i];
        }
        return ret;
    }
};