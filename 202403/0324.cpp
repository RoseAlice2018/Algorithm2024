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
    int coinChange(vector<int>& coins, int amount) {
       int Max = amount + 1;
       vector<int> dp(amount + 1, Max);
       dp[0] = 0;
       for(int i = 1; i <= amount; ++i)
       {
        for(int j = 0; j < (int)coins.size(); ++j)
        {
            if(coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
       }
       return dp[amount] > amount ? -1 : dp[amount];

    } 
};


