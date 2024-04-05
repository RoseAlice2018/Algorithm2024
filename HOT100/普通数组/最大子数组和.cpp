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


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int ret = nums[0];
        for(int num : nums)
        {
           pre = max(pre + num, num);
           ret = max(ret, pre);
        }
        return ret;
    }
};