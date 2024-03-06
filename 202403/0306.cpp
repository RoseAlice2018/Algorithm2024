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
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < 31; i++)
        {
            int cnt = 0;
            for(int num : nums){
                if((num >> i) & 1){
                    ++cnt;
                }
            }

            if(cnt >= k)
                ans |= 1 << i;
        }
        return ans;
    }
};