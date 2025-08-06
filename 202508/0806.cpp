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

