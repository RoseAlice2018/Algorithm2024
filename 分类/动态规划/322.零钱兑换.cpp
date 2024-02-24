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
    int dp(vector<int>& coins, int amount)
    {
        if(amount == 0) return 0;
        if(amount < 0) return -1;

        int res = INT_MAX;
        for(int coin : coins)
        {
            int subproblem = dp(coins, amount - coin);
            if(subproblem == -1) continue;

            res = min(res, subproblem + 1);
        }

        return res == INT_MAX ? -1 : res;
    }
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins, amount);
    }
};



class Solution {
public:
    vector<int> memo;
    int dp(vector<int>& coins, int amount)
    {
        if(amount == 0) return 0;
        if(amount < 0) return -1;

        if(memo[amount] != INT_MIN) return memo[amount];

        int res = INT_MAX;
        for(int coin : coins)
        {
            int subproblem = dp(coins, amount - coin);
            if(subproblem == -1) continue;

            res = min(res, subproblem + 1);
        }

        memo[amount] = (res == INT_MAX ? -1 : res);
        return memo[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        
        memo = vector<int>(amount + 1, INT_MIN);
        return dp(coins, amount);
    }
};
