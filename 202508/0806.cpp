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