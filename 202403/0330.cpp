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
    int minimumAddedCoins(vector<int>& coins, int target) {

    }
};
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        int x = 1;
        int length = coins.size(), index = 0;
        while (x <= target) {
            if (index < length && coins[index] <= x) {
                x += coins[index];
                index++;
            } else {
                x <<= 1;
                ans++;
            }
        }
        return ans;
    }
};


class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int i = 0;
        stack<int> stk;
        while(i < n)
        {
            if(stk.empty())
            {
                return false;
            }
            else if(preorder[i] == ',')
            {
                i++;
            }
            else if(preorder[i] == '#')
            {
                stk.top() -= 1;
                if(stk.top() == 0)
                {
                    stk.pop();
                }
                i++;
            }
            else 
            {
                while(i < n && preorder[i] !=',')
                {
                    i++;
                }
                stk.top() -= 1;
                if(stk.top() == 0)
                {
                    stk.pop();
                }
                stk.push(2);
            }
        }
        return stk.empty();
    }
};


class Solution {
public:
    bool isValidSerialization(string preorder) {

    }
};


