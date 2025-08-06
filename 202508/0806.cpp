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
    void backtrace(int n, int left, int right, vector<string> &ret, string &path)
    {
        if(n == 0 && (left == right))
        {
            ret.push_back(path);
            return;
        }
        if(n <= 0)
            return;
        if(left < right)
        {
            return;
        }
        // 1 chose left
        path.push_back('(');
        backtrace(n-1, left+1, right, ret, path);
        path.pop_back();

        // 2 chose right
        path.push_back(')');
        backtrace(n-1, left, right + 1, ret, path);
        path.pop_back();
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path;
        backtrace(2*n, 0, 0, ret, path);
        return ret;
    }
};
class Solution {
public:
    void backtrace(int n, int left, int right, vector<string> &ret, string &path, int limit)
    {
        if(n == 0 && (left == right))
        {
            ret.push_back(path);
            return;
        }
        if(n <= 0)
            return;
        if(left < right)
        {
            return;
        }
        if(left < limit)
        {
            // 1 chose left
            path.push_back('(');
            backtrace(n-1, left+1, right, ret, path, limit);
            path.pop_back();
        }
        if(right < limit)
        {
            // 2 chose right
            path.push_back(')');
            backtrace(n-1, left, right + 1, ret, path, limit);
            path.pop_back();
            return;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string path;
        backtrace(2*n, 0, 0, ret, path, n);
        return ret;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1 && l2)
        {
            int tmp = l1->val + l2->val + flag;
            if(tmp >= 10)
            {
                tmp = tmp % 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
            l1->val = tmp;
            cur->next = l1;
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }
        while(l1)
        {
            int tmp = l1->val + flag;
            if(tmp >= 10)
            {
                tmp = tmp % 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
            l1->val = tmp;
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2)
        {
            int tmp = l2->val + flag;
            if(tmp >= 10)
            {
                tmp = tmp % 10;
                flag = 1;
            }
            else{
                flag = 0;
            }
            l2->val = tmp;
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        if(flag)
        {
            ListNode *nn = new ListNode(flag);
            cur->next = nn;
            cur = cur->next;
        }
        return dummy->next;
    }
};


class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int first = 1; 
        int second = 2;
        int third;
        for(int i = 3; i<= n; i++)
        {
            third= first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};
