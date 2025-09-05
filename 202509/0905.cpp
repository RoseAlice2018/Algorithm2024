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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int num1 = m - 1, num2 = n - 1;
        for(int i = m + n - 1; i >= 0; i--)
        {
            if(num1 < 0)
            {
                nums1[i] = nums2[num2];
                num2--;
                continue;
            }
            if(num2 < 0)
            {
                break;
            }
            if(nums1[num1] < nums2[num2])
            {
                nums1[i] = nums2[num2];
                num2--;
            }
            else{
                nums1[i] = nums1[num1];
                num1--;
            }
        }    
        return;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == NULL) return root;
       if(root == p || root == q) return root;
       TreeNode *left = lowestCommonAncestor(root->left, p, q);
       TreeNode *right = lowestCommonAncestor(root->right, p, q);
       if(left && right) return root;
       return left ? left : right; 
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = 0;
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        ans = dp[0];
        for(int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            if(dp[i] > ans)
            {ans = dp[i];}
        }
        return ans;
    }
};