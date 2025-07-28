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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *curA = headA;
        ListNode *curB = headB;
        while(curA != curB)
        {
            curA = (curA == nullptr) ? headB : curA->next;
            curB = (curB == nullptr) ? headA : curB->next;
        }
        return curA;
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        std::vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int maxSum = INT_MIN;
    
    int maxGain(TreeNode *node)
    {
        if(node == nullptr)
            return 0;
        
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        int priceNewPath = node->val + leftGain + rightGain;
        maxSum = max(priceNewPath, maxSum);

        return node->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};