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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;
        ListNode *pre = new ListNode(0);
        ListNode *head = pre;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                pre->next = list1;
                list1 = list1->next;
            }
            else 
            {
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }
        while(list1)
        {
            pre->next = list1;
            list1 = list1->next;
            pre = pre->next;
        }
        while(list2)
        {
            pre->next = list2;
            list2 = list2->next;
            pre = pre->next;
        }
        return head->next;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1)
        {
            return s;
        }
        else if(n == 2)
        {
            return (s[0] == s[1]) ? s : string(1, s[0]);
        }
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        int max_len = 1;
        int ans_l = 0, ans_r = 0;

        for(int i = 0 ; i < n; i++)
            dp[i][i] = 1;
        
        for(int Len = 2; Len <= n; Len++)
        {
            for(int i = 0; i < n; i++)
            {
                int j = i + Len - 1;
                if(j >= n)
                    break;
                if(s[i] == s[j])
                {
                    if(j - i < 3)
                        dp[i][j] = 1;
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                    if(dp[i][j] && Len > max_len)
                    {
                        ans_l = i;
                        ans_r = j;
                        max_len = Len;
                    } 
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        std::cout<<max_len<<"  "<<ans_l<<endl;
        return s.substr(ans_l, max_len);
    }
};



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> index;
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(index.find(target - nums[i]) != index.end())
            {
                ans.push_back(index[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            index[nums[i]] = i;
        }
        return ans;
    }
};