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


// 
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();

        int i = 0, j = 0;
        while(i < m || j < n)
        {
            long val1 = 0;
            for(; i < m; i++)
            {
                if(version1[i] == '.')
                {
                    i++;
                    break;
                }
                val1 = val1 * 10 + version1[i] - '0';
            }
            long val2 = 0;
            for(;j < n; j++)
            {
                if(version2[j] == '.')
                {
                    j++;
                    break;
                }
                val2 = val2 * 10 + version2[j] - '0';
            }
            cout<<val1<<" "<<val2<<endl;
            if(val1 > val2) return 1;
            else if (val1 < val2) return -1;
        }
        return 0;
    }
};




class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; i++)
            dp[i][0] = 0;
        for(int j = 0; j <= n; j++)
            dp[0][j] = 0;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1] );
                }
            }
        }
        return dp[m][n];
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ret;
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        while(left<=right && top<=bottom)
        {
            for(int i = left; i <= right; i++)
            {
                ret.push_back(matrix[top][i]);
            }

            for(int i = top + 1; i <= bottom; i++)
            {
                ret.push_back(matrix[i][right]);
            }

            if(left < right && top < bottom)
            {
            for(int i = right - 1; i >= left; i--)
            {
                ret.push_back(matrix[bottom][i]);
            }

            for(int i = bottom - 1; i > top; i--)
            {
                ret.push_back(matrix[i][left]);
            }
            }

            left++;
            right--;
            top++;
            bottom--;
        }
        return ret;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int ret = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ret = max(ret, dp[i]);
                }
            }
        }
        return ret;
    }
};
















