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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int n = matrix[0].size();
        int m = matrix.size();
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        while(left<=right && top<= bottom)
        {
            for(int i = left; i <= right; i++)
            {
                ret.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i<= bottom; i++)
            {
                ret.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom)
            {
                for(int i = right; i>=left; i--)
                {
                    ret.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if(left <= right)
            {
                for(int i =  bottom; i >= top; i--)
                {
                    ret.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return ret;
    }
};




class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size() - 1;
        int n = num2.size() - 1;
        int carry = 0;
        string ans;
        while(m >= 0 && n >= 0)
        {
            int number1 = num1[m] - '0';
            int number2 = num2[n] - '0';
            int add = number1 + number2 + carry;
            int tmp = add % 10;
            ans.push_back(tmp + '0');
            carry = (add < 10) ? 0 : 1;
            m--;
            n--;
        }

        while(m>=0)
        {
            int num = num1[m] - '0' + carry;
            int tmp = num % 10;
            ans.push_back(tmp + '0');
            carry = (num < 10) ? 0 : 1;
            m--;
        }
        while(n>=0)
        {
            int num = num2[n] - '0' + carry;
            int tmp = num % 10;
            ans.push_back(tmp + '0');
            carry = (num < 10) ? 0 : 1;
            n--;
        }
        if(carry)
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};