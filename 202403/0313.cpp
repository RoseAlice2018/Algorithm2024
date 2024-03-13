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
    string maximumOddBinaryNumber(string s) {
        int left = 0, right = s.size() - 1;
        if(left == right) return s;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
            {
                //try to set right
                if(s[right] == '0' && right == s.size() - 1)
                {
                    s[right] = '1';
                    right--;
                }
                else 
                {
                    s[left] = '1';
                    left++;
                    s[i] ='0';
                }
            }
        }
        return s;
    }
};

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = count(s.begin(), s.end(), '1');
        return string(cnt - 1, '1') + string(s.length() - cnt, '0') + '1';
    }
};

