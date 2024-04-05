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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int first = 0; first < nums.size() ; first++)
        {
            if(first > 0 && nums[first] == nums[first - 1])
                continue;
            int target = -nums[first];
            int second = first + 1;
            int third  = nums.size() - 1; // 注意体会这里third放在这里而不是第二层循环的原因
            for(second = first + 1; second < nums.size() - 1; second++)
            {
                if(second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                
                while(second < third && nums[second] + nums[third] > target)
                    third--;
                
                if(second >= third)
                    break;
                
                if(nums[second] + nums[third] == target)
                {
                    ret.push_back({nums[first], nums[second], nums[third]});
                }
            }

        }

        return ret;
    }
};