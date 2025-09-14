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
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        if(m == 0 || n == 0) return n+m;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 0; i <= m; i++)
        {
            dp[i][0] = i;
        }

        for(int i = 0; i <= n; i++)
        {
            dp[0][i] = i;
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j<= n; j++)
            {
                int left = dp[i-1][j] + 1;
                int right = dp[i][j-1] + 1;
                int replace = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1]) replace++;

                dp[i][j] = min(left, min(right, replace));
            }
        }

        return dp[m][n];
    }
};