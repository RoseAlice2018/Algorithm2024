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
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(fast < nums.size())
        {
            if(nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        for(int i = slow; i < nums.size(); i++)
            nums[i] = 0;
    }
};