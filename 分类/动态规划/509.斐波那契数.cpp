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
    int fib(int n) {
        if(n == 0 || n == 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};


class Solution {
public:
    int fib(int n) {
        int memo[n + 1];
        memset(memo, 0, sizeof(memo));
        return dp(memo, n);
    }

    int dp(int memo[], int n)
    {
        if(n == 0 || n == 1) return n;

        if(memo[n] != 0) return memo[n];
        memo[n] = dp(memo, n - 1) + dp(memo, n - 2);
        return memo[n];
    }
};