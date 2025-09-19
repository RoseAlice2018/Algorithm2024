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
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int num_size = nums.size();
        int ans = INT_MAX;
        int sum = 0;

        int begin = 0, end = 0;
        while(end < num_size)
        {
            sum += nums[end];
            while(sum >= target)
            {
                ans = min(ans, end-begin+1);
                sum -= nums[begin];
                begin++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};